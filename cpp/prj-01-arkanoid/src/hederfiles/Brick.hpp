#pragma once

#include "Rectangle.hpp"
// #include "WindowManager.hpp"

#include <vector>

class Brick : public Rectangle
{
public:
    Brick() = default;
    Brick(const sf::Vector2f &, const sf::Vector2f &, const sf::Color &);
    ~Brick() = default;
    static const int ROW_COUNT = 5;
    static const int COLUMN_COUNT = 3;

    void move(float, float) override;
    void setPosition(float, float) override;
    void draw(sf::RenderWindow &) override;
    sf::Vector2f getPosition() const override;
    float getRadius() const override;
    
    std::vector<sf::RectangleShape> getVecBricks();
    std::unique_ptr<sf::RectangleShape> &getShape();
    void pushToVec(sf::RectangleShape);

    void createRowOfBricks();
    void init();

    bool getIsDestroyed() const;
    void setIsDestroyed(bool destroyed);

    void deleteBrick(int);
    sf::RectangleShape getBrick(int);
    bool isEmpty();
private:
    bool m_isDestroyed;
    std::unique_ptr<sf::RectangleShape> m_shape;
    std::vector<sf::RectangleShape> m_bricks;
    std::vector<sf::Vector2i> m_hitBricks;
};