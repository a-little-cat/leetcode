aux_source_directory(./src SRC)
add_library(leetcode ${SRC})
target_include_directories(leetcode PUBLIC ./inc)
