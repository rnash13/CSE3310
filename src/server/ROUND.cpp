#include "ROUND.h"
#include "PLAYER.h"

#include <vector>

ROUND::ROUND(): ROUND{0, std::vector<PLAYER*>{}} {

}

ROUND::ROUND(int round_number, std::vector<PLAYER*> remaining_players): _round_number{round_number}, _remaining_players{remaining_players} {

}

void ROUND::deal(){
    for(auto &player: _remaining_players){
        //auto &hand = player->current_hand();
        //Implement filling player's hand with cards from deck
    }
}

void ROUND::take_bets(){
    
}

void ROUND::finish_round(){

}

int ROUND::round_number(){
    return _round_number;
}



ROUND::~ROUND(){

};

