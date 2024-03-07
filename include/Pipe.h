//
// Created by Taisiia Nekrasova on 26/02/2024.
//

#ifndef HERO_OF_THE_ARCADE_PIPE_H
#define HERO_OF_THE_ARCADE_PIPE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Pipe {
private:
    sf::Texture texture;
    std::vector<sf::Sprite> pipesUp;
    std::vector<sf::Sprite> pipesDown;
    float movementSpeed;
    float gapHeight;

public:
    Pipe();
    void addPipe(float x, float y);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;
    std::vector<sf::FloatRect> getPipeBounds() const {
        std::vector<sf::FloatRect> bounds;
        for (const auto& pipe : pipesUp) {
            bounds.push_back(pipe.getGlobalBounds());
        }
        for (const auto& pipe : pipesDown) {
            bounds.push_back(pipe.getGlobalBounds());
        }
        return bounds;
    }
};


#endif //HERO_OF_THE_ARCADE_PIPE_H
