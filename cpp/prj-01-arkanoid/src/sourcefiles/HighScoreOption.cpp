#include "../hederfiles/HighScoreOption.hpp"

void HighScoreOption::draw(sf::RenderWindow &window)
{
    window.draw(m_highScoreText);   
}

bool HighScoreOption::handleInput(const InputManager& inputManager)
{
    if (m_highScoreText.getGlobalBounds().contains(inputManager.getMousePosition())) {
        m_highScoreText.setOutlineColor(sf::Color::Red);
        if (inputManager.isMouseButtonPressed(sf::Mouse::Left)) {
            m_isSelected = true;
            return true;
        }
    } else {
        m_isSelected = false;
        m_highScoreText.setOutlineColor(sf::Color::White);
    }
    
    return false;
}

void HighScoreOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_highScoreText.setString("HIGH SCORE");
    m_highScoreText.setFont(m_font);
    m_highScoreText.setCharacterSize(48);
    m_highScoreText.setFillColor(sf::Color::White);
    m_highScoreText.setOutlineThickness(2);
    m_highScoreText.setOutlineColor(sf::Color::Black);
    m_highScoreText.setPosition(sf::Vector2f(window.getSize().x / 2 - m_highScoreText.getGlobalBounds().width / 2, window.getSize().y / 2 - 50));
}

inline bool HighScoreOption::isSelected() const
{
    return m_isSelected;;
}
