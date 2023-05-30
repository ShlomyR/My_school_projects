#pragma once

struct BallManager
{
    void init();
    bool isPressed;
    float m_speed;
    float m_dx;
    float m_dy;
    unsigned int m_windowBoundWidth;
    unsigned int m_windowBoundHeight;
};