

#ifndef _HAND_
#define _HAND_


#include<vector>

#include"CARD.h"


enum HAND_ENUM
{
	NOTHING,
	ONE_PAIR,
	TWO_PAIR,
	THREE_OF_A_KIND,
	STRIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRIGHT_FLUSH,
	ROYAL_FLUSH
};


class HAND
{
	public:
		HAND(CARD[]);  // cards already determined
		HAND(std::string);  // JSON usage

		std::vector<CARD> cards();  // return cards in hand
		std::vector<CARD> trade(std::vector<CARD>);  // set cards in array

		int value();  // return what type of hand this is

		friend std::string operator<<(std::string, HAND);
		std::string operator+(std::string);

	private:
		CARD _cards[5];
};



#endif