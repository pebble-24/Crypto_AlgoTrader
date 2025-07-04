cmake_minimum_required(VERSION 3.14)

project(common LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# TODO Replace this with specific files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_library(common STATIC ${SOURCES})

target_include_directories(common
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(common PRIVATE
    -Wall -Wextra -Wpedantic -Werror
)