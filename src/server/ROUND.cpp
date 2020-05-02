#include "ROUND.h"
#include "PLAYER.h"

#include <vector>

ROUND::ROUND(): ROUND{0, std::vector<PLAYER*>{}} {

}

ROUND::ROUND(int round_number, std::vector<PLAYER*> remaining_players): _remaining_players{remaining_players}, _round_number{round_number} {

}

void ROUND::deal(){
    //for(auto &player: _remaining_players){
        //auto &hand = player->current_hand();
        //Implement filling player's hand with cards from deck
    //}
}

void ROUND::take_bets(){
    
}

void ROUND::finish_round(){

}

int ROUND::round_number(){
    return _round_number;
}

void ROUND::process_play(nlohmann::json play){
    if(_remaining_players(_current_player).id != play["id"]) return;

    switch(play["type"]){
        //BET
        case 0:
            break;
        //CHECK
        case 1:
            break;
        //FOLD
        case 2:
            break;
        //TRADE
        case 3:
            break;
        //OUT
        case 4:
            break;
        default:
            break;
    }
}

ROUND::~ROUND(){

};

