//
// Created by maximilian on 18.01.20.
// The Game class handles the main loop and switches between GameStates

#ifndef TEST_GAME_H
#define TEST_GAME_H

#include "GameState.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

#define TextureCount 3

class Game {
public:
    Game();
    ~Game();

    enum class gameStates { MAINMENU, PLAY, CREATE};

    void Run();
    void ChangeState(gameStates newState);

    sf::RenderWindow window;
    sf::Font font;
    sf::Texture textures[TextureCount];

private:
    std::unique_ptr<GameState> currentState;

    std::string texturePath[3] = { "/home/maximilian/Documents/CLion/Game/textures/Player.png",
                                   "/home/maximilian/Documents/CLion/Game/textures/Full_Block_Laboratory.png",
                                   "/home/maximilian/Documents/CLion/Game/textures/Corner_Block_Laboratory.png" };
};

#endif //TEST_GAME_H
