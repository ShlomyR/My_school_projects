#pragma once

#include <sstream>
#include "SymbolVar.hpp"
#include <SFML/Graphics.hpp>

struct Data{
    std::string name;
    int score;
};


class Information
{
public:
    explicit Information(const int score,const int highScore,const int health,const std::string path,const bool endGame = false)
    :   m_score(score)
    ,   m_highScore(highScore)
    ,   m_health(health)
    ,   m_path(path)
    ,   m_endGame(endGame)
    {}
    void setScore(const int);
    void setHighScore(const int);
    int setHealth(const int);
    int getScore();
    int getHealth();
    bool getEndGame();
    void decreaseHealth();
    void initFonts();
    void initTexts();
    void initVars();
    void updateTexts();
    void renderText(sf::RenderTarget *);
    void renderHighScore(sf::RenderTarget *);
    void increaseHealth();
    bool setEndGame(std::string);
    void setGameStart(const bool);
    void setNextLev(const bool);
    bool getGameOver();
    void setGameOver(bool);
    const std::vector<std::string> splitByWord(std::string const&,const char);
    int currScore();
    int oldScore();
    void initializeFile();
    void updateHighScore(sf::Event&);
    void makeText(
        sf::Text&,
        const sf::Font&,
        const sf::Color,
        const std::string
    );

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

    void updateText(
        std::stringstream&,
        sf::Text&,
        int,
        int,
        int,
        Texts
    );
    // std::unordered_map<std::string,std::string> creatDataBase(std::string key,std::string const&);

    std::string m_strName;
    std::string m_strScore;
    bool m_highScorePage;
    int m_givenScore;
private:
    int getHighScore();
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

    int m_score;
    int m_highScore;
    int m_highScoreMax;
    int m_health;
    std::string m_path;
    bool m_endGame;
    bool m_gameStart;
    bool m_nextLev;
    bool m_gameOver;
    int m_level;
    int m_counter;
    std::string m_givenName;

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
    Data data[10];
};