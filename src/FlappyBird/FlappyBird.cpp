//
// Created by Taisiia Nekrasova on 26/02/2024.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "FlappyBird.h"

FlappyBird::FlappyBird() {
    // Setup the game window
    window.create(sf::VideoMode(800, 600), "Flappy Bird Clone", sf::Style::Close);
    window.setFramerateLimit(60);

    // Initialize game state
    isGameOver = false;


    background = std::make_unique<Background>();
    bird = std::make_unique<Bird>();
    pipe = std::make_unique<Pipe>();
}

void FlappyBird::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        processEvents();
        if (!isGameOver) {
            update(deltaTime);
        }
        render();
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

void FlappyBird::update(sf::Time deltaTime) {
    bird->update();
    pipe->update();

    // Check for collisions
    if (checkCollision()) {
        isGameOver = true;
    }

    static sf::Time timeSinceLastPipe = sf::Time::Zero;
    timeSinceLastPipe += deltaTime;
    if (timeSinceLastPipe > sf::seconds(2.0)) {
        float pipeX = window.getSize().x;
        float pipeY = rand() % (window.getSize().y - 200);
        pipe->addPipe(pipeX, pipeY);
        timeSinceLastPipe = sf::Time::Zero;
    }
}

bool FlappyBird::checkCollision() {
    // collision detection between bird and pipes
    return false;
}

void FlappyBird::render() {
    window.clear();
    background->draw(window);
    pipe->draw(window);
    bird->draw(window);
    window.display();
}

