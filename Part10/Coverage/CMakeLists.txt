project(LineReader)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_definitions(-std=c++14)

find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(sources 
   main.cpp 
   LineReaderTest.cpp)

add_executable(Test ${sources})

target_link_libraries(Test gmock)
target_link_libraries(Test gtest)
target_link_libraries(Test rt)
target_link_libraries(Test Threads::Threads)

