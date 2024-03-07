//
// Created by Taisiia Nekrasova on 26/02/2024.
//
#include "Background.h"

Background::Background(const sf::Vector2u& windowSize, float speed)
        : scrollSpeed(speed), offset(0, 0) {

    if (!texture.loadFromFile("/Users/taisiianekrasova/CLionProjects/hero-of-the-arcade/resources/images/bird-back.png")) {
        throw std::runtime_error("Failed to load background texture");
    }

    /*sprite.setPosition(0, 0);
    sprite.setTexture(texture);
    sprite.setScale(
            float(window.getSize().x) / texture.getSize().x,
            float(window.getSize().y) / texture.getSize().y
    );*/
    sf::Vector2u textureSize = texture.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    sprite.setScale(scaleX, scaleY);


    texture.setRepeated(true); // Enable texture repeating
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, windowSize.x, windowSize.y)); // Use the window size here
}


void Background::draw(sf::RenderWindow& window)  {
    window.draw(sprite);
}

// Implement scrolling functionality
/*void Background::update(float deltaTime) {
    // Move the offset by scrollSpeed every update call
    offset.x += scrollSpeed * deltaTime;

    // Reset the offset if it goes beyond the texture's width
    if (offset.x > texture.getSize().x) {
        offset.x -= texture.getSize().x;
    }

    // Update the texture rect of the sprite to create the scrolling effect
    sprite.setTextureRect(sf::IntRect(offset.x, offset.y, 800, 600));
}*/

void Background::update(float deltaTime) {
    // Update the offset based on the scroll speed and the elapsed time
    offset.x += scrollSpeed * deltaTime;

    // Wrap around the texture to create a continuous scrolling effect
    if (offset.x > texture.getSize().x) {
        offset.x -= texture.getSize().x;
    } else if (offset.x < 0) {
        offset.x += texture.getSize().x;
    }

    // Apply the offset to the texture rect for the scrolling effect
    sprite.setTextureRect(sf::IntRect(offset.x, 0, sprite.getTextureRect().width, sprite.getTextureRect().height));
}
