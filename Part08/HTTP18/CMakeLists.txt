project(HTTP)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include /usr/local/include/gtest /usr/local/include/gmock)
link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GMOCK_HOME}/gtest/mybuild $ENV{JSONCPP_HOME}/libs $ENV{CURL_HOME}/build/lib)
add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

set(sources 
   main.cpp 
   #CurlHttpTest.cpp 
   CurlHttp.cpp
   HttpFactory.cpp
   #AddressExtractorTest.cpp 
   AddressExtractor.cpp
   #OutParameterTest.cpp
   PlaceDescriptionServiceTest.cpp)

add_executable(test ${sources})
target_link_libraries(test gmock)
target_link_libraries(test gtest)
target_link_libraries(test jsoncpp)
target_link_libraries(test curl)
target_link_libraries(test Threads::Threads)
