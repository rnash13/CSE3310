#ifndef ROUND_inc
#define ROUND_inc

#include "PLAYER.h"
#include <vector>

class ROUND {
    public:
        ROUND();
         
            ROUND(int round_number, std::vector<PLAYER*> remaining_players);

            void deal(); 
            void take_bets(); 
            void finish_round(); 

            int round_number(); 
        
        ~ROUND();

    private:
            int _round_number; 
            std::vector<PLAYER*>  _remaining_players; 
            DECK _deck; 
            int  _current_pot; 
            int  _current_player; 

    protected:
        

};

#endif

