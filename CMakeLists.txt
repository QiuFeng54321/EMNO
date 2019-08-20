cmake_minimum_required(VERSION 3.14)
project(EMNO)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

include_directories(include)

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
message("Source Files are: ${SOURCE_FILES}")

include_directories(src/header)
include_directories(include)
link_directories(libs)

add_library(emno SHARED ${SOURCE_FILES})
