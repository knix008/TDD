project(foundations)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_definitions(-std=c++14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(sources 
    main.cpp 
    #RetweetCollectionTest.cpp 
    RetweetCollection.cpp
    TweetTest.cpp
    Tweet.cpp)

add_executable(test ${sources})
target_link_libraries(test gmock)
target_link_libraries(test gtest)
target_link_libraries(test Threads::Threads)