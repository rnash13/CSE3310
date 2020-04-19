#include "PLAY.h"
#include "json.hpp"

PLAY::PLAY(): PLAY(BET, 0) {}
PLAY::PLAY(PLAYTYPE type, int bet): type{type}, bet{bet} {}

void from_json(const nlohmann::json& j, PLAY& play) {
    play.type = j.at("type");
    play.bet = j.at("bet");
}

void to_json(nlohmann::json& j, const PLAY& play) {
    j = nlohmann::json{{"type", play.type}, {"bet", play.bet}};
}

