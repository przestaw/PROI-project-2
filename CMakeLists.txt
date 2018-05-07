cmake_minimum_required(VERSION 3.5)
project(PROI_Course_3)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-std=c++11 -O3 -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

file(GLOB SOURCES "src/*.cpp")

project(database_concept)

include_directories(include)

add_library(Theater ${SOURCES})

add_executable(zad-3-test test/test.cpp)

target_link_libraries(zad-3-test Theater)

add_executable(zad-3 zad-3.cpp)

target_link_libraries(zad-3 Theater)
