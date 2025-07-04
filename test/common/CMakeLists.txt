set(SOURCES
        test_common.cpp
)

add_executable(test_common
        ${SOURCES}
)

target_link_libraries(test_common
    PRIVATE
        common
        gtest_main
)

gtest_discover_tests(test_common)