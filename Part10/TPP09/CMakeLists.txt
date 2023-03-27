project(SoundexTpp)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include)
link_directories(/usr/local/lib) 
add_definitions(-g -std=c++0x)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(testSources 
    SoundexTest.cpp)

add_executable(Test 
    testmain.cpp 
    ${testSources})

target_link_libraries(Test CppUTest)
