//
// Created by maximilian on 18.01.20.
//

#include "MainMenuState.h"
#include "Game.h"

MainMenuState::MainMenuState() {
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(100, 100);
    circle.setRadius(10);

    text.setCharacterSize(12);
    text.setPosition(sf::Vector2f(100,100));
    text.setFillColor(sf::Color::White);
    text.setString("MainMenuState");
}

MainMenuState::~MainMenuState() {
    printf("MainMenu destroyed\n");
}

void MainMenuState::HandleEvents(Game &game) {
    while (game.window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game.window.close();
        }
    }
}

void MainMenuState::Update(Game &game) {
    if (text.getFont() == nullptr) {
        text.setFont(game.font);
    }

    if (sf::Mouse::getPosition(game.window).x > 600) {
        game.ChangeState(Game::gameStates::PLAY);
    }
}

void MainMenuState::Draw(Game &game) {
    game.window.clear();

    game.window.draw(circle);
    game.window.draw(text);

    game.window.display();
}