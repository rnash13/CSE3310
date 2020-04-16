#ifndef CARDSTRUCT_inc
#define CARDSTRUCT_inc

#include <json.hpp>

typedef struct card {
    unsigned int suit: 2;
    unsigned int rank: 4;
} Card;

void to_json(nlohmann::json& j, const Card& card);
void from_json(const nlohmann::json& j, Card& card);
typedef unsigned char card_int;
card_int cardAsInt(const Card card);

#endif
