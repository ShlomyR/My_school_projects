#pragma once

#include <SFML/Graphics.hpp>

class IGameRendering {
public:
    virtual ~IGameRendering() = default;
    virtual void render() = 0;
    virtual void renderBG() = 0;
    virtual void closeWindow() = 0;
};

class GameRendering : public IGameRendering {
public:
    void render() override {
        m_window->clear();
        
        m_window->display();
    }

    void renderBG() override {
        // ...
    }

    void closeWindow() override {
        if (m_window != nullptr) {
            m_window->close();
            delete m_window;
            m_window = nullptr;
        }
    }
private:
    sf::RenderWindow* m_window;
};