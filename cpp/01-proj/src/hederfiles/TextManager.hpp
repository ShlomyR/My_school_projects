#pragma once

#include <string>

struct TextManager
{
    static TextManager *getInstance(); 
    void initVars();
    void increaseScore();
    void decreaseHealth();

    std::string m_path;
    int m_score;
    int m_highScore;
    int m_health;
    bool m_endGame;
    int m_level;

    bool m_gameStart;
    bool m_nextLev;
    bool m_gameOver;
    int m_counter;
    bool m_highScorePage;
};
