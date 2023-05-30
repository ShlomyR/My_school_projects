#include "../hederfiles/GameState.hpp"

GameState::GameState(int health, int level, int score, int high_score)
: m_health(health)
, m_level(level)
, m_score(score)
, m_high_score(high_score)
{

}

int GameState::getHealth() const {
    return m_health;
}

int GameState::getLevel() const {
    return m_level;
}

int GameState::getScore() const {
    return m_score;
}

int GameState::getHighScore() const
{
    return m_high_score;
}

State GameState::getState() const
{
    return currentState;
}

void GameState::setState(State state)
{
    currentState = state;
}

void GameState::setHighScore(size_t new_high_score)
{
    m_high_score = new_high_score;
}

void GameState::reset()
{
    currentState = State::Menu;
}

void GameState::decreaseHealth()
{
    --m_health;
}

void GameState::increaseScore() {
    m_score += 10;
}

void GameState::resetScore()
{
    m_score = 0;
}

void GameState::resetHealth()
{
    m_health = 5;
}

void GameState::nextLevel()
{
    ++m_level;
}