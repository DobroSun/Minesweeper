cmake_minimum_required(VERSION 3.5)
project(minesweeper)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")

find_package(SDL2 REQUIRED)
# FIXME:
# Doesn't work without FindSDL2_image.cmake
find_package(SDL2_image REQUIRED) 
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


add_subdirectory(src)

add_executable(
	main
		src/main.cpp
)

target_link_libraries(main lib ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
