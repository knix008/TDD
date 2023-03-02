project(FirstExample)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
find_package(Threads REQUIRED)

add_definitions(-std=c++14)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(sources 
   main.cpp 
   CharUtil.cpp
   StringUtil.cpp)
   
set(testSources
    CharUtilTest.cpp
    SoundexTest.cpp
    StringUtilTest.cpp)

add_executable(soundextest ${testSources} ${sources})
target_link_libraries(soundextest Threads::Threads)
target_link_libraries(soundextest gmock)
target_link_libraries(soundextest gtest)