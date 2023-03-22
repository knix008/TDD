project(GeoServer)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include/)
link_directories(/usr/local/lib)
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)
add_definitions(-g -std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources 
   Area.cpp
   GeoServer.cpp
   Location.cpp)

set(testSources 
   CppUTestExtensions.cpp
   CppUTestExtensionsTest.cpp
   TestTimer.cpp
   AreaTest.cpp
   GeoServerTest.cpp
   LocationTest.cpp
   ThreadPoolTest.cpp
   WorkTest.cpp)

add_executable(Test testmain.cpp ${testSources} ${sources})

target_link_libraries(Test CppUTest)
target_link_libraries(Test Threads::Threads)
