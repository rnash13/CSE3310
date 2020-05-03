#include <sstream>

#include "chat_server.h"
#include "GAME_SERVER.h"
#include "ROUND.h"
#include "PLAYER.h"
#include "PLAY.h"


GAME_SERVER::GAME_SERVER()
: players{std::vector<PLAYER*>{}}, participants{std::vector<chat_participant_ptr>{}} {

}


void GAME_SERVER::addPlayer(chat_participant_ptr player, chat_message msg) {
	nlohmann::json msgjson = msg.getJson();

	participants.push_back(player);
	std::string name = "", id="";
	players.push_back(new PLAYER{});
	if(players.size() == 4) start_game();
}


void GAME_SERVER::start_game()
{
	game_started = true;
	currentRound = new ROUND(0, &players, &message_queue);

	for(int i = 0; i < (int) players.size(); i++){
		PLAY tempPlay{};
		tempPlay.type = PLAYTYPE::MATCHSTART;
		tempPlay.tradedCards = players[i]->current_hand().getCards();
		auto temp = nlohmann::json{tempPlay};
		participants[i]->deliver(chat_message{temp});
		std::cout << chat_message{temp}.body() << std::endl; 
	}
}


std::string GAME_SERVER::processPacket(const chat_message& message) {
	currentRound->move(message);

	std::string return_message = currentRound->return_message();
	if(currentRound->round_is_finished())
	{
		// create new round
		ROUND* next_round = new ROUND(currentRound->round_number() + 1, &players, &message_queue);
		delete currentRound;
		currentRound = next_round;
	}
}


// ——————————————————— UTILITY ———————————————————

bool GAME_SERVER::has_started()
{
	return game_started;
}


void GAME_SERVER::processInput(chat_message msg) {
	if(msg.decode_header())
	{
		std::stringstream str;
		str.write(msg.body(), msg.body_length());
		nlohmann::json j{str.str()};
		
		//TODO:
	}

	send_queued_messages();
}


void GAME_SERVER::send_queued_messages()
{
	while(message_queue.size())
	{
		auto message = message_queue[0].begin();
		participants[message->first]->deliver(message->second);
		std::cout << message->second.body() << std::endl; 
		message_queue.erase(message_queue.begin());
	}
}
