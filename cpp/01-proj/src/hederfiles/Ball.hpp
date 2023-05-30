#pragma once

#include<SFML/Graphics.hpp>
#include <memory>

#include "Interface.hxx"
#include "BallManager.hpp"
#include "Border.hpp"

class Ball : public Interface_grandson
{
public:
    explicit Ball(std::string path)
    :   m_path(path)
    {}
    void init(std::unique_ptr<sf::RenderWindow> &) override ;
    void initSprite(std::unique_ptr<sf::RenderWindow> &) override;
    void update(std::unique_ptr<sf::RenderWindow> &) override;
    void render(std::unique_ptr<sf::RenderWindow> &) override;
    //void deleteBrick();

    float getRandomDirection();
    sf::FloatRect getBounds();
private:
    sf::Texture m_tBall;
    sf::Sprite m_sBall;
    sf::FloatRect m_ballBounds;
    std::string m_path;
    // TODO singleton
    std::unique_ptr<BallManager> m_ball_manager = std::make_unique<BallManager>();
    std::unique_ptr<Border> m_border;
};