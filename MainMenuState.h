//
// Created by maximilian on 18.01.20.
// Handles the Main menu

#ifndef TEST_MAINMENUSTATE_H
#define TEST_MAINMENUSTATE_H

#include <SFML/Graphics.hpp>
#include "GameState.h"

class MainMenuState : public GameState {
public:
    MainMenuState();
    ~MainMenuState();

    void HandleEvents(Game& game) override;
    void Update(Game& game) override;
    void Draw(Game& game) override;

private:
    sf::CircleShape circle;
    sf::Text text;
};

#endif //TEST_MAINMENUSTATE_H
