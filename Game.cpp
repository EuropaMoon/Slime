//
// Created by maximilian on 18.01.20.
//

#include "Game.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "Playground.h"

Game::Game() {

    //create buffer to store infos
    char buffer[100] = "";

    //Loading settings file
    info.open("settings");
    //Check if settings file is loaded
    if (!info) {
        std::cout << "Missing settings file" << std::endl;
    }

    //create to store the VideoMode for Window
    sf::VideoMode videoMode;
    //searching through the settings file for game settings
    for (int j = 0; info.getline(buffer, 100); j++) {
        //transforming the char array into a string
        std::string sInfo = std::string(buffer);

        //searching for the resolution setting
        if (sInfo.substr(0, sInfo.find_first_of(':')) == "resolution") {
            //saving the width and height for the window
            videoMode.width = std::stoi(sInfo.substr(sInfo.find_first_of(':') + 1, sInfo.find_first_of('x')));
            videoMode.height = std::stoi(sInfo.substr(sInfo.find_first_of('x') + 1, sInfo.find_first_of('\n')));
        }

        //searching for the font setting
        if (sInfo.substr(0, sInfo.find_first_of(':')) == "font") {
            //saving the font
            if (!font.loadFromFile("fonts/" + sInfo.substr(sInfo.find_first_of(':') + 1, sInfo.find_first_of('\n')))) {
                printf("Font not found!\n");
            }
        }
    }

    //Close settings file
    info.close();

    //creating the game window
    window.create(videoMode, "Game");

    //Loading infos for Game objects
    info.open("Objects/Info");
    //Check if info file is loaded
    if (!info) {
        std::cout << "Missing info file" << std::endl;
    }

    //Loading Textures
    for (int i = 0; info.getline(buffer, 100); i++) {
        //Load and check if Image gets loaded
        textures.resize(i + 1);
        if (!textures[i].loadFromFile("textures/" + std::string(buffer) + ".png")) {
            std::cout << "Missing Image : " << std::string(buffer) << " in folder textures" << std::endl;
        }
    }
    //Close info file
    info.close();
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
            currentState = std::move(std::make_unique<MainMenuState>(*this));
            break;
        case gameStates::PLAY:
            currentState = std::move(std::make_unique<PlayState>());
            break;
        case gameStates::PLAYGROUND:
            currentState = std::move(std::make_unique<Playground>(*this));
            break;
    }
}