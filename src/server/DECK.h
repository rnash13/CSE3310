
#ifndef _DECK_
#define _DECK_

#include<string>
#include<vector>

#include"CARD.h"


class DECK
{
	public:
		DECK();

		CARD draw_card();
		std::vector<CARD> draw_card(int);  // draw multiple cards
		bool still_has_cards();

	private:
		CARD _cards[52];
		int _next_card_in_deck_index = 0;
};

#endif