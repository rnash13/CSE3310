

#include"CARD.h"

CARD::CARD() {}  // thanks array initialization


CARD::CARD(short card_value)
{
	_value = card_value;
	_rank = card_value >> 4;
	_suit = card_value & 0xF;
}


CARD::CARD(const CARD &old)
{
	this->_value = old._value;
	this->_rank = old._rank;
	this->_suit = old._suit;
}


CARD CARD::operator=(int card_value)
{
	_rank = card_value >> 4;
	_suit = card_value & 0xF;
	_value = card_value;
}



void operator<<(std::stringstream &str, CARD &card)
{
	str << std::setfill('0') << std::setw(2) << std::hex << card._value;
}