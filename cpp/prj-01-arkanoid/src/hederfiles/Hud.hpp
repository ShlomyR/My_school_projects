#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "GameState.hpp"
class HighScoreManager;


class Hud {
public:
    Hud(sf::RenderWindow& window)
    : m_window(window)
    {
        initFont();
        makeText(m_scoreText,m_font,"Score: ",sf::Vector2i(10,10));
        makeText(m_healthText,m_font,"Health: ",sf::Vector2i(window.getSize().x -150, 10));
        makeText(m_gameOverText,m_font,"Game over: ",sf::Vector2i(window.getSize().x / 2.f - 100,window.getSize().y / 2.f));
        makeText(m_highScoreText,m_font,"High Score: ",sf::Vector2i(window.getSize().x - 500, 10));
        makeText(m_enterNameText,m_font,"Please enter your name: ",sf::Vector2i(window.getSize().x -600, 30));
        //makeText(m_inputFieldText,m_font,"Pjkbhjkbk: ",sf::Vector2i(window.getSize().x -550, 50));
    }

    void update(int,int,int,Hud&);
    void draw(sf::RenderWindow &,GameState &, HighScoreManager &);
    const sf::Font getFont() const;
    sf::Text &getInputFieldText();
private:
    void initFont();
    void makeText(sf::Text&,sf::Font&,std::string,sf::Vector2i);
private:
    sf::RenderWindow& m_window;
    sf::Font m_font;
    sf::Text m_scoreText;
    sf::Text m_healthText;
    sf::Text m_gameOverText;
    sf::Text m_highScoreText;
    sf::Text m_enterNameText;
    sf::Text m_inputFieldText;
};
