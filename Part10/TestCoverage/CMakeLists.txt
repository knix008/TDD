project(SoundexTest)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_definitions(-std=c++14)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall -fprofile-arcs -ftest-coverage -g")

find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(sources 
   SoundexTest.cpp
   testmain.cpp)

add_executable(Test ${sources})

target_link_libraries(Test CppUTest)
