#ifndef GAME_SERVER_inc
#define GAME_SERVER_inc

#include "chat_server.h"
#include "asio.hpp"

class GAME_SERVER: public chat_server {
public:
    GAME_SERVER(asio::io_context& io_context, const tcp::endpoint& endpoint);
    void loop();
};

#endif
