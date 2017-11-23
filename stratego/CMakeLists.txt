cmake_minimum_required(VERSION 3.8)
project(stratego)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES
        include/strategoTypes.h
        src/main.cpp
        src/renderable/Renderable.cpp
        src/Texture.cpp
        src/renderable/Piece.cpp
        src/PlayerMove.cpp
        src/Game.cpp
        src/renderable/Player.cpp
        src/renderable/Selection.cpp
        src/renderable/clickable/Clickable.cpp
        src/renderable/clickable/displayMatrix/DisplayMatrix.cpp
        src/renderable/clickable/displayMatrix/Board.cpp
        src/renderable/clickable/displayMatrix/PieceContainer.cpp
        src/renderable/clickable/Menu.cpp
        src/renderable/clickable/Button.cpp
        src/Resources.cpp)
add_executable(stratego ${SOURCE_FILES})
target_link_libraries(stratego ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})