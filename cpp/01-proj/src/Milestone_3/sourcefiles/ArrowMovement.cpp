#include "../hederfiles/ArrowMovement.hpp"

ArrowMovement::ArrowMovement(std::shared_ptr<Paddle> &rectangle, float moveSpeed)
:    m_rectangle(rectangle)
,    m_moveSpeed(moveSpeed)
{}

void ArrowMovement::moveLeft()
{
    m_rectangle->move(-m_moveSpeed, 0);
}

void ArrowMovement::moveRight()
{
    m_rectangle->move(m_moveSpeed, 0);
}
