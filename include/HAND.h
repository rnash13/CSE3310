#ifndef hand_inc
#define hand_inc

#include "CARDSTRUCT.h"

class HAND{
    public:
        HAND();
        HAND(Card cards[5]);

        void sort();

        unsigned char value(); 

        friend void to_json(nlohmann::json& j, const HAND& hand);
        friend void from_json(const nlohmann::json& j, HAND& hand);
    
    private:
        Card cards[5];
};

#endif
