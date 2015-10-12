cmake_minimum_required(VERSION 3.0)
project(simpleserver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
    simpleserver/connection.cpp
        simpleserver/connection.h
        simpleserver/connection_manager.cpp
        simpleserver/connection_manager.h
        simpleserver/header.h
        simpleserver/main.cpp
        simpleserver/reply.cpp
        simpleserver/reply.h
        simpleserver/request_handler.cpp
        simpleserver/request_handler.h
        simpleserver/request.h
        simpleserver/request_parser.cpp
        simpleserver/request_parser.h
        simpleserver/server.cpp
        simpleserver/server.h)

find_package(Threads)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost
    1.55.0
    REQUIRED
    COMPONENTS
        system
)

add_executable(simpleserver ${SOURCE_FILES})
target_link_libraries(simpleserver ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})
