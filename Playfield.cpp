//
// Created by maximilian on 05.04.20.
//

#include "Playfield.h"

Playfield::Playfield(Game &game) {

    //creat a array that stores the color information for every pixel
    pixels = new sf::Uint8[game.window.getSize().x * game.window.getSize().y * 4];
    //creat a texture
    playField.create(game.window.getSize().x, game.window.getSize().y);

    //color all pixel to a specific color
    for(int x = 0; x < game.window.getSize().x; x++) {
        for(int y = 0; y < game.window.getSize().y; y++) {
            pixels[(y * game.window.getSize().x + x) * 4]     = 255;          //Red
            pixels[(y * game.window.getSize().x + x) * 4 + 1] = 255;          //Green
            pixels[(y * game.window.getSize().x + x) * 4 + 2] = 255;          //Blue
            pixels[(y * game.window.getSize().x + x) * 4 + 3] = 255;          //Alpha
        }
    }
    //load pixel into the texture
    playField.update(pixels);

    //load texture into the sprite so it's a drawable
    sprite.setTexture(playField);
}

void Playfield::draw(Game &game) {
    //draw the sprite
    game.window.draw(sprite);
}