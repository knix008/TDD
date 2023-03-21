project(SnippetPublisher)
cmake_minimum_required(VERSION 3.16)

# For x86_64 Linux 
if (LINUX)
include_directories($ENV{BOOST_ROOT}/ $ENV{RLOG_HOME} $ENV{CPPUTEST_HOME}/include)
link_directories($ENV{RLOG_HOME}/rlog/.libs $ENV{CPPUTEST_HOME}/lib)
endif()

# For Apple Mac
if (APPLE)
include_directories($ENV{BOOST_ROOT}/ $ENV{RLOG_HOME} $ENV{CPPUTEST_HOME}/include /usr/local/include/)
link_directories(/usr/local/lib)
endif()

set(Boost_USE_STATIC_LIBS ON)
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Boost $ENV{BOOST_VERSION} COMPONENTS filesystem system)

add_subdirectory(rlog)
add_definitions(-std=c++0x)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -DRLOG_COMPONENT=debug -Wall")
set(sources WavReader.cpp WavDescriptor.cpp FileUtil.cpp StreamUtil.cpp)
set(testSources WavReaderTest.cpp)
add_executable(Test testmain.cpp FileUtilTest.cpp StreamUtilTest.cpp SnippetTest.cpp ${testSources} ${sources})
add_executable(SnippetPublisher main.cpp ${sources})

target_link_libraries(Test ${Boost_LIBRARIES})
target_link_libraries(Test CppUTest)
target_link_libraries(Test CppUTestExt)
target_link_libraries(Test Threads::Threads)
target_link_libraries(Test rlogStub)

target_link_libraries(SnippetPublisher ${Boost_LIBRARIES})
target_link_libraries(SnippetPublisher Threads::Threads)
target_link_libraries(SnippetPublisher rlog)
