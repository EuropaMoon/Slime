//
// Created by maximilian on 05.04.20.
//

/*
 * Represents a game field
 */

#ifndef TEST_PLAYFIELD_H
#define TEST_PLAYFIELD_H

#include <SFML/Graphics.hpp>
#include "Game.h"

class Playfield {
public:
    //constructor
    explicit Playfield(Game &game);

    //draw playfield
    void draw(Game &game);

private:
    sf::Texture playField;      //used to store pixel data on graphics card
    sf::Uint8 *pixels;          //stores every color values for every pixel
    sf::Sprite sprite;          //represents the texture
};

#endif //TEST_PLAYFIELD_H
