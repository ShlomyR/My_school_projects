#include "../hederfiles/GameManager_2.hpp"

GameManager::GameManager(WindowManager& windowManager, InputManager& inputManager)
    : m_windowManager(windowManager), m_inputManager(inputManager), m_ball(), m_paddle(), m_brick(), m_border(), m_ballSpeed(200.f)
{
    // Initialize game objects
    m_ball.setPosition(m_paddle.getShape()->getGlobalBounds().left + 50, m_paddle.getShape()->getGlobalBounds().top - 13);
    m_ball.setDirection(sf::Vector2f(std::rand() % 200 - 100, std::rand() % 200 - 100));
    m_physicsManager = PhysicsManager();
}

void GameManager::run()
{
    sf::Clock clock;
    while (m_windowManager.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        handleInput();
        update(deltaTime);
        render();
    }
}

void GameManager::handleInput()
{
    m_inputManager.pollEvent(m_windowManager.getRenderWindow());
    if (m_inputManager.isKeyPressed(sf::Keyboard::Escape)) {
        m_windowManager.getRenderWindow().close();
    }
    m_paddle.setIsPressed(m_inputManager.isKeyPressed(sf::Keyboard::Left) || m_inputManager.isKeyPressed(sf::Keyboard::Right));
}

void GameManager::update(float deltaTime)
{
    m_physicsManager.update(deltaTime, m_ball, m_paddle, m_brick, m_border);

    if (m_brick.isEmpty()) {
        m_brick.init();
    }
    if (m_ball.getPosition().y > m_windowManager.getRenderWindow().getSize().y) {
        reset();
    }
}

void GameManager::render()
{
    m_windowManager.clear();
    m_windowManager.draw(*m_paddle.getShape());
    m_windowManager.draw(*m_ball.getShape());
    m_windowManager.draw(*m_brick.getShape());
    m_windowManager.draw(*m_border.getShape());
    m_windowManager.display();
}
// m_brick.draw(m_windowManager);
// m_border.draw(m_windowManager);

void GameManager::reset()
{
    m_brick.init();
    m_paddle.setIsPressed(false);
    m_ball.setPosition(m_paddle.getShape()->getGlobalBounds().left + 50, m_paddle.getShape()->getGlobalBounds().top - 13);
    m_ball.setDirection(sf::Vector2f(std::rand() % 200 - 100, std::rand() % 200 - 100));
}

