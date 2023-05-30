#pragma once

#include <SFML/Graphics.hpp>

class IGameInput {
public:
    virtual ~IGameInput() = default;
    virtual void pollEvents(sf::RenderWindow &,sf::Event) = 0;
    virtual sf::Vector2f getMousePosition(sf::RenderWindow &) = 0;
};


class GameInput : public IGameInput {
public:
    void reset() {
        // this->m_paddleBound = this->paddle->getSprite().getGlobalBounds();
        // this->m_counter = 0;
        // this->m_level = 1;
        // this->ball->isPressed = false;
        // this->information->setGameStart(true);
        // this->m_vecBrickObj[0]->initBricks();
        // this->m_vecBrickObj[0]->spawnBricks();
        // this->information->setHealth(5);
        // this->information->m_givenScore = this->information->getScore();
        // this->information->setScore(0);
        // this->paddle->getSprite().setPosition(
        //     this->m_windowSize.x/2 - this->m_paddleBound.width/2,
        //     this->m_windowSize.y - this->m_paddleBound.height
        // );
    }
    void pollEvents(sf::RenderWindow &window,sf::Event event) override {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } if (event.key.code == sf::Keyboard::Escape) {
                reset();
            } if (event.type == sf::Event::TextEntered) {
                // if (this->m_isUpdateHighScore) {
                //     this->information->updateHighScore(this->ev);
                // }
            }
        }
    }
    sf::Vector2f getMousePosition(sf::RenderWindow &window) override {
        return window.mapPixelToCoords(sf::Mouse::getPosition(window));
    }
private:

};