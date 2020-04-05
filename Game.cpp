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

    //Loading infos for Game objects
    infoGameObjects.open("Objects/Info");
    //Check if info file id loaded
    if (!infoGameObjects) {
        std::cout << "Missing Info File" << std::endl;
    }

    //create buffer to store texture names
    char buffer[100] = "";

    //Loading Textures
    for (int i = 0; infoGameObjects.getline(buffer, 100); i++) {
        //Load and check if Image gets loaded
        textures.resize(i + 1);
        if (!textures[i].loadFromFile("textures/" + std::string(buffer) + ".png")) {
            std::cout << "Missing Image : " << std::string(buffer) << " in folder textures" << std::endl;
        }
    }
    //Closes info file
    infoGameObjects.close();
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