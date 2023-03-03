project(foundations)
cmake_minimum_required(VERSION 2.6)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_definitions(-std=c++0x)
find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(sources main.cpp RetweetCollectionTest.cpp)

add_executable(test ${sources})

target_link_libraries(test gmock)
target_link_libraries(test gtest)
target_link_libraries(test Threads::Threads)