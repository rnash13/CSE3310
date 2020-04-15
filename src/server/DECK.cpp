
#include"DECK.h"


DECK::DECK()
{
	for(int x = 0; x < 4; x++)
	{
		for(int y = 2; y < 15; y++)
		{
			_cards[x*13 + y-2] = y << 4 | x;
		}
	}
}

CARD DECK::draw_card()
{
	if(_next_card_in_deck_index >= 52) throw "No more cards";
	return _cards[_next_card_in_deck_index++];
}


std::vector<CARD> DECK::draw_card(int draw_amount)
{
	if(_next_card_in_deck_index + draw_amount >= 52) throw "No more cards";
	std::vector<CARD> new_cards;
	for(int x = 0; x < draw_amount; x++)
		new_cards.push_back(_cards[x + _next_card_in_deck_index++]);
	return new_cards;
}


bool DECK::still_has_cards()
{
	return _next_card_in_deck_index < 52;
}
