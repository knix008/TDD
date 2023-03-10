project(foundations)
cmake_minimum_required(VERSION 3.14)

include_directories($ENV{GMOCK_HOME}/include $ENV{GMOCK_HOME}/gtest/include)
link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild)
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)
target_link_libraries(test PRIVATE Threads::Threads)

set(sources 
    main.cpp 
    RetweetCollectionTest.cpp 
    RetweetCollection.cpp
    TweetTest.cpp
    Tweet.cpp)

add_executable(test ${sources})
target_link_libraries(test gmock)
target_link_libraries(test gtest)