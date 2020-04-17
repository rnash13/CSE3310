
/***********************************************************************************************************
*
*	created by: MPZinke
*	on ..
*
*	DESCRIPTION: TEMPLATE
*	BUGS:
*	FUTURE:
*
***********************************************************************************************************/

#include<iostream>
#include"CARD.h"
#include"DECK.h"
#include"HAND.h"

using namespace std;



int main() {
    DECK new_deck;
    for(int x = 0; x < 52; x++) {
        CARD tmp = new_deck.draw_card();
        std::stringstream str;
        str << tmp;
        std::cout << str.str() << std::endl;
    }

    return 0;
}
