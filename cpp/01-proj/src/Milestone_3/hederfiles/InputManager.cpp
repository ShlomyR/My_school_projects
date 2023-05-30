#include "../hederfiles/InputManager.hpp"



bool InputManager::isKeyPressed(sf::Keyboard::Key key) const {
    return m_pressedKeys.count(key) > 0;
}

bool InputManager::isKeyReleased(sf::Keyboard::Key key) const {
    return m_releasedKeys.count(key) > 0;
}

bool InputManager::isMouseButtonPressed(sf::Mouse::Button button) const {
    return m_pressedMouseButtons.count(button) > 0;
}

bool InputManager::isMouseButtonReleased(sf::Mouse::Button button) const {
    return m_releasedMouseButtons.count(button) > 0;
}

sf::Vector2f InputManager::getMousePosition() const {
    return m_mousePosition;
}

void InputManager::pollEvent(sf::RenderWindow& window) {
    m_pressedKeys.clear();
    m_releasedKeys.clear();
    m_pressedMouseButtons.clear();
    m_releasedMouseButtons.clear();

    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                m_pressedKeys.insert(event.key.code);
                break;
            case sf::Event::KeyReleased:
                m_releasedKeys.insert(event.key.code);
                break;
            case sf::Event::MouseButtonPressed:
                m_pressedMouseButtons.insert(event.mouseButton.button);
                break;
            case sf::Event::MouseButtonReleased:
                m_releasedMouseButtons.insert(event.mouseButton.button);
                break;
            case sf::Event::MouseMoved:
                m_mousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                break;
            default:
                break;
        }
    }
}