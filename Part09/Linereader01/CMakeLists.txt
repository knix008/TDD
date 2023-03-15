project(LineReader)
cmake_minimum_required(VERSION 2.6)

include_directories(~/gmock-1.6.0/include ~/gmock-1.6.0/gtest/include)
link_directories(~/gmock-1.6.0/mybuild ~/gmock-1.6.0/gtest/mybuild)
add_definitions(-std=c++0x)

find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(sources 
   main.cpp 
   LineReaderTest.cpp)

add_executable(test ${sources})

target_link_libraries(test gmock)
target_link_libraries(test gtest)
target_link_libraries(test rt)
target_link_libraries(test Threads::Threads)

