#include "GAME_SERVER.h"

#include "asio.hpp"

GAME_SERVER::GAME_SERVER(asio::io_context& io_context, const tcp::endpoint& endpoint) : chat_server{io_context, endpoint} {
    
}

void GAME_SERVER::loop(){
    while(true){
        sleep(1);
        std::cout << &room_.getChatParticipants() << " " << room_.participantsSize() << std::endl;
    }
}
