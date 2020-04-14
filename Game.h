//
// Created by maximilian on 18.01.20.
// The Game class handles the main loop and switches between GameStates

#ifndef TEST_GAME_H
#define TEST_GAME_H

#include "GameState.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <fstream>

class Game {
public:
    Game();
    ~Game();

    enum class gameStates { MAINMENU, PLAY, PLAYGROUND };

    void Run();
    void ChangeState(gameStates newState);

    sf::RenderWindow window;
    sf::Font font;
    std::vector<sf::Texture> textures;

private:
    std::unique_ptr<GameState> currentState;
    std::ifstream info;
};

#endif //TEST_GAME_H
