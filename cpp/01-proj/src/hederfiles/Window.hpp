#pragma once

#include <SFML/Graphics.hpp>
#include <thread>
#include <memory>

#include "Interface.hxx"
#include "Paddle.hpp"
//#include "GameManager.hpp"

class Window : public Interface_son
{
public:
    explicit Window(size_t,size_t);
    virtual ~Window() = default;

    void init(std::unique_ptr<sf::RenderWindow> &) override;
    void update(std::unique_ptr<sf::RenderWindow> &) override;
    void render(std::unique_ptr<sf::RenderWindow> &) override;

    void whileFunc();
    std::unique_ptr<sf::RenderWindow> &getRenderWindow();
private:
    std::unique_ptr<sf::RenderWindow> m_window;
    sf::VideoMode m_videoMode;
    sf::Event m_event;
};