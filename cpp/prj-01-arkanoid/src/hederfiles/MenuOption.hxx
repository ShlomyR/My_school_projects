#pragma once

#include <SFML/Graphics.hpp>

#include "InputManager.hpp"

class MenuOption {
public:
    virtual ~MenuOption() {}
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual bool handleInput(const InputManager& inputManager) = 0;
    virtual void makeButton(sf::RenderWindow&) = 0;
    virtual bool isSelected() const = 0;
protected:
    sf::Font m_font;
};