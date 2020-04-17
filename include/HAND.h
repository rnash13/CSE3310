#ifndef hand_inc
#define hand_inc

#include "CARDSTRUCT.h"

enum HAND_ENUM {
    NOTHING,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRIGHT_FLUSH,
    ROYAL_FLUSH
};

class HAND {
public:
    HAND();
    HAND(std::vector<Card> cards);
    HAND(std::string);  // JSON usage

    void sort();

    unsigned char value();

    friend void to_json(nlohmann::json& j, const HAND& hand);
    friend void from_json(const nlohmann::json& j, HAND& hand);
    friend std::string operator<<(std::string, HAND);

    const std::vector<Card>& getCards();

    std::string operator+(std::string);

private:
    std::vector<Card> cards;
};

#endif
