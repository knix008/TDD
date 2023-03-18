project(FirstExample)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(sources 
   main.cpp 
   SoundexTest.cpp)

add_definitions(-std=c++14)
add_executable(SoundexTest ${sources})

target_link_libraries(SoundexTest gmock)
target_link_libraries(SoundexTest gtest)
target_link_libraries(SoundexTest Threads::Threads)
