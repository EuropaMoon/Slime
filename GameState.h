//
// Created by maximilian on 18.01.20.
// Parent class for all Game states

#ifndef TEST_GAMESTATE_H
#define TEST_GAMESTATE_H

#include <SFML/Window/Event.hpp>

class Game;

class GameState {
public:
    virtual void HandleEvents(Game& game) = 0;
    virtual void Update(Game& game) = 0;
    virtual void Draw(Game& game) = 0;
    virtual ~GameState() {};

protected:
    sf::Event event;
};

#endif //TEST_GAMESTATE_H
