project(GeoServer)
cmake_minimum_required(VERSION 3.16)

# For x86_64 Linux 
if (LINUX)
include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib)
endif()

# For Apple Mac
if (APPLE)
include_directories(/usr/local/include/)
link_directories(/usr/local/lib)
endif()

find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib) 
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
