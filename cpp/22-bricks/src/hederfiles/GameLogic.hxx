#pragma once

#include "Menu.hpp"
#include "Bricks.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Information.hpp"

// class GameLogic {
// public:
//     virtual ~GameLogic() = default;
//     virtual void start() = 0;
//     virtual void pause() = 0;
//     virtual void reset() = 0;
//     virtual void update() = 0;
//     virtual bool running() = 0;
// };
    // virtual void setObj(Bricks*) = 0;
    // virtual void setObj(Menu*) = 0;
    // virtual Ball*& setObj(Ball*&) = 0;
    // virtual Paddle*& setObj(Paddle*&) = 0;
    // virtual Information*& setObj(Information*&) = 0;
    // virtual std::vector<Bricks*>& getVecObj() = 0;
    // virtual int getCurrLevel() = 0;
    // virtual int incrementMaxLevel() = 0;
    // virtual void checkCurrentLevel(int) = 0;
    // virtual Bricks*& getBrick() = 0;
    // virtual int getLevel() = 0;

class IGameLogic {
public:
    virtual ~IGameLogic() = default;
    virtual void start() = 0;
    virtual void update(sf::RenderWindow *) = 0;
    virtual void setObj(Bricks*) = 0;
    virtual void setObj(Menu*) = 0;
    virtual Ball*& setObj(Ball*&) = 0;
    virtual Paddle*& setObj(Paddle*&) = 0;
    virtual Information*& setObj(Information*&) = 0;
};

class GameLogic : public IGameLogic {
public:
    GameLogic(
    Bricks &bricks
    ,Menu &menu
    ,Ball &ball
    ,Paddle &paddle
    ,Information &information
    ,Menu &highScores
    )
    :   m_bricks(bricks)
    ,   m_menu(menu)
    ,   m_ball(ball)
    ,   m_paddle(paddle)
    ,   m_information(information)
    ,   m_highScores(highScores)
    {}
    void start() override {
        // this->t1  = new std::thread(init);
    }

    void update(sf::RenderWindow *window) override {
        if (!this->m_information.getEndGame()) {
            this->m_paddle.updatePaddle(window);
            this->m_ball.updateBall();
            this->m_information.updateTexts();
        }
    }
    void setObj(Bricks*) override {
        // ...
    }
    void setObj(Menu*) override {
        // ...
    }
    Ball*& setObj(Ball*&) override {
        // ...
    }
    Paddle*& setObj(Paddle*&) override {
        // ...
    }
    Information*& setObj(Information*&) override {
        // ...
    }
    
private:
    Bricks &m_bricks;
    Menu &m_menu;
    Ball &m_ball;
    Paddle &m_paddle;
    Information &m_information;
    Menu &m_highScores;
};