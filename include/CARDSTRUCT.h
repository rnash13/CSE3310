#ifndef CARDSTRUCT_inc
#define CARDSTRUCT_inc

#include <json.hpp>

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



typedef struct card {
    unsigned int suit: 2;
    unsigned int rank: 4;
} Card;

void to_json(nlohmann::json& j, const Card& card);
void from_json(const nlohmann::json& j, Card& card);
typedef unsigned char card_int;
card_int cardAsInt(const Card card);

#endif
