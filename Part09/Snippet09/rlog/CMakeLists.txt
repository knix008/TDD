project(rlogStub)
cmake_minimum_required(VERSION 2.6)

include_directories($ENV{RLOG_HOME})

add_definitions(-std=c++0x)

find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -DRLOG_COMPONENT=debug -Wall")
set(sources rlog.cpp RLogChannel.cpp RLogNode.cpp StdioNode.cpp)

add_library(rlogStub ${sources})

target_link_libraries(rlogStub Threads::Threads)