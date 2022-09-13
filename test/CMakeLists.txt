find_package(GTest REQUIRED)

aux_source_directory(./src SRC)
add_executable(test ${SRC})
target_link_libraries(test PUBLIC leetcode ${GTEST_BOTH_LIBRARIES} -pthread)
