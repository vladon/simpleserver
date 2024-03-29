#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

#include <boost/asio.hpp>
//#include <boost/pool/object_pool.hpp>
#include <string>
#include "connection.h"
#include "connection_manager.h"
#include "request_handler.h"

namespace http {
    namespace server {

        class server
        {
        public:
            server(const server&) = delete;
            server& operator=(const server&) = delete;

            explicit server(const std::string& address, const std::string& port,
                            const std::string& doc_root);

            void run();

        private:
            void do_accept();

            boost::asio::io_service io_service_;
            boost::asio::ip::tcp::acceptor acceptor_;
            connection_manager connection_manager_;
            boost::asio::ip::tcp::socket socket_;
            request_handler request_handler_;
            //boost::object_pool<connection> connection_pool_;
        };

    } // namespace server
} // namespace http

#endif // HTTP_SERVER_HPP
