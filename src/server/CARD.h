
#ifndef _CARD_
#define _CARD_

#include<iomanip>
#include<map>
#include<sstream>


enum RANK_ENUM
{
	TWO = 2,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING
};


enum SUIT_ENUM
{
	CLUBS,
	SPADES,
	DIAMONDS,
	HEARTS
};


const std::map<int, std::string> RANK_STRINGS =	{
															{2, "Two"}, {3, "Three"}, {4, "Four"}, 
															{5, "Five"}, {6, "Six"}, {7, "Seven"},
															{8, "Eight"}, {9, "Nine"}, {10, "Ten"}, 
															{11, "Jack"}, {12, "Queen"},
															{13, "King"}, {14, "Ace"}
														};


const std::map<int, std::string> SUIT_STRINGS =	{
															{0, "Clubs"}, {1, "Spades"}, 
															{2, "Diamonds"}, {3, "Hearts"}
														};


class CARD
{
	public:
		CARD();
		CARD(short);
		CARD(const CARD&);  // copy constructor

		std::string card_name();

		friend void operator<<(std::stringstream &str, CARD &card);
		CARD operator=(int card_value);

	private:
		short _rank;
		short _suit;
		short _value;  // determined by deck on creation time
};


#endif
