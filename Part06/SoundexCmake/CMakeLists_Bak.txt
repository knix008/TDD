project(FirstExample)
cmake_minimum_required(VERSION 3.25)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild)

find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(sources 
   main.cpp 
   SoundexTest.cpp)

add_definitions(-std=c++0x)
add_executable(soundextest ${sources})

target_link_libraries(soundextest gmock)
target_link_libraries(soundextest gtest)
target_link_libraries(soundextest Threads::Threads)