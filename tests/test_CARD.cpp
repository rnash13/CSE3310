#include "CARDSTRUCT.h"

Card makeCard(unsigned int suit, unsigned int rank){
    Card temp;
    temp.suit = suit;
    temp.rank = rank;
    return temp;
}

int main(/*int argc, char *argv[]*/){
    assert(makeCard(1, 5).rank == makeCard(2, 5).rank);
    assert(cardAsInt(makeCard(1, 5)) < cardAsInt(makeCard(0, 6)));
    assert(cardAsInt(makeCard(3, 5)) < cardAsInt(makeCard(3, 6)));
    assert(makeCard(0, 10).suit == 0);
    return 0;
}
