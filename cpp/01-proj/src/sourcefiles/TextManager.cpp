#include "../hederfiles/TextManager.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "TextManager.hpp"

TextManager *TextManager::getInstance()
{
    static TextManager m_instance;
    return &m_instance;
}

void TextManager::initVars()
{
    this->m_gameStart = true;
    this->m_nextLev = true;
    this->m_gameOver = false;
    this->m_highScorePage = false;
    this->m_counter = 0;
    this->m_score = 0;
    this->m_highScore = 0;
    this->m_health = 5;
    this->m_endGame = false;
    this->m_level = 1;
    this->m_path = "src/fonts/rexlia_rg.otf";
}

void TextManager::increaseScore()
{
    SymbolVar::getInstance()->map_doubleDB.at("score") = this->m_score += 10;
}

void TextManager::decreaseHealth()
{
    SymbolVar::getInstance()->map_doubleDB.at("health") = --(this->m_health);
}
