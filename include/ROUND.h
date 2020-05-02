#ifndef ROUND_inc
#define ROUND_inc

#include"chat_message.hpp"
#include"CARD.h"
#include "PLAYER.h"

#include <vector>
#include<string>

class ROUND {
public:
	ROUND(int round_number, std::vector<PLAYER*> remaining_players);

	void deal();
	Card draw_card();
	std::vector<Card> draw_card(int);
	void take_bets();
	void finish_round();

	void move(const chat_message& message);
	std::string return_message();
    void process_play(nlohmann::json play);

	int round_number();
	bool round_is_finished();

	~ROUND();

private:
	int _round_number;
	std::vector<PLAYER*>  _remaining_players;
	DECK _deck;
	int _current_bet;
	int _current_pot;
	int _current_player;
};

#endif

