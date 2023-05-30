#pragma once

#include "Rectangle.hpp"

class Paddle : public Rectangle
{
public:
    Paddle() = default;
    Paddle(const sf::Vector2f &, const sf::Vector2f &, const sf::Color &);
    ~Paddle() = default;

    void move(float, float) override;
    void setPosition(float, float) override;
    void draw(std::unique_ptr<WindowAdapter> &) override;
    sf::Vector2f getPosition() const override;
    float getRadius() const override;
    
    std::shared_ptr<sf::RectangleShape> &getShape();
    void setIsPressed(bool);
    bool getIsPressed();
private:
    std::shared_ptr<sf::RectangleShape> m_shape;
    bool is_pressed = false;
    bool m_paused = false;
};