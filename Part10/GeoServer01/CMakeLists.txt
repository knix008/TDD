project(GeoServer)
cmake_minimum_required(VERSION 3.16)

include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib) 
add_definitions(-g -std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources 
   GeoServer.cpp
   Location.cpp)

set(testSources 
   CppUTestExtensions.cpp
   CppUTestExtensionsTest.cpp
   GeoServerTest.cpp
   LocationTest.cpp)

add_executable(Test testmain.cpp ${testSources} ${sources})
target_link_libraries(Test CppUTest)