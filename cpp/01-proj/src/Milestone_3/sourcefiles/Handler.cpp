#include "../hederfiles/Handler.hpp"
#include "../hederfiles/GameManager_1.hpp"
#include "Handler.hpp"

void Handler::handleEvent(sf::Event &event)
{
    while (GameManager::getInstance()->getWindow()->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            GameManager::getInstance()->getWindow()->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            GameManager::getInstance()->pause();
        }
        if (event.key.code == sf::Keyboard::Space) {
            GameManager::getInstance()->getPaddle()->setIsPressed(true);
        }
        if (event.key.code == sf::Keyboard::Q) {
            GameManager::getInstance()->reset();
        }
        
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sequence[currentKeyIndex]) // if the pressed key is the next key in the sequence
            {
                currentKeyIndex++;

                if (currentKeyIndex == sequence.size()) // if the sequence has been matched
                {
                    sequenceMatched = true;
                    break;
                }
            }
            else // if the pressed key is not the next key in the sequence
            {
                currentKeyIndex = 0;
            }
        }
        
    }
}
        
    


void Handler::draw()
{
    GameManager::getInstance()->getWindow()->draw(*GameManager::getInstance()->getBorder()->getShape());
    GameManager::getInstance()->getWindow()->draw(*GameManager::getInstance()->getPaddle()->getShape());
    GameManager::getInstance()->getWindow()->draw(*GameManager::getInstance()->getBall()->getShape());
    for (auto &i : GameManager::getInstance()->getBrick()->getVecBricks()) {
        GameManager::getInstance()->getWindow()->draw(i);
    }
}

void Handler::logics(float m_deltaTime,float m_ballSpeed)
{
    GameManager::getInstance()->getBall()->move(m_ballSpeed * GameManager::getInstance()->getBall()->getDirection().x * m_deltaTime,m_ballSpeed * GameManager::getInstance()->getBall()->getDirection().y * m_deltaTime);
    GameManager::getInstance()->getCollision()->checkBallCollisions(GameManager::getInstance()->getBall(),GameManager::getInstance()->getBorder(),GameManager::getInstance()->getPaddle(),GameManager::getInstance()->getBrick(),GameManager::getInstance()->getWindow());
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        GameManager::getInstance()->getArrowMovement()->moveLeft();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        GameManager::getInstance()->getArrowMovement()->moveRight();
    }
    if (sequenceMatched) // if the sequence has been matched, open a new window
    {
        sf::RenderWindow newWindow(sf::VideoMode(800, 600), "New SFML window");
        while (newWindow.isOpen())
        {
            sf::Event event;
            while (newWindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    newWindow.close();
            }

            newWindow.clear();
            newWindow.display();
        }

        sequenceMatched = false;
        currentKeyIndex = 0;
    }
}