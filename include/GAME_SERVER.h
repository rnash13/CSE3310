#ifndef GAME_SERVER_inc
#define GAME_SERVER_inc

#include "chat_server.h"
#include "asio.hpp"
#include "PLAYER.h"
#include "DECK.h"

#include <vector>

class GAME_SERVER {
    public:
        GAME_SERVER(asio::io_context& io_context, const tcp::endpoint& endpoint);
        
        void loop();
        void addPlayer(chat_participant_ptr player);
        void processRound();
        void updatePlayers();
        
        bool processPacket();
        bool updateRound();

    private:
        ROUND currentRound;
        std::vector<Player*> players;
        std::vector<chat_participant_ptr> participants;
};

#endif
