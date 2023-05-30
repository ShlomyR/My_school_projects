#include <iostream>

#include "../hederfiles/Window.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/GameManager.hpp"
// #include "Window.hpp"

Window::Window(size_t width, size_t hight)
{
    m_videoMode.width = width;
    m_videoMode.height = hight;
    m_window = std::make_unique<sf::RenderWindow>(m_videoMode, "Arkoind!");
    m_window->setFramerateLimit(60);
    m_window->setPosition(sf::Vector2i(m_videoMode.getDesktopMode().width/3,m_videoMode.getDesktopMode().height/4));
    init(m_window);
}

void Window::init(std::unique_ptr<sf::RenderWindow> &target)
{
    GameManager::getInstance()->getTextObj()->init();
    GameManager::getInstance()->getTextObj()->initFonts();
    GameManager::getInstance()->getRenderBgObj()->init();
    GameManager::getInstance()->getRenderBgObj()->initSprite();
    GameManager::getInstance()->getBricksObj()->init(target);
    GameManager::getInstance()->getBricksObj()->spawnBricks();
    GameManager::getInstance()->getPaddleObj()->init(target);
    GameManager::getInstance()->getBallObj()->init(target);
    GameManager::getInstance()->getBallObj()->initSprite(target);
}

void Window::update(std::unique_ptr<sf::RenderWindow> &window)
{
    GameManager::getInstance()->getTextObj()->update();
    GameManager::getInstance()->getBricksObj()->update(window);
    GameManager::getInstance()->getBallObj()->update(window);
    GameManager::getInstance()->getPaddleObj()->update(window);
    while (window->pollEvent(m_event)) {
        if (m_event.type == sf::Event::Closed) {
            window->close();
        } else if (m_event.key.code == sf::Keyboard::Escape) {
            window->close();
        } else if (m_event.type == sf::Event::TextEntered) {

        } else {

        }
    }
}

void Window::render(std::unique_ptr<sf::RenderWindow> &target)
{
    m_window->clear();
    GameManager::getInstance()->getTextObj()->renderText(target);
    GameManager::getInstance()->getRenderBgObj()->render(target);
    GameManager::getInstance()->getBricksObj()->render(target);
    GameManager::getInstance()->getBallObj()->render(target);
    GameManager::getInstance()->getPaddleObj()->render(target);
    m_window->display();
}

void Window::whileFunc()
{
    while (m_window->isOpen()) {
        update(m_window);
        render(m_window);
    }
    if (!m_window->isOpen()) {
        SymbolVar::getInstance()->map_strDB.at("is_window_open") = "false";

    }
}

std::unique_ptr<sf::RenderWindow>  &Window::getRenderWindow()
{
    return this->m_window;
}