//
// Created by Taisiia Nekrasova on 26/02/2024.
//

#ifndef HERO_OF_THE_ARCADE_BACKGROUND_H
#define HERO_OF_THE_ARCADE_BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background {
public:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RenderWindow window;
    float scrollSpeed;
    sf::Vector2f offset;

    Background(const sf::Vector2u& windowSize, float speed);
    void draw(sf::RenderWindow& window);
    void update(float deltaTime);
};


#endif //HERO_OF_THE_ARCADE_BACKGROUND_H
