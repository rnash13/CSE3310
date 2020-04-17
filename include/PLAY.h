#ifndef PLAY_inc
#define PLAY_inc

#include "json.hpp"

enum PLAYTYPE{
    BET,
    CHECK,
    FOLD,
    TRADE,
    OUT
};



typedef struct play{
    PLAYTYPE type;
    int bet;  
}PLAY;

void to_json(nlohmann::json& j, const PLAY& play);
void from_json(const nlohmann::json& j, PLAY& play);

#endif

