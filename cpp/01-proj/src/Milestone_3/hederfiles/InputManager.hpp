#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_set>

class InputManager {
public:
    InputManager() {};
    bool isKeyPressed(sf::Keyboard::Key key) const;
    bool isKeyReleased(sf::Keyboard::Key key) const;
    bool isMouseButtonPressed(sf::Mouse::Button button) const;
    bool isMouseButtonReleased(sf::Mouse::Button button) const;
    sf::Vector2f getMousePosition() const;
    void pollEvent(sf::RenderWindow& window);
private:
    std::unordered_set<sf::Keyboard::Key> m_pressedKeys;
    std::unordered_set<sf::Keyboard::Key> m_releasedKeys;
    std::unordered_set<sf::Mouse::Button> m_pressedMouseButtons;
    std::unordered_set<sf::Mouse::Button> m_releasedMouseButtons;
    sf::Vector2f m_mousePosition;
};