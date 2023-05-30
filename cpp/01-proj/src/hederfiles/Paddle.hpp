#pragma once

#include <SFML/Graphics.hpp>

#include "Interface.hxx"

class Paddle : public Interface_grandson
{
public:
    Paddle(std::string path);
    ~Paddle() = default;
    void init(std::unique_ptr<sf::RenderWindow> &) override ;
    void initSprite(std::unique_ptr<sf::RenderWindow> &) override;
    void update(std::unique_ptr<sf::RenderWindow> &) override;
    void render(std::unique_ptr<sf::RenderWindow> &) override;
    void left();
    void right();
    const sf::FloatRect getBounds() const;
    sf::Sprite& getSprite();
private:
    const sf::Vector2f& getPos() const;
private:
    sf::Sprite m_sPaddle;
    sf::Texture m_tPaddle;
};