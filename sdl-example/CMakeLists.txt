cmake_minimum_required(VERSION 3.8)
project(SDLTest)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

set(SOURCE_FILES main.cpp Texture.cpp Texture.h SDLTest.cpp SDLTest.h)
add_executable(SDLTest ${SOURCE_FILES})

target_link_libraries(SDLTest ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})