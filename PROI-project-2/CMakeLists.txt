cmake_minimum_required(VERSION 3.5)
project(PROI_Course_3)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

file(GLOB SOURCES "src/*.cpp")

project(database_concept)

include_directories(include)

add_executable(zad-3 ${SOURCES} zad-3.cpp)

add_executable(zad-3-test ${SOURCES} test/test.cpp)
