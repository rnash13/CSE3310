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
#include "chat_client.h"

using asio::ip::tcp;

typedef std::deque<chat_message> chat_message_queue;

chat_client::chat_client(asio::io_context& io_context,
                         const tcp::resolver::results_type& endpoints,
                         std::iostream& iobuffer)
    : io_context_(io_context),
      socket_(io_context),
      iobuffer{iobuffer} {
    do_connect(endpoints);
}

// CSE3310 (client) message is sent to the chat server.
void chat_client::write(const chat_message& msg) {
    asio::post(io_context_,
    [this, msg]() {
        bool write_in_progress = !write_msgs_.empty();
        write_msgs_.push_back(msg);
        if (!write_in_progress) {
            do_write();
        }
    });
}

void chat_client::close() {
    asio::post(io_context_, [this]() {
        socket_.close();
    });
}

void chat_client::do_connect(const tcp::resolver::results_type& endpoints) {
    // CSE3310 (client) connection is established with the server
    asio::async_connect(socket_, endpoints,
    [this](std::error_code ec, tcp::endpoint) {
        if (!ec) {
            do_read_header();
        }
    });
}

void chat_client::do_read_header() {
    asio::async_read(socket_,
                     asio::buffer(read_msg_.data(), chat_message::header_length),
    [this](std::error_code ec, std::size_t /*length*/) {
        if (!ec && read_msg_.decode_header()) {
            do_read_body();
        } else {
            socket_.close();
        }
    });
}

// CSE3310 (client) message body is received from the server
void chat_client::do_read_body() {
    asio::async_read(socket_,
                     asio::buffer(read_msg_.body(), read_msg_.body_length()),
    [this](std::error_code ec, std::size_t /*length*/) {
        if (!ec) {
            iobuffer.write(read_msg_.body(), read_msg_.body_length());
            iobuffer << "\n";
            do_read_header();
        } else {
            socket_.close();
        }
    });
}

void chat_client::do_write() {
    asio::async_write(socket_,
                      asio::buffer(write_msgs_.front().data(),
                                   write_msgs_.front().length()),
    [this](std::error_code ec, std::size_t /*length*/) {
        if (!ec) {
            write_msgs_.pop_front();
            if (!write_msgs_.empty()) {
                do_write();
            }
        } else {
            socket_.close();
        }
    });
}


