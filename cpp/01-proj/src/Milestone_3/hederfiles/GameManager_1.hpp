#pragma once


#include "WindowAdapter.hpp"
#include "ArrowMovement.hpp"

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Border.hpp"
#include "Brick.hpp"
#include "Collision.hpp"
#include "Handler.hpp"

#include <memory>

class GameManager
{
public:
    static GameManager *getInstance();
    ~GameManager() = default;

    void start();
    void logics();
    void pause();
    void reset();
    void init();

    // Geter
    std::unique_ptr<Ball> & getBall();
    std::unique_ptr<Brick> & getBrick();
    std::unique_ptr<Border> & getBorder();
    std::shared_ptr<Paddle> & getPaddle();
    std::unique_ptr<ArrowMovement> & getArrowMovement();
    std::unique_ptr<Collision> & getCollision();
    std::unique_ptr<WindowAdapter> & getWindow();
    // Seter
    void setBall(std::unique_ptr<Ball> &);
    void setBorder(std::unique_ptr<Border> &);
    void setBrick(std::unique_ptr<Brick> &);
    void setPaddle(std::shared_ptr<Paddle> &);
    void setArrowMovement(std::unique_ptr<ArrowMovement> &);
    void setCollision(std::unique_ptr<Collision> &);
    void setWindow(std::unique_ptr<WindowAdapter> &);

private:
    GameManager(){}
    std::unique_ptr<Ball> m_ball;
    std::unique_ptr<Brick> m_brick;
    std::unique_ptr<Border> m_border;
    std::shared_ptr<Paddle> m_paddle;
    std::unique_ptr<ArrowMovement> m_arrow_movement;
    std::unique_ptr<WindowAdapter> m_window;
    std::unique_ptr<Collision> m_collision = std::make_unique<Collision>();
    std::unique_ptr<Handler> m_handler = std::make_unique<Handler>();
    
    
    //sf::Time m_deltaTime;
    float m_deltaTime = 0.f;
    float m_ballSpeed = 200.f;
    bool m_isPaused = false;
    std::vector<sf::Keyboard::Key> sequence {sf::Keyboard::A, sf::Keyboard::B, sf::Keyboard::C}; // define the sequence of keys
    bool sequenceMatched = false;
    size_t currentKeyIndex = 0;
};