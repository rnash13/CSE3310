#ifndef GAME_SERVER_inc
#define GAME_SERVER_inc

#include "chat_participant.h"
#include "asio.hpp"
#include "PLAYER.h"
#include "DECK.h"
#include "ROUND.h"

#include <vector>

class GAME_SERVER {
    public:
        GAME_SERVER();
        
        void loop();
        void addPlayer(chat_participant_ptr player, chat_message msg); 
        void processRound();
        void updatePlayers();
        
        bool processPacket();
        bool updateRound();

    private:
        ROUND currentRound;
        DECK deck;
        std::vector<PLAYER*> players;
        std::vector<chat_participant_ptr> participants;
};

#endif
