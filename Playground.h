//
// Created by maximilian on 14.04.20.
//

/*
 * represents a game state to test development
 */

#ifndef TEST_PLAYGROUND_H
#define TEST_PLAYGROUND_H

#include "SFML/Graphics.hpp"
#include "GameState.h"
#include "Playfield.h"

class Playground : public GameState {
public:
    explicit Playground(Game &game);
    ~Playground() override;

    void HandleEvents(Game& game) override;
    void Update(Game& game) override;
    void Draw(Game& game) override;

private:
    Playfield playfield;    //represents the playfield

};

#endif //TEST_PLAYGROUND_H
