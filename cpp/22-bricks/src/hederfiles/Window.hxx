#pragma once

#include<SFML/Graphics.hpp>

class IWindow {
public:
    virtual ~IWindow() {}
    virtual bool pollEvent(sf::Event& event) = 0;
    virtual void close() = 0;
};

class SFMLWindowAdapter : public IWindow {
public:
    SFMLWindowAdapter(sf::RenderWindow& window, int width, int height) 
        : m_window(window) 
    {
        m_window.setSize(sf::Vector2u(width, height));
    }

    bool pollEvent(sf::Event& event) override {
        return m_window.pollEvent(event);
    }

    virtual void close() override {
        m_window.close();
    }

private:
    sf::RenderWindow& m_window;
};
