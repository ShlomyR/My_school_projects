#include "../hederfiles/GameManager.hpp"
#include <unistd.h>


GameManager::GameManager(
    WindowManager& windowManager
    , InputManager& inputManager
    , Ball &ball
    , Brick &brick
    , Paddle &paddle
    , Border &border
)
: m_windowManager(windowManager)
, m_inputManager(inputManager)
, m_ball(ball)
, m_brick(brick)
, m_paddle(paddle)
, m_border(border)
, m_hud(windowManager.getRenderWindow())
, m_menu(windowManager)
, m_high_score_manager()
, m_gameState(5, 1, 0, m_high_score_manager.getFirstHighScore())
, m_ballSpeed(200.f)
{
    m_ball.setDirection(sf::Vector2f(std::rand() % 200 - 100, std::rand() % 200 - 100));
    m_physicsManager = PhysicsManager();

    for (size_t i = 0; i < m_menu.getOptionSize(); ++i) {
        m_menu.getOption(i)->makeButton(windowManager.getRenderWindow());
    }

    m_game_state_map = {
        { GameStateKey::BRICK_EMPTY, [&](){
            m_brick.init();
            reset();
            m_gameState.nextLevel();
        }},
        { GameStateKey::BALL_OUT_OF_BOUNDS, [&](){
            m_paddle.setIsPressed(false);
            m_gameState.decreaseHealth();
        }},
        { GameStateKey::NO_HEALTH, [&](){
            reset();
            sleep(3);
        }},
        { GameStateKey::UPDATE_HIGH_SCORE, [&](){
            m_gameState.setHighScore(m_gameState.getScore());
            m_high_score_manager.updateHighScoreToFile(m_gameState.getHighScore());
        }}
    };
}

void GameManager::run()
{
    while (m_windowManager.isOpen()) {
        float deltaTime = 0.5;
        handleInput();
        update(deltaTime);
        render();
    }
}

void GameManager::showMenu()
{
    if (m_menu.getSelectedOptionIndex() == 0) {
        m_menu.setIsMenuShown(false);
        m_high_score_manager.setIsHighScoreShown(false) ;
    } else if (m_menu.getSelectedOptionIndex() == 1) {
        m_high_score_manager.setIsHighScoreShown(true);
    } else if (m_menu.getSelectedOptionIndex() == 2) {
        m_windowManager.getRenderWindow().close();
    }
}

void GameManager::handleInput()
{
    m_inputManager.handleInput(m_windowManager.getRenderWindow(),m_gameState,m_paddle,m_menu,m_inputManager);
}

void GameManager::update(float deltaTime)
{

    if (m_brick.isEmpty()) {
        m_game_state_map[GameStateKey::BRICK_EMPTY]();
    } else if (m_ball.getPosition().y > m_windowManager.getSize().y -10) {
        m_game_state_map[GameStateKey::BALL_OUT_OF_BOUNDS]();
    } else if (m_gameState.getHealth() <= 0) {
        m_game_state_map[GameStateKey::NO_HEALTH]();
    } else if (m_menu.getIsMenuShown()) {
        reset();
    } else if (m_gameState.getScore() > m_gameState.getHighScore()) {
        m_game_state_map[GameStateKey::UPDATE_HIGH_SCORE]();
    } else if (m_high_score_manager.getIsHighScoreShown()) {
        m_high_score_manager.updateHighScore(m_inputManager.getLastEvent(),m_gameState.getHighScore(),m_hud);
    }
    m_physicsManager.update(deltaTime, m_ball, m_paddle, m_brick, m_border, m_gameState);
    m_hud.update(m_gameState.getScore(), m_gameState.getHealth(),m_gameState.getHighScore(),m_hud);
    m_paddle.update();
}

void GameManager::render()
{
    m_windowManager.clear();
    if (m_menu.getIsMenuShown()) {
        m_menu.draw();
    } else if (m_high_score_manager.getIsHighScoreShown()) {
        m_high_score_manager.drew(m_windowManager.getRenderWindow());
        m_hud.draw(m_windowManager.getRenderWindow(), m_gameState,m_high_score_manager);
        showMenu();
    } else {
        showMenu();
        m_windowManager.draw(*m_paddle.getShape());
        m_windowManager.draw(*m_ball.getShape());
        m_brick.draw(m_windowManager.getRenderWindow());
        m_border.draw(m_windowManager.getRenderWindow());
        m_hud.draw(m_windowManager.getRenderWindow(), m_gameState,m_high_score_manager);
    }
    m_windowManager.display();
}

void GameManager::reset()
{
    m_brick.init();
    m_paddle.setIsPressed(false);
    m_paddle.setPosition(m_windowManager.getSize().x / 2.f - 50,m_windowManager.getSize().y - 20);
    m_ball.setPosition(m_paddle.getCenterPosition().x,m_paddle.getCenterPosition().y);
    m_ball.setDirection(sf::Vector2f(std::rand() % 200 - 100, std::rand() % 200 - 100));
    m_gameState.resetScore();
    m_gameState.resetHealth();
}
