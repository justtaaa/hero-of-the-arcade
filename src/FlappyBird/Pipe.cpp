//
// Created by Taisiia Nekrasova on 26/02/2024.
//
#include "Pipe.h"


// Constructor initializes the pipe movement speed and loads the texture.
Pipe::Pipe() {

    if (!texture.loadFromFile("/Users/taisiianekrasova/CLionProjects/hero-of-the-arcade/resources/images/pipe.png")) {

    }
    sf::Sprite pipeSprite;
    pipeSprite.setTexture(texture);
    pipeSprite.setScale(0.5f, 0.5f);

    // Set the movement speed of pipes
    movementSpeed = -2.0f;
    gapHeight = 150.0f;
}

// Function to add a new pipe pair to the game
void Pipe::addPipe(float x, float y) {
    sf::Sprite pipeUp(texture);
    sf::Sprite pipeDown(texture);


    pipeUp.setPosition(x, y);
    pipeUp.setRotation(180.f);
    pipeUp.setScale(1, -1); // Invert the top pipe


    pipeDown.setPosition(x, y + gapHeight + texture.getSize().y);


    pipesUp.push_back(pipeUp);
    pipesDown.push_back(pipeDown);
}

// Function to move all pipes and remove them if they go off-screen
void Pipe::update() {
    for (size_t i = 0; i < pipesUp.size(); i++) {
        // Move each pipe pair to the left
        pipesUp[i].move(movementSpeed, 0);
        pipesDown[i].move(movementSpeed, 0);

        // If a pipe is off-screen, remove it from the vector
        if (pipesUp[i].getPosition().x < -texture.getSize().x) {
            pipesUp.erase(pipesUp.begin() + i);
            pipesDown.erase(pipesDown.begin() + i);
            i--;
        }
    }
}

// Function to draw the pipes on the window
void Pipe::draw(sf::RenderWindow& window) const {
    for (size_t i = 0; i < pipesUp.size(); ++i) {
        window.draw(pipesUp[i]);
        window.draw(pipesDown[i]);
    }
}



