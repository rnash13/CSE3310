//
// chat_server.cpp
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
#include <list>
#include <memory>
#include <set>
#include <utility>
#include "asio.hpp"
#include "chat_message.hpp"
#include "chat_server.h"

using asio::ip::tcp;

//----------------------------------------------------------------------

typedef std::deque<chat_message> chat_message_queue;

//----------------------------------------------------------------------

void chat_room::join(chat_participant_ptr participant) {
    participants_.insert(participant);
    // CSE3310 (server)  previous chat messages are sent to a client
    std::cout << "User has joined, " << &participants_ << " is now at " << participants_.size() << std::endl;
    for (auto msg: recent_msgs_)
        participant->deliver(msg);
}

void chat_room::leave(chat_participant_ptr participant) {
    participants_.erase(participant);
}

void chat_room::deliver(const chat_message& msg) {
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > max_recent_msgs)
        recent_msgs_.pop_front();

    // CSE3310 (server)  messages are sent to all connected clients
    for (auto participant: participants_)
        participant->deliver(msg);
}

void chat_room::deliverTo(const chat_message& msg, chat_participant_ptr participant) {
    participant->deliver(msg);
}

const std::set<chat_participant_ptr>& chat_room::getChatParticipants() {
    return participants_;
}

int chat_room::participantsSize() {
    return participants_.size();
}

//----------------------------------------------------------------------

chat_session::chat_session(tcp::socket socket, chat_room& room)
    : socket_(std::move(socket)),
      room_(room) {
}

void chat_session::start() {
    room_.join(shared_from_this());
    do_read_header();
}

void chat_session::deliver(const chat_message& msg) {
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress) {
        do_write();
    }
}

void chat_session::do_read_header() {
    auto self(shared_from_this());
    asio::async_read(socket_,
                     asio::buffer(read_msg_.data(), chat_message::header_length),
    [this, self](std::error_code ec, std::size_t /*length*/) {
        if (!ec && read_msg_.decode_header()) {
            do_read_body();
        } else {
            room_.leave(shared_from_this());
        }
    });
}

void chat_session::do_read_body() {
    auto self(shared_from_this());
    asio::async_read(socket_,
                     asio::buffer(read_msg_.body(), read_msg_.body_length()),
    [this, self](std::error_code ec, std::size_t /*length*/) {
        if (!ec) {
            //Don't want everyone to recieve the messages sent from the players
            //room_.deliver(read_msg_);
            do_read_header();
        } else {
            room_.leave(shared_from_this());
        }
    });
}

void chat_session::do_write() {
    auto self(shared_from_this());
    asio::async_write(socket_,
                      asio::buffer(write_msgs_.front().data(),
                                   write_msgs_.front().length()),
    [this, self](std::error_code ec, std::size_t /*length*/) {
        if (!ec) {
            write_msgs_.pop_front();
            if (!write_msgs_.empty()) {
                do_write();
            }
        } else {
            room_.leave(shared_from_this());
        }
    });
}

//----------------------------------------------------------------------

chat_server::chat_server(asio::io_context& io_context,
                         const tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint) {
    do_accept();
}

void chat_server::do_accept() {
    acceptor_.async_accept(
    [this](std::error_code ec, tcp::socket socket) {
        if (!ec) {
            std::make_shared<chat_session>(std::move(socket), room_)->start();
        }

        do_accept();
    });
}

