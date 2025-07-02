cmake_minimum_required(VERSION 3.14)
project(algo_trader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

include(FetchContent)

find_package(cpr QUIET)
if (NOT cpr_FOUND)
  message(STATUS "CPR not found, using FetchContent")
  FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 1.10.4
  )
  FetchContent_MakeAvailable(cpr)
endif()

find_package(nlohmann_json QUIET)
if (NOT nlohmann_json_FOUND)
  message(STATUS "nlohmann_json not found, using FetchContent")
  FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
  )
  FetchContent_MakeAvailable(nlohmann_json)
endif()

set(SOURCES
  src/main.cpp
  src/logger.cpp
)

add_executable(algo_trader ${SOURCES})

target_link_libraries(algo_trader PRIVATE
  cpr::cpr
  nlohmann_json::nlohmann_json
)

target_compile_features(algo_trader PRIVATE cxx_std_23)

target_compile_options(algo_trader PRIVATE
  -Wall -Wextra -Wpedantic -Werror
)