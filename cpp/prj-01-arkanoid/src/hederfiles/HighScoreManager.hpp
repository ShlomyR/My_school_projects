#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include "Hud.hpp"

class HighScoreManager 
{
public:
    HighScoreManager();
    void updateHighScore(sf::Event&, size_t,Hud &);

    void updateHighScoreToFile(size_t);
    size_t getFirstHighScore();
    std::string &getStringName();
    sf::Text &getInputString();
    void setIsHighScoreShown(bool);
    bool getIsHighScoreShown();
    void drew(sf::RenderWindow &);

private:
    void scoreScoresTextLogic();
    void scoreNameTextLogic();
    void initializeFile();
    struct ScoreData {
        std::string name;
        int score;
    } data[10];
private:
    sf::Text m_titleText;
    sf::Text m_scoreText;

    sf::Text m_inputField;
    std::string m_givenName;
    std::string m_strName;

    int m_givenScore;
    int m_counter;
    bool m_isHighScoreShown = false;
};
