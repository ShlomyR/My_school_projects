#include "../hederfiles/WindowManager.hpp"

class WindowManager {
public:
    WindowManager(const sf::Vector2u& windowSize, const std::string& windowTitle)
    : m_window(sf::VideoMode(windowSize.x, windowSize.y), windowTitle)
    {}
    
    bool isOpen() const {
        return m_window.isOpen();
    }
    
    void clear() {
        m_window.clear();
    }
    
    void display() {
        m_window.display();
    }
    
    void pollEvent(sf::Event& event) {
        m_window.pollEvent(event);
    }
    
    void draw(const sf::Drawable& drawable) {
        m_window.draw(drawable);
    }
    
    void draw(const sf::Vertex* vertices, std::size_t vertexCount, sf::PrimitiveType type) {
        m_window.draw(vertices, vertexCount, type);
    }

    sf::RenderWindow &WindowManager::getRenderWindow()
    {
        return m_window;
    }
private:
    sf::RenderWindow m_window;
};