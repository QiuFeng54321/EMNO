cmake_minimum_required(VERSION 3.14)
project(EMNO_test)

set(CMAKE_CXX_STANDARD 17)

include_directories(../include)
link_libraries(emno)

add_executable(emno-test test_header.cpp)