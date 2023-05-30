#include "../hederfiles/BallManager.hpp"

void BallManager::init()
{
    this->isPressed = false;
    this->m_speed = 3.f;
    this->m_dx = m_speed;
    this->m_dy = -m_speed;
    this->m_windowBoundWidth = 5;
    this->m_windowBoundHeight = 3;
}