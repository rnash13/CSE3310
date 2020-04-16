#include <json.hpp>

typedef struct card {
    unsigned int suit: 2;
    unsigned int rank: 4;
} Card;

void to_json(nlohmann::json& j, const Card& card) {
    j = nlohmann::json{{"rank", card.rank}, {"suit", card.suit}};
}

void from_json(const nlohmann::json& j, Card& card) {
    card.rank = j.at("rank");
    card.suit = j.at("suit");
}

typedef unsigned char card_int;

card_int cardAsInt(const Card card) {
    return *((card_int*) (&card))&0b00111111;
}