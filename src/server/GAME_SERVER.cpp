#include "chat_server.h"
#include "GAME_SERVER.h"
#include "ROUND.h"
#include "PLAYER.h"

typedef std::shared_ptr<chat_participant> chat_participant_ptr;

GAME_SERVER::GAME_SERVER(): currentRound{ROUND{}}, players{std::vector<PLAYER*>{}}, participants{std::vector<chat_participant_ptr>{}}, deck{DECK{}} {
    deck.shuffle();
}

void GAME_SERVER::loop() {

}

void GAME_SERVER::addPlayer(chat_participant_ptr player, chat_message msg) {
    nlohmann::json msgjson = msg.getJson();

    participants.push_back(player);
    std::string name = "", id="";
    players.push_back(new PLAYER{name, id});
    if(players.size() == 4){
        for(int i = 0; i < 4; i++){
            players[i]->setHand(deck.draw_card(5));
            auto temp = nlohmann::json{players[i]->current_hand()};
            participants[i]->deliver(chat_message{temp});
            std::cout << chat_message{temp}.body() << std::endl; 
        }
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
