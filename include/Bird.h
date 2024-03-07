#ifndef HERO_OF_THE_ARCADE_BIRD_H
#define HERO_OF_THE_ARCADE_BIRD_H
#include <SFML/Graphics.hpp>

#include <SFML/Graphics.hpp>

class Bird {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    float gravity;
    float movementSpeed;
    float jumpHeight;

public:
    Bird();
    void update(float deltaTime);
    void flap();
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;

};


#endif //HERO_OF_THE_ARCADE_BIRD_H
