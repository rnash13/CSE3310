
#include "ROUND.h"


ROUND::ROUND(int round_number, std::vector<PLAYER*>* remaining_players, MessageQueue* queue_ptr)
: _round_number{round_number}, _remaining_players{remaining_players}
{
	_deck = DECK();
	_deck.shuffle();
	for(unsigned int x = 0; x < _remaining_players->size(); x++) 
		(*_remaining_players)[x]->setHand(_deck.draw_card(5));
}

// ——————————————— GAME COMMUNICATION ———————————————

void ROUND::move(const chat_message& message)
{
	if(all_other_players_have_folded());  // in case I decide I need to do something with this
	else
	{
		// trading phase
		if(_round_phase % 2)
		{

		}
		// betting phase
		else
		{
			int needed_bet = highest_bet() - _player_bets[_current_player];
		}


		if((unsigned int)_current_player >= _remaining_players->size())
		{
			_current_player = 0;
			_round_phase++;
		}
	}

	// all betting and trading has occured
	if(_round_phase == 5)
	{
		finish_round();
		return;
	}
}


bool ROUND::is_taking_bets()
{
	return _round_phase % 2 == 0;
}


// —————————————————— PRIVATE ———————————————————
// —————————————————————————————————————————

// ————————————————— WHOLE GAME —————————————————


void ROUND::remove_current_player()
{
	for(unsigned int x = _current_player; x < _remaining_players->size() - 1; x++)
	{
		_player_folds[x] = _player_folds[x+1];
		_player_bets[x] = _player_bets[x+1];
	}
	_remaining_players->erase(_remaining_players->begin() + _current_player);
}



// ———————————————— INDIVIDUAL PLAY —————————————————

void ROUND::process_play(nlohmann::json playJson){
	PLAY play = playJson.get<PLAY>();
	if((*_remaining_players)[_current_player]->id() != play.ID) return;

	switch(play.type){
		//BET
		case 0:
			// check if amount is enough (compare with highest bet)
			// if less, send bet amount
			// else send next player bet amount
			break;
		//CHECK
		case 1:
			_current_player++;
			break;
		//FOLD
		case 2:
			_player_folds[_current_player++] = true;
			break;
		//TRADE
		case 3:
			(*_remaining_players)[_current_player++]->trade(play.tradedCards, _deck);

			break;
		//OUT
		case 4:
			remove_current_player();
			break;
		default:
			break;
	}
}


// ——————————————————— UTILITY ———————————————————

bool ROUND::all_other_players_have_folded()
{
	for(unsigned int x = _current_player; x < _remaining_players->size(); x++)
	{
		if(!_player_folds[_current_player]) return false;
		_current_player++;
	}
	return true;
}


void ROUND::take_bets()
{
	
}

void ROUND::finish_round(){

}

int ROUND::round_number(){
	return _round_number;
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



int ROUND::highest_bet()
{
	int current_highest = _player_bets[0];
	for(unsigned int x = 0; x < _remaining_players->size(); x++)
		if(_player_bets[x] > current_highest) current_highest = _player_bets[x];
	return current_highest;
}


ROUND::~ROUND(){

};

