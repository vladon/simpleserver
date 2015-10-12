#include "request_handler.h"
#include <fstream>
#include <sstream>
#include <string>
#include "reply.h"
#include "request.h"

namespace http {
    namespace server {

        request_handler::request_handler(const std::string& doc_root)
                : doc_root_(doc_root)
        {
        }

        void request_handler::handle_request(const request& req, reply& rep)
        {
            std::string request_path;
            if (req.method != "GET")
            {
                rep = reply::stock_reply(reply::not_implemented);
                return;
            }

            if (!url_decode(req.uri, request_path))
            {
                rep = reply::stock_reply(reply::internal_server_error);
                return;
            }

            std::size_t last_slash_pos = request_path.find_last_of("/");
            std::size_t last_dot_pos = request_path.find_last_of(".");
            std::string extension;
            if (last_dot_pos != std::string::npos && last_dot_pos > last_slash_pos)
            {
                extension = request_path.substr(last_dot_pos + 1);
            }

            std::string full_path = doc_root_ + request_path;
            std::ifstream is(full_path.c_str(), std::ios::in | std::ios::binary);
            if (!is)
            {
                rep = reply::stock_reply(reply::not_found);
                return;
            }

            rep.status = reply::ok;
            char buf[512];
            while (is.read(buf, sizeof(buf)).gcount() > 0)
                rep.content.append(buf, is.gcount());
            rep.headers.resize(2);
            rep.headers[0].name = "Content-Length";
            rep.headers[0].value = std::to_string(rep.content.size());
            rep.headers[1].name = "Content-Type";
            rep.headers[1].value = "text/html";
        }

        bool request_handler::url_decode(const std::string& in, std::string& out)
        {
            out.clear();
            out.reserve(in.size());
            for (std::size_t i = 0; i < in.size(); ++i)
            {
                if (in[i] == '%')
                {
                    if (i + 3 <= in.size())
                    {
                        int value = 0;
                        std::istringstream is(in.substr(i + 1, 2));
                        if (is >> std::hex >> value)
                        {
                            out += static_cast<char>(value);
                            i += 2;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (in[i] == '+')
                {
                    out += ' ';
                }
                else
                {
                    out += in[i];
                }
            }
            return true;
        }

    } // namespace server
} // namespace http
