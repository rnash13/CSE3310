#include "ROUND.h"


ROUND::ROUND(int round_number, std::vector<PLAYER*>* remaining_players, MessageQueue* queue_ptr)
    : _round_number{round_number}, _remaining_players{remaining_players}, message_queue{queue_ptr}
{
    _deck = DECK();
    _deck.shuffle();
    for(unsigned int x = 0; x < _remaining_players->size(); x++) 
        (*_remaining_players)[x]->setHand(_deck.draw_card(5));
}

// ——————————————— GAME COMMUNICATION ———————————————

void ROUND::process_play(nlohmann::json playJson){
    PLAY play = playJson.get<PLAY>();
    PLAYER* current_player = (*_remaining_players)[_current_player];
    if(current_player->id() != play.ID) return;

    if(play.type == OUT) remove_current_player();
    else if(play.type == FOLD) _player_folds[_current_player] = true;
    else if(play.type == TRADE)
    {
        if(currently_taking_bets()) return remove_current_player();  // CHEATER! (bad UI)

        (*_remaining_players)[_current_player]->trade(play.tradedCards, _deck);
        // send player all of their cards
        PLAY new_hand_play{TRADE, current_player->current_hand()};
        add_message_to_queue(new_hand_play);
    }
    else if(play.type == BET)
    {
        if(!currently_taking_bets()) return remove_current_player();  // CHEATER! (bad UI)

        current_player->money(current_player->money() - play.bet);  // decrement money
        if(play.bet < highest_bet())
        {
            play.bet = highest_bet() - play.bet;  // they still need to match the other player's bet
            return add_message_to_queue(play);  // stay on current player and request more $$
        }
    }

    _current_player++;
    if((unsigned int)_current_player == _remaining_players->size())
    {
        _current_player = 0;
        _round_phase++;
    }
}


void ROUND::add_message_to_queue(PLAY current_play)
{
    auto message = nlohmann::json{current_play};
    message_queue->push_back({{_current_player, chat_message{message}}});
}


// ——————————————————— UTILITY ———————————————————

bool ROUND::is_finished()
{
    return _round_phase == 5;
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


void ROUND::finish_round()
{
    // determine winner & give them money
    std::vector<unsigned char> values;
    values.resize(_remaining_players->size());
    std::transform(_remaining_players->begin(), _remaining_players->end(), values.begin(), [&] (PLAYER *player) -> unsigned char { return player->current_hand().value(); });
    int winner = 0;
    for(int i = 0; i < (int) values.size(); i++) {
        if(values[i] > values[winner])
            winner = i;
    }
    (*_remaining_players)[winner]->money((*_remaining_players)[winner]->money()+_current_pot);
    _current_pot = 0; 
    // eliminate anyone without money
    std::vector<int> removeIndeces{};
    for(int i = 0; i < (int) _remaining_players->size(); i++){
        if((*_remaining_players)[i]->money() <= 0)
            removeIndeces.insert(removeIndeces.begin(), i);
    }
    for(auto index : removeIndeces)
        (*_remaining_players).erase(_remaining_players->begin()+index);
}


// ———————————————— INDIVIDUAL PLAY —————————————————


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


bool ROUND::bet_amount_exceeds_other_players_worth(int current_bet)
{
    for(unsigned int x = 0; x < _remaining_players->size(); x++)
        if((*_remaining_players)[x]->money() + _player_bets[x] > current_bet) return true;
    return false;
}


bool ROUND::currently_taking_bets()
{
    return _round_phase % 2 == 0;
}

int ROUND::round_number()
{
    return _round_number;
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

