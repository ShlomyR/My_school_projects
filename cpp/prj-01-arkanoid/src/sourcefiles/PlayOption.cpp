#include "../hederfiles/PlayOption.hpp"

void PlayOption::draw(sf::RenderWindow& window)
{
    window.draw(m_playText);
}

bool PlayOption::handleInput(const InputManager& inputManager)
{
    if (m_playText.getGlobalBounds().contains(inputManager.getMousePosition())) {
        m_playText.setOutlineColor(sf::Color::Red);
        if (inputManager.isMouseButtonPressed(sf::Mouse::Left)) {
            m_isSelected = true;
            return true;
        }
    } else {
        m_isSelected = false;
        m_playText.setOutlineColor(sf::Color::White);
    }

    return false;
}


void PlayOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_playText.setString("PLAY");
    m_playText.setFont(m_font);
    m_playText.setCharacterSize(48);
    m_playText.setFillColor(sf::Color::White);
    m_playText.setOutlineThickness(2);
    m_playText.setOutlineColor(sf::Color::Black);
    m_playText.setPosition(sf::Vector2f(window.getSize().x / 2 - m_playText.getGlobalBounds().width / 2, window.getSize().y / 2 - 150));
}

bool PlayOption::isSelected() const
{
    return m_isSelected;;
}