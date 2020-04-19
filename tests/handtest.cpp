#include "HAND.h"
#include "CARD.h"
#include "asio.hpp"
#include "json.hpp"

#include<iostream>
#include<iomanip>

Card makeCard(unsigned int suit, unsigned int rank) {
    Card temp;
    temp.suit = suit;
    temp.rank = rank;
    return temp;
}

int main(/*int argc, char *argv[]*/) {
    std::vector<HAND> hands{
        std::vector<Card>{Card{0, 1}, Card{0, 13}, Card{0, 12}, Card{0, 11}, Card{0, 10}},
        std::vector<Card>{Card{0, 9}, Card{0, 13}, Card{0, 12}, Card{0, 11}, Card{0, 10}},
        std::vector<Card>{Card{0, 4}, Card{1, 4}, Card{2, 4}, Card{3, 4}, Card{3, 13}},
        std::vector<Card>{Card{0, 4}, Card{1, 4}, Card{2, 4}, Card{3, 2}, Card{3, 2}},
        std::vector<Card>{Card{0, 4}, Card{0, 5}, Card{0, 3}, Card{0, 10}, Card{0, 13}},
        std::vector<Card>{Card{0, 2}, Card{1, 3}, Card{2, 4}, Card{3, 5}, Card{1, 1}},
        std::vector<Card>{Card{0, 4}, Card{1, 4}, Card{2, 4}, Card{3, 3}, Card{3, 13}},
        std::vector<Card>{Card{0, 4}, Card{1, 4}, Card{2, 2}, Card{3, 2}, Card{3, 13}},
        std::vector<Card>{Card{0, 4}, Card{1, 4}, Card{2, 1}, Card{3, 2}, Card{3, 13}},
        std::vector<Card>{Card{0, 1}, Card{1, 2}, Card{2, 3}, Card{3, 4}, Card{3, 6}},
    };

    std::vector<unsigned char> expectedValues{
        0x9d,
        0x8d,
        0x74,
        0x64,
        0x5d,
        0x45,
        0x34,
        0x24,
        0x14,
        0x06
    };
    for(auto i = 0; i < (int) hands.size(); i++) {
        auto hand = hands[i];
        nlohmann::json j = hand;
        //HAND hand2 = j.get<HAND>();
        assert(hand.value() == expectedValues[i]);
        std::cout << std::endl << j << std::endl;
        std::cout << std::hex << std::setw(2) << std::setfill('0') << "0x" << (int) hand.value() << std::endl;
        std::cout << std::dec << hand.valueStr() << std::endl;
    }
    return 0;
}
