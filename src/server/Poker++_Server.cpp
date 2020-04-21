#include <iostream>
#include <vector>
#include <thread>

#include "asio.hpp"
#include "chat_server.h"

int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            std::cerr << "Usage: chat_server <port> [<port> ...]\n";
            return 1;
        }

        asio::io_context io_context;

        std::vector<chat_server> servers;
        //std::vector<std::thread> serverThreads;
        for (int i = 1; i < argc; ++i) {
            tcp::endpoint endpoint(tcp::v4(), std::atoi(argv[i]));
            servers.emplace_back(io_context, endpoint);
            //serverThreads.emplace_back(&GAME_SERVER::loop, &servers[i]);
        }

        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
