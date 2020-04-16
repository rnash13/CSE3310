//
// chat_client.cpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include "asio.hpp"
#include "chat_message.hpp"
#include "json.hpp"

using asio::ip::tcp;

typedef std::deque<chat_message> chat_message_queue;

class chat_client
{
    public:
        chat_client(asio::io_context& io_context,
                const tcp::resolver::results_type& endpoints)
            : io_context_(io_context),
            socket_(io_context)
    {
        do_connect(endpoints);
    }

        // CSE3310 (client) message is sent to the chat server.
        void write(const chat_message& msg)
        {
            asio::post(io_context_,
                    [this, msg]()
                    {
                    bool write_in_progress = !write_msgs_.empty();
                    write_msgs_.push_back(msg);
                    if (!write_in_progress)
                    {
                    do_write();
                    }
                    });
        }

        void close()
        {
            asio::post(io_context_, [this]() { socket_.close(); });
        }

    private:
        void do_connect(const tcp::resolver::results_type& endpoints)
        {
            // CSE3310 (client) connection is established with the server
            asio::async_connect(socket_, endpoints,
                    [this](std::error_code ec, tcp::endpoint)
                    {
                    if (!ec)
                    {
                    do_read_header();
                    }
                    });
        }

        void do_read_header()
        {
            asio::async_read(socket_,
                    asio::buffer(read_msg_.data(), chat_message::header_length),
                    [this](std::error_code ec, std::size_t /*length*/)
                    {
                    if (!ec && read_msg_.decode_header())
                    {
                    do_read_body();
                    }
                    else
                    {
                    socket_.close();
                    }
                    });
        }

        // CSE3310 (client) message body is received from the server
        void do_read_body()
        {
            asio::async_read(socket_,
                    asio::buffer(read_msg_.body(), read_msg_.body_length()),
                    [this](std::error_code ec, std::size_t /*length*/)
                    {
                    if (!ec)
                    {
                    std::cout.write(read_msg_.body(), read_msg_.body_length());
                    std::cout << "\n";
                    do_read_header();
                    }
                    else
                    {
                    socket_.close();
                    }
                    });
        }

        void do_write()
        {
            asio::async_write(socket_,
                    asio::buffer(write_msgs_.front().data(),
                        write_msgs_.front().length()),
                    [this](std::error_code ec, std::size_t /*length*/)
                    {
                    if (!ec)
                    {
                    write_msgs_.pop_front();
                    if (!write_msgs_.empty())
                    {
                    do_write();
                    }
                    }
                    else
                    {
                    socket_.close();
                    }
                    });
        }

    private:
        asio::io_context& io_context_;
        tcp::socket socket_;
        chat_message read_msg_;
        chat_message_queue write_msgs_;
};

/*
   int main(int argc, char* argv[])
   {
   try
   {
   if (argc != 3)
   {
   std::cerr << "Usage: chat_client <host> <port>\n";
   return 1;
   }

   std::string name, studID;
   nlohmann::json prepender;

   std::cout << "Please enter your name." << std::endl;
   std::cin >> name;
   std::cout << "Please enter your student ID." << std::endl;
   std::cin >> studID; 

   prepender["name"] = name;
   prepender["studID"] = studID;

   asio::io_context io_context;

   tcp::resolver resolver(io_context);
   auto endpoints = resolver.resolve(argv[1], argv[2]);
   chat_client c(io_context, endpoints);

   std::thread t([&io_context](){ io_context.run(); });

   char line[chat_message::max_body_length + 1];
// CSE3310 (client) accepts input from the user via cin.
while (std::cin.getline(line, chat_message::max_body_length + 1))
{
time_t currTime;
tm* currTm;

char timeString[100];

time(&currTime);
currTm = localtime(&currTime);

strftime(timeString, 50, "%T", currTm);

prepender["chrono"] = std::string{timeString};

chat_message msg;
char newLine[prepender.dump().size() + 1 + std::strlen(line)];
for(int i = 0; i < prepender.dump().size() + 1 + std::strlen(line); i++){
newLine[i] = ' ';
}
std::strcpy(newLine, prepender.dump().c_str());
std::memcpy(newLine+prepender.dump().size(), line, std::strlen(line));

msg.body_length(std::strlen(newLine));
std::memcpy(msg.body(), newLine, msg.body_length());
msg.encode_header();
c.write(msg);
}

c.close();
t.join();
}
catch (std::exception& e)
{
std::cerr << "Exception: " << e.what() << "\n";
}

return 0;
}*/
