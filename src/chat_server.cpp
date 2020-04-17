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

//Add participant to chat_room and send them all of the messages sent so far
void chat_room::join(chat_participant_ptr participant) {
    participants_.insert(participant);
    // CSE3310 (server)  previous chat messages are sent to a client
    std::cout << "User has joined, " << this << " is now at " << participants_.size() << std::endl;
    for (auto msg: recent_msgs_)
        participant->deliver(msg);
}

//Remove participant form the chatroom
void chat_room::leave(chat_participant_ptr participant) {
    participants_.erase(participant);
}

//Deliver a message to everyone in the chatroom
void chat_room::deliver(const chat_message& msg) {
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > max_recent_msgs)
        recent_msgs_.pop_front();

    // CSE3310 (server)  messages are sent to all connected clients
    for (auto participant: participants_)
        participant->deliver(msg);
}

//Deliver a message to a specific user from the chatroom
void chat_room::deliverTo(const chat_message& msg, chat_participant_ptr participant) {
    participant->deliver(msg);
}

//Allegedly returns participants but can't confirm it works
const std::set<chat_participant_ptr>& chat_room::getChatParticipants() {
    return participants_;
}

//Get participants_size (can't confirm it works
std::size_t chat_room::participantsSize() {
    return participants_.size();
}

//----------------------------------------------------------------------

//Initialize a chat_session from a socket and chat_room reference
//move the socket from its source to this object
//use the old room as a constructor parameter for the new room.
chat_session::chat_session(tcp::socket socket, chat_room& room)
    : socket_(std::move(socket)),
      room_(room) {
}

//Start the chat session
void chat_session::start() {
    //When session is started send this session as an operator for room_.join
    room_.join(shared_from_this());
    do_read_header();
}

//Deliver message
void chat_session::deliver(const chat_message& msg) {
    //initialize write_in_progress as not write_msgs empty
    bool write_in_progress = !write_msgs_.empty();
    //Push msg on to write_msgs
    write_msgs_.push_back(msg);
    //If it isn't busy then write the message
    if (!write_in_progress) {
        do_write();
    }
}

//
void chat_session::do_read_header() {
    //Initialize a chat_participant_ptr of this object called self
    auto self(shared_from_this());

    //Define an async_read handler
    //Read from socket
    //An asio::buffer constructed from read_msg_.data() and the header_length
    asio::async_read(socket_,
                     asio::buffer(read_msg_.data(), chat_message::header_length),
    // A function used to handle the async_read that knows everything from this and self
    // Receives an error_code and size (unused)
    [this, self](std::error_code ec, std::size_t /*length*/) {
        //If no error and decode header is true read the message
        //Otherwise leave the room    
        if (!ec && read_msg_.decode_header()) {
            do_read_body();
        } else {
            room_.leave(shared_from_this());
        }
    });
}

//Reads the message body from the socket
void chat_session::do_read_body() {
    //Define self as pointer to this
    auto self(shared_from_this());
    //Define async_read handler from socket and the buffer of the message
    asio::async_read(socket_,
                     asio::buffer(read_msg_.body(), read_msg_.body_length()),
    //This function receives the error code and size(unused)
    [this, self](std::error_code ec, std::size_t /*length*/) {
        //If there's no error then deliver the message and read the header
        //Otherwise leave the room
        if (!ec) {
            //Don't want everyone to recieve the messages sent from the players
            //room_.deliver(read_msg_);
            do_read_header();
        } else {
            room_.leave(shared_from_this());
        }
    });
}

//Write to the message buffer
void chat_session::do_write() {
    //Define self as this
    auto self(shared_from_this());
    //Define async_write handler for this socket from the asio:buffer built from the front write_msg data and length
    asio::async_write(socket_,
                      asio::buffer(write_msgs_.front().data(),
                                   write_msgs_.front().length()),
    //This function knows everything inside of this and self and receives an error_code and unused size
    [this, self](std::error_code ec, std::size_t /*length*/) {
        //If no error then write the message and pop write_msgs until it's empty
        //Otherwise leave the room
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

//chat_server constructor
//initialize acceptor_ from(io_context and endpoint) references
chat_server::chat_server(asio::io_context& io_context,
                         const tcp::endpoint& endpoint)
    : acceptor_(io_context, endpoint) {
    do_accept();
}

//Define the acceptor_ async_accept listener
void chat_server::do_accept() {
    //Define lambda function for async_accept, recieves an std::error_code and a tcp::socket
    acceptor_.async_accept(
    [this](std::error_code ec, tcp::socket socket) {
        if (!ec) {
            //If there is no error then make a shared chat_session which moves this object's socket to itself and recieves a room_ object, then run start.
            std::make_shared<chat_session>(std::move(socket), room_)->start();
        }
        //Reassign this function as the listener for acceptor_
        do_accept();
    });
}

