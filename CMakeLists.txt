cmake_minimum_required(VERSION 3.14)
project(algo_trader)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

include(FetchContent)

FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_TAG 1.10.4 # Latest as of mid-2025
)

FetchContent_MakeAvailable(cpr)

set(SOURCES
    src/main.cpp
    src/logger.cpp
)

add_executable(algo_trader ${SOURCES})

target_link_libraries(algo_trader PRIVATE cpr::cpr)