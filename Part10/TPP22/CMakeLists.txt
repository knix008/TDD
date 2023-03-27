project(NonTPP)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(sources 
   main.cpp 
   CharUtil.cpp
   StringUtil.cpp)
set(testSources
    CharUtilTest.cpp
    SoundexTest.cpp
    StringUtilTest.cpp)

add_executable(Test ${testSources} ${sources})

target_link_libraries(Test gmock)
target_link_libraries(Test gtest)
target_link_libraries(Test Threads::Threads)