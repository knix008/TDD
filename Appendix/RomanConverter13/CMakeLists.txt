project(RomanConverter)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_definitions(-std=c++14 -fprofile-arcs -ftest-coverage -g)
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources 
   main.cpp 
   RomanConverterTest.cpp )

add_executable(Test ${sources})

target_link_libraries(Test Threads::Threads)
target_link_libraries(Test gmock)
target_link_libraries(Test gtest)
target_link_libraries(Test gcov)

