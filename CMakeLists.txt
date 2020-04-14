cmake_minimum_required(VERSION 3.15)
project(test)

set(CMAKE_CXX_STANDARD 20)

add_executable(test main.cpp GameState.h Game.h Game.cpp MainMenuState.cpp MainMenuState.h PlayState.h PlayState.cpp
               Playfield.cpp Playfield.h Playground.cpp Playground.h)

target_link_libraries(test sfml-graphics sfml-window sfml-system)