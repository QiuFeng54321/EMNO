cmake_minimum_required(VERSION 3.14)
project(EMNO)

set(CMAKE_CXX_STANDARD 17)

include(CMake/FindZstd.cmake)

if (ZSTD_FOUND)
    message("Zstd library: ${ZSTD_LIBRARY}")
    message("Zstd include directory: ${ZSTD_INCLUDE_DIR}")
    include_directories(${ZSTD_INCLUDE_DIR})
endif ()

add_subdirectory(test)

include_directories(include)

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
message("Source Files are: ${SOURCE_FILES}")

include_directories(src/header)
include_directories(include)
link_directories(libs)

add_library(emno SHARED ${SOURCE_FILES})

target_link_libraries(emno ${ZSTD_LIBRARY})
