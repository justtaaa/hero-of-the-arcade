//
// Created by Taisiia Nekrasova on 26/02/2024.
//
#include "Bird.h"
#include <SFML/Graphics.hpp>


Bird::Bird() {

    if (!texture.loadFromFile("/Users/taisiianekrasova/CLionProjects/hero-of-the-arcade/resources/images/flappy-bird.png")) {

    }

    // Set the texture for the bird sprite
    sprite.setTexture(texture);
    sprite.setScale(0.1f, 0.1f);

    position = sf::Vector2f(100, 200); // Starting position
    sprite.setPosition(position);
    gravity = 0.25f;
    movementSpeed = 0.0f;
    jumpHeight = -5.0f; // Negative because the y-axis is inverted
}

void Bird::update(float deltaTime) {
    // Apply gravity to the movement speed
    movementSpeed += gravity;
    position.y += movementSpeed;

    // Update the sprite's position
    sprite.setPosition(position);

    // Rotate the bird based on its movement speed
    if (movementSpeed < 0) {
        sprite.setRotation(-30.0f); // Angle upwards if moving up
    } else if (movementSpeed > 0) {
        sprite.setRotation(30.0f); // Angle downwards if falling
    }
}

void Bird::flap() {
    movementSpeed = jumpHeight;
}

void Bird::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::FloatRect Bird::getBounds() const {
    return sprite.getGlobalBounds();
}

