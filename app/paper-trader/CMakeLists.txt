cmake_minimum_required(VERSION 3.14)

add_executable(paper_trader
    src/main.cpp
)

target_link_libraries(paper_trader
    PRIVATE
        common
        # core
        # broker
        # strategy
        # risk
)

target_compile_options(paper_trader PRIVATE
    -Wall -Wextra -Wpedantic -Werror
)