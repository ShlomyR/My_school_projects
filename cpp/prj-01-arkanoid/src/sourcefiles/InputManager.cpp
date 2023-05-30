#include "../hederfiles/InputManager.hpp"
#include "../hederfiles/GameState.hpp"
#include "../hederfiles/Hud.hpp"
#include "../hederfiles/Menu.hpp"
#include "../hederfiles/Paddle.hpp"
#include "../hederfiles/HighScoreManager.hpp"

bool InputManager::isKeyPressed(sf::Keyboard::Key key) const
{
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

    while (window.pollEvent(m_event)) {
        switch (m_event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                m_pressedKeys.insert(m_event.key.code);
                break;
            case sf::Event::KeyReleased:
                m_releasedKeys.insert(m_event.key.code);
                break;
            case sf::Event::MouseButtonPressed:
                m_pressedMouseButtons.insert(m_event.mouseButton.button);
                break;
            case sf::Event::MouseButtonReleased:
                m_releasedMouseButtons.insert(m_event.mouseButton.button);
                break;
            case sf::Event::MouseMoved:
                m_mousePosition = window.mapPixelToCoords(sf::Vector2i(m_event.mouseMove.x, m_event.mouseMove.y));
                break;
            default:
                break;
        }
    }
}

void InputManager::handleInput(sf::RenderWindow &window,GameState &gameState, Paddle &paddle, Menu &menu, InputManager& inputManager)
{
    inputManager.pollEvent(window);
    menu.handleInput(inputManager);
    //high_score_manager.updateHighScore(m_event);
    if (inputManager.isKeyPressed(sf::Keyboard::Escape)) {
        if (menu.getIsMenuShown()) {
            window.close();
        } else {
            menu.setIsMenuShown(true);
            //reset();
        }
    } else if (inputManager.isKeyPressed(sf::Keyboard::Space)) {
        paddle.setIsPressed(true);
        // Testing
    } else if (inputManager.isKeyPressed(sf::Keyboard::Q)) {
        gameState.decreaseHealth();
        gameState.decreaseHealth();
        gameState.decreaseHealth();
        gameState.decreaseHealth();
    }

}

sf::Event &InputManager::getLastEvent()
{
    return m_event;
}