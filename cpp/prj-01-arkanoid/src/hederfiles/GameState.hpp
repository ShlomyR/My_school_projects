#pragma once

#include <iostream>

// #include "HighScoreManager.hpp"

enum class State{
    Menu = 0,
    High_Score,
    Exit,
};

class GameState {
public:
    GameState(int health, int level, int score, int high_score);

    int getHealth() const;
    int getLevel() const;
    int getScore() const;
    int getHighScore() const;

    State getState() const;
    void setState(State);

    void setHighScore(size_t);

    void reset();

    void decreaseHealth();
    void increaseScore();
    void resetScore();
    void resetHealth();
    void nextLevel();
private:
    int m_health;
    int m_level;
    int m_score;
    int m_high_score;

    State currentState = State::Menu;
};