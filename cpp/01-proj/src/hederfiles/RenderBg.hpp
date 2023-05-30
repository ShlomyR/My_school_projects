#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class RenderBg
{
public:
    void init();
    void initSprite();
    void render(std::unique_ptr<sf::RenderWindow> &);
private:
    sf::Texture t_background;
    sf::Sprite s_background;
};