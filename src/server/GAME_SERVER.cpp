#include "chat_server.h"
#include "GAME_SERVER.h"
#include "ROUND.h"
#include "PLAYER.h"


GAME_SERVER::GAME_SERVER()
: players{std::vector<PLAYER*>{}}, participants{std::vector<chat_participant_ptr>{}} {
}

std::string GAME_SERVER::processPacket(const chat_message& message) {
	currentRound->move(message);

	std::string return_message = currentRound->return_message();
	if(currentRound->round_is_finished())
	{
		// create new round
		ROUND* next_round = new ROUND(currentRound->round_number() + 1, players);
		delete currentRound;
		currentRound = next_round;
	}
	return return_message;
}

void GAME_SERVER::addPlayer(chat_participant_ptr player, chat_message msg) {
	nlohmann::json msgjson = msg.getJson();

	participants.push_back(player);
	std::string name = "", id="";
	players.push_back(new PLAYER{name, id});
	if(players.size() == 4) start_game();
}


void GAME_SERVER::start_game()
{
	game_started = true;
	currentRound = new ROUND(0, players);

	for(int i = 0; i < players.size(); i++){
		auto temp = nlohmann::json{players[i]->current_hand()};
		participants[i]->deliver(chat_message{temp});
		std::cout << chat_message{temp}.body() << std::endl; 
	}
}


bool GAME_SERVER::has_started()
{
	return game_started;
}


void GAME_SERVER::processRound() {
	
}

void GAME_SERVER::updatePlayers() {

}


bool GAME_SERVER::updateRound() {

	return true;
}
