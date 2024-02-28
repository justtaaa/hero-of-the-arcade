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
    void update();
    void draw(sf::RenderWindow& window) const;
};


#endif //HERO_OF_THE_ARCADE_PIPE_H
