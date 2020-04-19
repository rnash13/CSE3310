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
#include "chat_session.h"
#include "chat_room.h"
#include "chat_participant.h"
#include "chat_server.h"

using asio::ip::tcp;

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
    //Define lambda function for async_accept, receives an std::error_code and a tcp::socket
    acceptor_.async_accept(
    [this](std::error_code ec, tcp::socket socket) {
        if (!ec) {
            //If there is no error then make a shared chat_session which moves this object's socket to itself and receives a room_ object, then run start.
            std::make_shared<chat_session>(std::move(socket), room_)->start();
        }
        //Reassign this function as the listener for acceptor_
        do_accept();
    });
}

