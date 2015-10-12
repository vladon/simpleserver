#ifndef HTTP_CONNECTION_HPP
#define HTTP_CONNECTION_HPP

#include <array>
#include <memory>
#include <boost/asio.hpp>
#include "reply.h"
#include "request.h"
#include "request_handler.h"
#include "request_parser.h"

namespace http {
    namespace server {

        class connection_manager;

        class connection
                : public std::enable_shared_from_this<connection>
        {
        public:
            connection(const connection&) = delete;
            connection& operator=(const connection&) = delete;

            explicit connection(boost::asio::ip::tcp::socket socket,
                                connection_manager& manager, request_handler& handler);

            virtual void start();
            virtual void stop();
            virtual ~connection() = default;

        private:
            virtual void do_read();
            virtual void do_write();

            boost::asio::ip::tcp::socket socket_;
            connection_manager& connection_manager_;
            request_handler& request_handler_;
            std::vector<char> buffer_;
            request request_;
            request_parser request_parser_;
            reply reply_;
        };

        typedef std::shared_ptr<connection> connection_ptr;

    } // namespace server
} // namespace http

#endif
