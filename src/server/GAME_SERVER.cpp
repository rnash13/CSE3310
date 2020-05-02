#include <sstream>

#include "chat_server.h"
#include "GAME_SERVER.h"
#include "ROUND.h"
#include "PLAYER.h"
#include "PLAY.h"

typedef std::shared_ptr<chat_participant> chat_participant_ptr;

GAME_SERVER::GAME_SERVER(): currentRound{ROUND{}}, deck{DECK{}}, players{std::vector<PLAYER*>{}}, participants{std::vector<chat_participant_ptr>{}} {
    deck.shuffle();
}

void GAME_SERVER::loop() {

}

void GAME_SERVER::addPlayer(chat_participant_ptr player, chat_message msg) {
    nlohmann::json msgjson = msg.getJson();

    participants.push_back(player);
    std::string name = "", id="";
    players.push_back(new PLAYER{});
    if(players.size() == 4){
        for(int i = 0; i < 4; i++){
            players[i]->setHand(deck.draw_card(5));
            PLAY play{MATCHSTART, players[i]->current_hand()};
            auto temp = nlohmann::json{play};
            participants[i]->deliver(chat_message{temp});
            std::cout << chat_message{temp}.body() << std::endl; 
        }
    }
}

void GAME_SERVER::processInput(chat_message msg) {
    if(msg.decode_header()){
        std::stringstream str;
        str.write(msg.body(), msg.body_length());
        nlohmann::json j{str.str()};
        
    }
}

void GAME_SERVER::processRound() {
    
}

void GAME_SERVER::updatePlayers() {

}

bool GAME_SERVER::processPacket() {

    return true;
}

bool GAME_SERVER::updateRound() {

    return true;
}
