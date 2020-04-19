#ifndef chat_session_inc
#define chat_session_inc
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
#include "chat_participant.h"
#include "chat_room.h"

class chat_session
    : public chat_participant,
      public std::enable_shared_from_this<chat_session> {
public:

    chat_session(tcp::socket socket, chat_room& room);

    void start();

    void deliver(const chat_message& msg);

private:
    void do_read_header();

    void do_read_body();

    void do_write();

    tcp::socket socket_;
    chat_room& room_;
    chat_message read_msg_;
    chat_message_queue write_msgs_;
};

#endif
