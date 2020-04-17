#include"DECK.h"
#include"CARDSTRUCT.h"

DECK::DECK() {
    for(unsigned int i = 0; i < 52; i++) {
        const unsigned int suit = i%4;
        const unsigned int rank = (i/13)+1;
        _cards[i] = Card{suit, rank};
    }
}

Card DECK::draw_card() {
    if(_next_card_in_deck_index >= 52) throw "No more cards";
    return _cards[_next_card_in_deck_index++];
}


std::vector<Card> DECK::draw_card(int draw_amount) {
    if(_next_card_in_deck_index + draw_amount >= 52) throw "No more cards";
    std::vector<Card> new_cards;
    for(int x = 0; x < draw_amount; x++)
        new_cards.push_back(_cards[x + _next_card_in_deck_index++]);
    return new_cards;
}


bool DECK::still_has_cards() {
    return _next_card_in_deck_index < 52;
}
