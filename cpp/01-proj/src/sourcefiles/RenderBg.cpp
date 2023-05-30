#include "../hederfiles/RenderBg.hpp"

void RenderBg::init()
{
    this->t_background.loadFromFile("src/images/wallpapersden.com_colorful-space_800x600.jpg");
}

void RenderBg::initSprite()
{
    this->s_background.setTexture(this->t_background);
}

void RenderBg::render(std::unique_ptr<sf::RenderWindow> &target)
{
    target->draw(this->s_background);
}
