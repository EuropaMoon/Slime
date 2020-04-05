//
// Created by maximilian on 18.01.20.
// Handles the Play state

#ifndef TEST_PLAYSTATE_H
#define TEST_PLAYSTATE_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

class PlayState : public GameState {
public:
    PlayState();
    ~PlayState();

    void HandleEvents(Game& game) override;
    void Update(Game& game) override;
    void Draw(Game& game) override;

private:
    sf::CircleShape circle;
    sf::Text text;
};

#endif //TEST_PLAYSTATE_H
