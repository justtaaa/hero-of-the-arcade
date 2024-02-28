//
// Created by Taisiia Nekrasova on 26/02/2024.
//
#include "Background.h"

Background::Background() {

    if (!texture.loadFromFile("/Users/taisiianekrasova/CLionProjects/hero-of-the-arcade/resources/images/bird-back.png")) {

    }

    sprite.setPosition(0, 0);
    sprite.setTexture(texture);
    sprite.setScale(
            float(window.getSize().x) / texture.getSize().x,
            float(window.getSize().y) / texture.getSize().y
    );
}

void Background::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

// Implement scrolling functionality
void Background::update() {
    // Move the background to the left to simulate scrolling
    sprite.move(-0.5, 0); // Adjust speed as necessary

    // If the background has moved a full width's distance, reset its position
    if (sprite.getPosition().x <= -texture.getSize().x) {
        sprite.setPosition(0, 0);
    }
}
