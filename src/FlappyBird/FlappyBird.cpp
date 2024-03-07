//
// Created by Taisiia Nekrasova on 26/02/2024.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "FlappyBird.h"

FlappyBird::FlappyBird() {
    // Setup the game window
    window.create(sf::VideoMode(800, 600), "Flappy Bird", sf::Style::Close);
    window.setFramerateLimit(60);

    // Initialize game state
    isGameOver = false;


    sf::Vector2u windowSize = window.getSize();
    background = std::make_unique<Background>(window.getSize(), -100.0f); // Negative speed for leftward scrolling
    bird = std::make_unique<Bird>();
    pipe = std::make_unique<Pipe>();

}

void FlappyBird::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        processEvents(); // Handle user input and window events
        update(deltaTime); // Update the game state
        render(); // Draw the current state of the game to the window
    }
}



void FlappyBird::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                bird->flap();
            }
        }
    }
}

void FlappyBird::update(float deltaTime) {
    // First, check if the game is over
    if (isGameOver) {
        return;
    }

    // Update the background with the scrolling effect
    background->update(deltaTime);

    // Update the bird's state with gravity and check for input to flap
    bird->update(deltaTime);

    // Update the pipes, moving them to the left
    pipe->update(deltaTime);

    // Check for collisions between the bird and the pipes
    if (checkCollision()) {
        isGameOver = true; // End the game if there's a collision
    }

    // Add new pipes at regular intervals
    static sf::Time timeSinceLastPipe = sf::Time::Zero;
    timeSinceLastPipe += sf::seconds(deltaTime);


    if (timeSinceLastPipe > sf::seconds(1.5f)) {
        float pipeX = window.getSize().x;
        float lowerY = window.getSize().y - 300.0f;

        pipe->addPipe(pipeX, lowerY);
        timeSinceLastPipe = sf::Time::Zero;
    }
}



bool FlappyBird::checkCollision() {
    sf::FloatRect birdBounds = bird->getBounds();
    std::vector<sf::FloatRect> pipeBounds = pipe->getPipeBounds();

    for (const auto& bound : pipeBounds) {
        if (birdBounds.intersects(bound)) {
            return true; // Collision detected
        }
    }

    return false; // No collision detected
}

void FlappyBird::render() {
    window.clear();
    background->draw(window);
    pipe->draw(window);
    bird->draw(window);
    window.display();
}

