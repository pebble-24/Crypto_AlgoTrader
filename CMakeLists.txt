cmake_minimum_required(VERSION 3.14)
project(algo_trader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/cpr)
add_subdirectory(external/json)
add_subdirectory(external/googletest)

# Internal Libraries
add_subdirectory(lib)

# Applications
add_subdirectory(app/live-trader)
add_subdirectory(app/paper-trader)
add_subdirectory(app/cli-backtester)

# Tests
add_subdirectory(test)