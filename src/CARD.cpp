#include <json.hpp>
#include <sstream>

#include "CARD.h"


Card::Card(int suit, int rank) : rank{rank}, suit{suit} {

}

Card::Card() : Card{0,0} {

}

void to_json(nlohmann::json& j, const Card& card) {
    j = nlohmann::json{{"rank", card.rank}, {"suit", card.suit}};
}

void from_json(const nlohmann::json& j, Card& card) {
    card.rank = j.at("rank");
    card.suit = j.at("suit");
}

int Card::asInt() {
    return suit+(rank<<2);
}

std::string Card::toEnglish(){
    std::stringstream ss;
    ss << RANK_STRINGS.at(rank) << " of " << SUIT_STRINGS.at(suit);
    return ss.str();
}

bool operator==(const Card& card1, const Card& card2) {
    return (card1.rank == card2.rank) && (card2.suit == card2.suit);
}
