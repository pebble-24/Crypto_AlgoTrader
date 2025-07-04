cmake_minimum_required(VERSION 3.14)
project(algo_trader LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

add_subdirectory(external/cpr)
add_subdirectory(external/json)
add_subdirectory(external/googletest)

set(SOURCES
  src/main.cpp
  src/logger.cpp
  src/trader.cpp
  src/market_data.cpp
  src/secrets.cpp
  src/data_collector.cpp
  src/risk_manager.cpp
  src/brokers/alpaca.cpp
  src/strategies/strategy_smacrossover.cpp
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