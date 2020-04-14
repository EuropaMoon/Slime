//
// Created by maximilian on 14.04.20.
//

#include "Playground.h"

Playground::Playground(Game &game) : playfield(game) {

}

Playground::~Playground() = default;

void Playground::HandleEvents(Game &game) {
    while (game.window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game.window.close();
        }
    }
}

void Playground::Update(Game &game) {

}

void Playground::Draw(Game &game) {
    //clear window
    game.window.clear();

    //drew playfield
    playfield.draw(game);

    //display window
    game.window.display();
}