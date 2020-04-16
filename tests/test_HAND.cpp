#include "HAND.h"
#include "CARDSTRUCT.h"
#include "asio.hpp"

#include<iostream>

Card makeCard(unsigned int suit, unsigned int rank){
    Card temp;
    temp.suit = suit;
    temp.rank = rank;
    return temp;
}

int main(/*int argc, char *argv[]*/){
    HAND test{};
    Card cardHand[5] = {makeCard(0, 1), makeCard(0, 2), makeCard(0, 3), makeCard(0, 4), makeCard(0, 5)};
    HAND hand{cardHand};
    
    nlohmann::json j = hand;
    
    std::cout << j << std::endl;
    std::cout << std::hex << (int) hand.value() << std::endl;
    assert(hand.value() == (unsigned char) (8<<4) + 5);
    
    return 0;
}
