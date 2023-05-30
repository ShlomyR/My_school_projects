#pragma once

#include <SFML/Graphics.hpp>

class Paddle
{
public:
    explicit Paddle(std::string path);
    void initSprite(sf::RenderTarget* const);
    void renderPaddle(sf::RenderTarget* const);
    void updatePaddle(sf::RenderTarget* const);
    const sf::FloatRect getBounds() const;
    sf::Sprite& getSprite();
private:
    const sf::Vector2f& getPos() const;
private:
    sf::Sprite m_sPaddle;
    sf::Texture m_tPaddle;
};