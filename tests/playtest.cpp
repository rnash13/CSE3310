#include "PLAY.h"

#include <string>

int main(){
    std::vector<PLAY> plays;
    for(int i = 0; i < 5; i++){
        plays.push_back(PLAY{static_cast<PLAYTYPE>(i), 100});
    }
    return 0;
}
