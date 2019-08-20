cmake_minimum_required(VERSION 3.14)
project(EMNO)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/header/*.hpp ${PROJECT_SOURCE_DIR}/src/definition/*.cpp)
message(Source Files are: ${SOURCE_FILES})

include_directories(include)
link_directories(libs)

add_executable(EMNO ${SOURCE_FILES})
