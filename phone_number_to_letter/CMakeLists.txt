cmake_minimum_required(VERSION 2.8)
project(letter)
SET(CMAKE_BUILD_TYPE Debug)
aux_source_directory(. DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS})