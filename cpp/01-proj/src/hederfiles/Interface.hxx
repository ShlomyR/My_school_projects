#pragma once

class Interface
{
public:
    Interface() = default;
    virtual ~Interface() = default;

    virtual void init(std::unique_ptr<sf::RenderWindow> &) = 0;
    virtual void render(std::unique_ptr<sf::RenderWindow> &) = 0;
};

class Interface_son : public Interface
{
public:
    virtual void update(std::unique_ptr<sf::RenderWindow> &) = 0;
};

class Interface_grandson : public Interface_son
{
public:
    virtual void initSprite(std::unique_ptr<sf::RenderWindow> &) = 0;
};