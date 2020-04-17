#ifndef PLAYER_inc
#define PLAYER_inc

#include <string>
#include <vector>

#include "DECK.h"
#include "HAND.h"
#include "CARDSTRUCT.h"
#include "PLAY.h"

class PLAYER {
    public:
        PLAYER(std::string name, std::string id);

        void play(PLAY current_play);


        void trade(std::vector<Card> cards, DECK deck); 
        std::string name(); 
        std::string id(); 
        int money(); 
        int current_bet(); 
        HAND current_hand(); 
        PLAY current_play(); 


    private:
        std::string _name;
        std::string _id; 
        int _money=200; 

        HAND _current_hand; 
        int _current_bet; 
        PLAY _current_play; 
};

#endif

