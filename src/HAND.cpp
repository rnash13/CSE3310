#include "HAND.h"

#include<algorithm>

HAND::HAND() {
    Card temp{3, 15};
    for(int i = 0; i < 5; i++) {
        cards[i] = temp;
        temp.rank--;
    }
}

HAND::HAND(Card inCards[5]) {
    for(int i = 0; i < 5; i++) {
        cards[i] = inCards[i];
    }
}

void HAND::sort() {
    std::sort(cards, cards+5, [](Card a, Card b) {
        return cardAsInt(a) < cardAsInt(b);
    });
}

//Check for four of a kind
//TODO MAKE cards[4] HOLD HIGHEST RANK FROM QUARTET
bool checkFourOfKind(Card cards[5]) {
    return (cards[0].rank == cards[3].rank || cards[1].rank == cards[3].rank);
}

bool checkFullHouse(Card cards[5]) {
    return ((cards[0].rank == cards[1].rank && cards[2].rank == cards[4].rank) || (cards[0].rank == cards[2].rank && cards[3].rank == cards[4].rank));
}

//Check for Flush
bool checkFlush(Card cards[5]) {
    //Save suit of first card to compare to all other cards
    int suit = cards[0].suit;
    //Flag to be swapped if any of the cards fail either suit check or rank check.
    bool flag = true;
    for(int i = 0; i < 5; i++) {
        if(cards[i].suit != suit)
            flag = false;
    }
    return flag;
}

bool checkStraight(Card cards[5]) {
    int rank = cards[0].rank;
    bool flag = true;
    for(int i = 0; i < 5; i++) {
        if(cards[i].rank != rank++)
            flag = false;
    }
    return flag;
}

//Checks for a set of three of a kind
//TODO SET card[4] TO RANK OF TRIO
bool checkThreeOfAKind(Card cards[5]) {
    /*
    0 == 2 && 2 != 3
    0 != 1 && 1 == 3 && 3 !=4
    1 != 2 && 2 == 4
    */
    return ((cards[0].rank == cards[2].rank && cards[2].rank != cards[3].rank) ||
            (cards[0].rank != cards[1].rank && cards[1].rank == cards[3].rank && cards[3].rank != cards[4].rank) ||
            (cards[1].rank != cards[2].rank && cards[2].rank == cards[4].rank));
}

//Helper function that runs == && == && != && != on 8 numbers to check for pairs exhaustively
//TODO This is probably the wrong way to do this, someone help
bool checkSpecificPairs(Card cards[5], int pairs[8]) {
    std::transform(pairs, pairs+8, pairs, [&] (int ind) -> int { return cards[ind].rank; });

    return (pairs[0] == pairs[1]) && (pairs[2] == pairs[3]) && (pairs[4] != pairs[5]) && (pairs[6] != pairs[7]);
}

//Check for two pairs.
//TODO Make card[4] be one of the cards from the pair with the highest rank
bool checkTwoPairs(Card cards[5]) {
    /*
    0&1 2&3 1!2 3!4
    0&1 3&4 1!2 2!3
    1&2 3&4 0!1 2!3
    */
    int pairs[3][8] = {{0,1,2,3,1,2,3,4},
        {0,1,3,4,1,2,2,3},
        {1,2,3,4,0,1,2,3}
    };
    bool checks[3];
    std::transform(pairs, pairs+3, checks,  [&] (int set[8]) -> bool { return checkSpecificPairs(cards, set); });
    bool flag = false;
    for(int i = 0; i < 3; i++) {
        if(checks[i])
            flag = true;
    }
    return  flag;
}

//Helper function to check for a single pair by applying a != && == && != set of operations
bool checkSinglePair(Card cards[5], int pairs[6]) {
    std::transform(pairs, pairs+6, pairs, [&] (int ind) -> int { return cards[ind].rank; });
    return (pairs[0] != pairs[1]) && (pairs[2] == pairs[3]) && (pairs[4] != pairs[5]);
}

//Check for a single pair
//TODO Set card with rank of pair to card[4]
bool checkOnePair(Card cards[5]) {
    /*
    0&1 1!2
    0!1 1&2 2!3
    1!2 2&3 3!4
    2!3 3&4 4!5
    3!4 4&5
    */
    int pairs[5][6] = {{2, 0, 0, 1, 1, 2},
        {0, 1, 1, 2, 2, 3},
        {1, 2, 2, 3, 3, 4},
        {2, 3, 3, 4, 4, 5},
        {3, 4, 4, 5, 5, 3}
    };
    bool checks[5];
    std::transform(pairs, pairs+5, checks, [&] (int pair[5]) -> bool { return checkSinglePair(cards, pair); });
    bool flag = false;
    for(int i = 0; i < 5; i++) {
        if(checks[i])
            flag = true;
    }
    return flag;
}

//Check for both a straight and a flush
bool checkSFlush(Card cards[5]) {
    return checkFlush(cards) && checkStraight(cards);
}

//Check for Flush and verify ranks match royal ranks
bool checkRFlush(Card cards[5]) {
    if(checkFlush(cards)) {
        //Const set of ranks to check royals
        const int ROYALS[5] = {1, 10, 11, 12, 13};
        //Flag to be swapped if any of the cards either fail the suit check or rank check.
        bool flag = true;
        for(int i = 0; i < 5; i++) {
            if(cards[i].rank != ROYALS[i])
                flag = false;
        }
        return flag;
    }
    return false;
}

//Value single hand exhaustively.
//TODO Currently the rank portion of the hand is valued as just the highest in hand, needs to be changed to accurate rank.
unsigned char HAND::value() {
    sort();
    unsigned char value = cards[4].rank;
    if(checkRFlush(cards))
        value += (9<<4);
    //Straight Flush
    else if(checkSFlush(cards))
        value += (8<<4);
    //Four of a Kind
    else if(checkFourOfKind(cards))
        value += (7<<4);
    //Full House
    else if(checkFullHouse(cards))
        value += (6<<4);
    //Flush
    else if(checkFlush(cards))
        value += (5<<4);
    //Straight
    else if(checkStraight(cards))
        value += (4<<4);
    //Three of a Kind
    else if(checkThreeOfAKind(cards))
        value += (3<<4);
    //Two Pairs
    else if(checkTwoPairs(cards))
        value += (2<<4);
    //One Pair
    else if(checkOnePair(cards))
        value += (1<<4);
    //Lone High Card (do nothing)

    return value;
}

void to_json(nlohmann::json& j, const HAND& hand) {
    j = nlohmann::json{{"cards", hand.cards}};
}

void from_json(const nlohmann::json& j, HAND& hand) {
    j.at("cards").get_to(hand.cards);
}

