#pragma once

#include <sstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "TextManager.hpp"

class Text
{
public:
    enum Texts {
        health_Score = 0,
        game_over,
        level,
        space_bar,
        high_score,
        high_names,
        high_scores,
        input
    };
    void init();
    void initFonts();
    void renderText(std::unique_ptr<sf::RenderWindow> &);
    void update();

public:
    void updateText(
        std::stringstream&,
        sf::Text&,
        int,
        int,
        int,
        Texts
    );
    void makeText(
        sf::Text&,
        const sf::Font&,
        const sf::Color,
        const std::string
    );

    // make Text
    void gameOverTextLogic(
        std::stringstream&,
        sf::Text&,
        int,
        int,
        int
    );

    void levelTextLogic(
        std::stringstream&,
        sf::Text&
    );

    void spaceBarTextLogic(
        std::stringstream&,
        sf::Text&
    );
    void scoreNameTextLogic(
        sf::Text&
    );

    void scoreScoresTextLogic(
        sf::Text&
    );
    sf::Font m_font;
    sf::Text m_healthScoreText;
    sf::Text m_gameOverText;
    sf::Text m_currLevelText;
    sf::Text m_spaceBarText;
    sf::Text m_highScoreText;
    sf::Text m_scoresText;
    sf::Text m_scoresText_2;
    sf::Text m_instructionsText;
    sf::Text m_inputField;

    //std::unique_ptr<TextManager> m_text_manager = std::make_unique<TextManager>();    
};
    // read file

    // struct Data{
    //     std::string name;
    //     int score;
    // };
    // Data data[10];
    // std::string m_givenName;
    // int m_givenScore;
    // std::string m_strName;
    // std::string m_strScore;

    // state of game

    // bool m_gameStart;
    // bool m_nextLev;
    // bool m_gameOver;
    // int m_level;
    // int m_counter;
    // bool m_highScorePage;