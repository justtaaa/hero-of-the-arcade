//
// Created by Taisiia Nekrasova on 26/02/2024.
//

#ifndef HERO_OF_THE_ARCADE_FLAPPYBIRD_H
#define HERO_OF_THE_ARCADE_FLAPPYBIRD_H

#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Pipe.h"
#include "Bird.h"

class FlappyBird {
private:
    sf::RenderWindow window;
    std::unique_ptr<Background> background;
    std::unique_ptr<Bird> bird;
    std::unique_ptr<Pipe> pipe;
    bool isGameOver;

public:
    FlappyBird();
    void run();
    void processEvents();
    void update(float deltaTime);
    bool checkCollision();
    void render();
};


#endif //HERO_OF_THE_ARCADE_FLAPPYBIRD_H
