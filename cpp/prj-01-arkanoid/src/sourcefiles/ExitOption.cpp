#include "../hederfiles/ExitOption.hpp"

void ExitOption::draw(sf::RenderWindow& window)
{
    window.draw(m_exitText);
}

bool ExitOption::handleInput(const InputManager& inputManager)
{
    if (m_exitText.getGlobalBounds().contains(inputManager.getMousePosition())) {
        m_exitText.setOutlineColor(sf::Color::Red);
        if (inputManager.isMouseButtonPressed(sf::Mouse::Left)) {
            m_isSelected = true;
            return true;
        }
    } else {
        m_isSelected = false;
        m_exitText.setOutlineColor(sf::Color::White);
    }
    
    return false;
}

void ExitOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_exitText.setString("EXIT");
    m_exitText.setFont(m_font);
    m_exitText.setCharacterSize(48);
    m_exitText.setFillColor(sf::Color::White);
    m_exitText.setOutlineThickness(2);
    m_exitText.setOutlineColor(sf::Color::Black);
    m_exitText.setPosition(sf::Vector2f(window.getSize().x / 2 - m_exitText.getGlobalBounds().width / 2, window.getSize().y / 2 + 50));
}

inline bool ExitOption::isSelected() const
{
    return m_isSelected;;
}
