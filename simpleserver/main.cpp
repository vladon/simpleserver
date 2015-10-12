#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "server.h"

int main(int argc, char* argv[])
{
    try
    {
        if (argc != 4)
        {
            std::cerr << "Usage: simpleserver <address> <port> <doc_root>\n";
            std::cerr << "  For example, try:\n";
            std::cerr << "    simpleserver 0.0.0.0 8080 .\n";
            return 1;
        }

        http::server::server s(argv[1], argv[2], argv[3]);

        s.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
