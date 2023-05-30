#include "../hederfiles/WindowAdapter.hpp"

WindowAdapter::WindowAdapter(int width, int height, const std::string &title)
:   m_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title))
,   m_width(width)
,   m_height(height)
{
    m_window->setFramerateLimit(60);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

bool WindowAdapter::isOpen() const
{
    return m_window->isOpen();
}

void WindowAdapter::close()
{
    m_window->close();
}

void WindowAdapter::clear()
{
    m_window->clear();
}

void WindowAdapter::display()
{
    m_window->display();
}

void WindowAdapter::draw(sf::Drawable &drawable)
{
    m_window->draw(drawable);
}

bool WindowAdapter::pollEvent(sf::Event &event)
{
    return m_window->pollEvent(event);
}

sf::Vector2u WindowAdapter::getSize() const
{
    return m_window->getSize();
}
