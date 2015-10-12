//
// reply.hpp
// ~~~~~~~~~
//
// Copyright (c) 2003-2015 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef HTTP_REPLY_HPP
#define HTTP_REPLY_HPP

#include <string>
#include <vector>
#include <boost/asio.hpp>
#include "header.h"

namespace http {
    namespace server {

        struct reply
        {
            enum status_type
            {
                ok = 200,
                not_found = 404,
                internal_server_error = 500,
                not_implemented = 501
            } status;

            std::vector<header> headers;
            std::string content;
            std::vector<boost::asio::const_buffer> to_buffers();
            static reply stock_reply(status_type status);
        };

    } // namespace server
} // namespace http

#endif // HTTP_REPLY_HPP
