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
    movementSpeed = -70.0f;
    gapHeight = 150.0f;
}

void Pipe::addPipe(float x, float y) {
    sf::Sprite pipeUp(texture);
    sf::Sprite pipeDown(texture);

    // Set the scale for the pipes
    float pipeScale = 0.5f;
    pipeUp.setScale(pipeScale, -pipeScale); // Inverting the top pipe
    pipeDown.setScale(pipeScale, pipeScale);

    pipeUp.setPosition(x, y - (texture.getSize().y * pipeScale));
    pipeDown.setPosition(x, y + gapHeight);

    pipesUp.push_back(pipeUp);
    pipesDown.push_back(pipeDown);
}


void Pipe::update(float deltaTime) {
    float scaledTextureWidth = texture.getSize().x * 1.0f;

    for (int i = 0; i < pipesUp.size(); ++i) {

        float moveDistance = movementSpeed * deltaTime;
        pipesUp[i].move(moveDistance, 0);
        pipesDown[i].move(moveDistance, 0);

        if (pipesUp[i].getPosition().x + scaledTextureWidth < 0) {
            pipesUp.erase(pipesUp.begin() + i);
            pipesDown.erase(pipesDown.begin() + i);
            --i; // Decrement i since the list size has been reduced
        }
    }
}

void Pipe::draw(sf::RenderWindow& window) const {
    for (size_t i = 0; i < pipesUp.size(); ++i) {
        window.draw(pipesUp[i]);
        window.draw(pipesDown[i]);
    }
}