#pragma once

#include<SFML/Graphics.hpp>

class Ball
{
public:
    explicit Ball(std::string path)
    :   m_path(path)
    {}
    void initBall();
    void initSprite(sf::RenderTarget* const);
    void updateBall();
    void renderBall(sf::RenderTarget* const);

    float getRandomDirection();
    sf::FloatRect getBounds();
    bool isPressed;
private:
    sf::Texture m_tBall;
    sf::Sprite m_sBall;
    sf::FloatRect m_ballBounds;
    std::string m_path;
    float m_dx; 
    float m_dy;
    unsigned int m_windowBoundWidth;
    unsigned int m_windowBoundHeight;
};