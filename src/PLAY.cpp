#include "PLAY.h"
#include "json.hpp"

void from_json(const nlohmann::json& j, PLAY& play){
    play.type = j.at("type");
    play.bet = j.at("bet");
}

void to_json(nlohmann::json& j, const PLAY& play){
    j = nlohmann::json{{"type", play.type}, {"bet", play.bet}};
}

