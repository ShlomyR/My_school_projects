#pragma once

#include <SFML/Graphics.hpp>

class Handler
{
public:
    Handler() = default;
    ~Handler() = default;

    void handleEvent(sf::Event& event);
    void draw();
    void logics(float,float);

private:
    std::vector<sf::Keyboard::Key> sequence {sf::Keyboard::A, sf::Keyboard::B, sf::Keyboard::C}; // define the sequence of keys
    bool sequenceMatched = false;
    size_t currentKeyIndex = 0;
};