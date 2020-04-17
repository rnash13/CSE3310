
#ifndef _DECK_
#define _DECK_

#include<string>
#include<vector>

#include"CARDSTRUCT.h"


class DECK {
public:
    DECK();

    Card draw_card();
    std::vector<Card> draw_card(int);  // draw multiple cards
    bool still_has_cards();

private:
    Card _cards[52];
    int _next_card_in_deck_index = 0;
};

#endif
