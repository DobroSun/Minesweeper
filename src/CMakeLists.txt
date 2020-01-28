cmake_minimum_required(VERSION 3.5)

add_library(
    lib STATIC
        board.cpp
        cell.cpp
        utils.cpp
)

target_include_directories(
    lib PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
