//
// chat_client.h
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

class chat_client {
public:
    chat_client(asio::io_context& io_context,
                const tcp::resolver::results_type& endpoints);

    // CSE3310 (client) message is sent to the chat server.
    void write(const chat_message& msg);
    void close();


private:
    void do_connect(const tcp::resolver::results_type& endpoints);
    void do_read_header();
    // CSE3310 (client) message body is received from the server
    void do_read_body();
    void do_write();

private:
    asio::io_context& io_context_;
    tcp::socket socket_;
    chat_message read_msg_;
    chat_message_queue write_msgs_;
};

