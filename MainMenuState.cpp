//
// Created by maximilian on 18.01.20.
//

#include "MainMenuState.h"
#include "Game.h"

MainMenuState::MainMenuState(Game &game) {
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(game.window.getSize().x / 2.f,game.window.getSize().y / 3.f);
    circle.setRadius(10);

    playStateButton.setCharacterSize(12);
    playStateButton.setPosition(sf::Vector2f(game.window.getSize().x / 2.f,game.window.getSize().y / 3.f));
    playStateButton.setFillColor(sf::Color::White);
    playStateButton.setString("Play State");

    playgroundButton.setCharacterSize(12);
    playgroundButton.setPosition(sf::Vector2f(game.window.getSize().x / 2.f,game.window.getSize().y / 2.f));
    playgroundButton.setFillColor(sf::Color::White);
    playgroundButton.setString("PlAYGROUND");
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
    if (playStateButton.getFont() == nullptr) {
        playStateButton.setFont(game.font);
        playgroundButton.setFont(game.font);
    }

    if (playStateButton.getGlobalBounds().contains(sf::Mouse::getPosition(game.window).x, sf::Mouse::getPosition(game.window).y)) {
        game.ChangeState(Game::gameStates::PLAY);
    }else if (playgroundButton.getGlobalBounds().contains(sf::Mouse::getPosition(game.window).x, sf::Mouse::getPosition(game.window).y)) {
        game.ChangeState(Game::gameStates::PLAYGROUND);
    }
}

void MainMenuState::Draw(Game &game) {
    game.window.clear();

    game.window.draw(circle);
    game.window.draw(playStateButton);
    game.window.draw(playgroundButton);

    game.window.display();
}