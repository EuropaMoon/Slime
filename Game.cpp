//
// Created by maximilian on 18.01.20.
//

#include "Game.h"
#include "MainMenuState.h"
#include "PlayState.h"

Game::Game() {
    window.create(sf::VideoMode(1200, 720), "Game");

    if (!font.loadFromFile("font.ttf")) {
        printf("Font not found!\n");
    } else {
        font.loadFromFile("font.ttf");
    }
    
    //Loading Textures
    for (const auto & i : texturePath) {
        if(!textures->loadFromFile(i)) {
            std::cout << "Missing Image : " << i << std::endl;
        }
    }
    
}

Game::~Game() {
    window.close();
}

void Game::Run() {

    ChangeState(gameStates::MAINMENU);

    //Main loop
    while (window.isOpen()) {
        currentState->HandleEvents(*this);
        currentState->Update(*this);
        currentState->Draw(*this);
    }
}

void Game::ChangeState(gameStates newState) {
    switch (newState) {
        case gameStates::MAINMENU:
            currentState = std::move(std::make_unique<MainMenuState>());
            break;
        case gameStates::PLAY:
            currentState = std::move(std::make_unique<PlayState>());
            break;
        case gameStates::CREATE:
            //currentState = std::move(std::unique_ptr<MainMenuState>(new MainMenuState));
            break;
    }
}