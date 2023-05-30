#include "../hederfiles/GameManager.hpp"

#include <unistd.h>
// #include "../hederfiles/GameManager.hpp"
// #include "GameManager.hpp"


GameManager::~GameManager()
{
    if (this->m_t1->joinable()) {
        this->m_t1->detach();
    }
}

GameManager *GameManager::getInstance()
{
    static GameManager m_instance;
    return &m_instance;
}

void GameManager::start()
{
    this->m_t1  = std::make_unique<std::thread>(init);
}

void GameManager::pause()
{
    sleep(1);
}

void GameManager::reset()
{
    sf::FloatRect paddleBound = this->m_paddle->getSprite().getGlobalBounds();
    sf::Vector2u windowSize;
    
    TextManager::getInstance()->m_counter = 0;
    TextManager::getInstance()->m_level = 1;
    this->m_ball_manager->isPressed = false;
    //TextManager::getInstance()->setGameStart(true);
    this->m_bricks->init(this->m_window->getRenderWindow());
    this->m_bricks->spawnBricks();
    // TextManager::getInstance()->setHealth(5);
    // TextManager::getInstance()->setScore(0);
    // TextManager::getInstance()>m_givenScore = TextManager::getInstance()->getScore();
    this->m_paddle->getSprite().setPosition(
        windowSize.x/2 - paddleBound.width/2,
        windowSize.y - paddleBound.height
    );
}

void GameManager::init()
{
    GameManager::getInstance()->m_window->whileFunc();    
}

std::unique_ptr<Text> &GameManager::getTextObj()
{
    return this->m_text;
}

std::unique_ptr<Bricks> &GameManager::getBricksObj()
{
    return this->m_bricks;
}

void GameManager::setObj(std::unique_ptr<Bricks> &bricks)
{
    this->m_bricks = std::move(bricks);
}

std::unique_ptr<Ball> &GameManager::getBallObj()
{
    return this->m_ball;
}

void GameManager::setObj(std::unique_ptr<Ball> &ball)
{
    this->m_ball = std::move(ball);
}

std::unique_ptr<BallManager> &GameManager::getBallManagerObj()
{
    return this->m_ball_manager;
}

void GameManager::setObj(std::unique_ptr<BallManager> &ball_manager)
{
    this->m_ball_manager = std::move(ball_manager);
}

std::shared_ptr<Paddle> &GameManager::getPaddleObj()
{
    return this->m_paddle;
}

void GameManager::setObj(std::shared_ptr<Paddle> &paddle)
{
    this->m_paddle = std::move(paddle);
}

std::unique_ptr<Window> &GameManager::getWindowObj()
{
    return this->m_window;
}

void GameManager::setObj(std::unique_ptr<Window> &window)
{
    this->m_window = std::move(window);
}

std::unique_ptr<RenderBg> &GameManager::getRenderBgObj()
{
    return this->m_render_bg;
}