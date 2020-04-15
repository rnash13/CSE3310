#include <json.hpp>

typedef struct card {
    unsigned int suit: 2;
    unsigned int rank: 4;
} Card;

void to_json(nlohmann::json& j, const Card& card) {
    j = nlohmann::json{{"rank", card.rank}, {"suit", card.suit}};
}

void from_json(const nlohmann::json& j, const Card& card) {
    j.at("rank").get_to(card.rank);
    j.at("suit").get_to(card.suit);
}
