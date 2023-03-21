project(RomanConverter)
cmake_minimum_required(VERSION 3.16)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(sources 
   main.cpp 
   RomanConverterTest.cpp )

add_executable(Test ${sources})

target_link_libraries(Test Threads::Threads)
target_link_libraries(Test gmock)
target_link_libraries(Test gtest)