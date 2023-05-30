#pragma once

#include <SFML/Graphics.hpp>

class WindowAdapter
{
public:
    WindowAdapter(int width, int height, const std::string &title);

    bool isOpen() const;
    void close();
    void clear();
    void display();
    void draw(sf::Drawable &);
    
    template<typename T>
    void run(std::vector<T*>);

    bool pollEvent(sf::Event &);
    sf::Vector2u getSize() const;

    std::unique_ptr<sf::RenderWindow> &getRenderWindow()
    {
        return m_window;
    }

private:
    std::unique_ptr<sf::RenderWindow> m_window;
    int m_width, m_height;
};