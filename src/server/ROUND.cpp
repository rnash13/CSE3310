#include "ROUND.h"
#include "PLAYER.h"
#include"CARD.h"



ROUND::ROUND(int round_number, std::vector<PLAYER*> remaining_players): _round_number{round_number}, _remaining_players{remaining_players} {
	_deck = DECK();
	_deck.shuffle();
	for(int x = 0; x < _remaining_players.size(); x++) _remaining_players[x]->setHand(_deck.draw_card(5));
}

void ROUND::deal(){
	for(auto &player: _remaining_players){
		//auto &hand = player->current_hand();
		//Implement filling player's hand with cards from deck
	}
}

void ROUND::move(const chat_message& message)
{

}


void ROUND::take_bets(){
	
}

void ROUND::finish_round(){

}

int ROUND::round_number(){
	return _round_number;
}


std::string ROUND::return_message()
{
	std::string message;
	return message;
}


bool ROUND::round_is_finished()
{
	return false;
}


Card ROUND::draw_card()
{
	return _deck.draw_card();
}


std::vector<Card> ROUND::draw_card(int draw_amount)
{
	return _deck.draw_card(draw_amount);
}


ROUND::~ROUND(){

};

