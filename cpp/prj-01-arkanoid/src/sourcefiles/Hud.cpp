#include "../hederfiles/Hud.hpp"
#include "../hederfiles/HighScoreManager.hpp"

void Hud::update(int score, int health, int highScore,Hud&)
{
    m_scoreText.setString("Score: " + std::to_string(score));
    m_healthText.setString("Health: " + std::to_string(health));
    m_gameOverText.setString("Game over!");
    m_highScoreText.setString("High Score: " + std::to_string(highScore));
    m_enterNameText.setString("Please enter your name: ");
    //m_inputFieldText.setString("P: mjbkbkbnmbb n");
}

void Hud::draw(sf::RenderWindow &window, GameState &m_game_state, HighScoreManager &high_score_manager)
{
    //if (high_score_manager.getIsHighScoreShown()) {
        window.draw(m_inputFieldText);
    //} else {
        window.draw(m_scoreText);
        window.draw(m_healthText);
        if (m_game_state.getHealth() == 0) {
            window.draw(m_gameOverText); 
        }
        window.draw(m_highScoreText);
        //if (m_game_state.getHealth() == 0) {
            window.draw(m_enterNameText);
        //}
    //}
}

const sf::Font Hud::getFont() const
{
    return m_font;
}

sf::Text &Hud::getInputFieldText()
{
    return m_inputFieldText;
}

void Hud::initFont()
{
    if (!m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf")) {
        throw std::runtime_error("Could not load the font in hud!!!");
    }
}

void Hud::makeText(sf::Text &text, sf::Font &font, std::string str, sf::Vector2i vec2i)
{
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setString(str);
    text.setPosition(vec2i.x,vec2i.y);
}