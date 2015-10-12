#ifndef HTTP_CONNECTION_MANAGER_HPP
#define HTTP_CONNECTION_MANAGER_HPP

#include <set>
#include "connection.h"

namespace http {
    namespace server {

        class connection_manager
        {
        public:
            connection_manager();

            connection_manager(const connection_manager&) = delete;
            connection_manager& operator=(const connection_manager&) = delete;

            ~connection_manager() = default;

            void start(connection_ptr c);
            void stop(connection_ptr c);
            void stop_all();

        private:
            std::set<connection_ptr> connections_;
        };

    } // namespace server
} // namespace http

#endif // HTTP_CONNECTION_MANAGER_HPP
