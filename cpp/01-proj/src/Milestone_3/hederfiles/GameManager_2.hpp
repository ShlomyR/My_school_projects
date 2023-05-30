#pragma once

#include <SFML/Graphics.hpp>
#include "WindowManager.hpp"
#include "InputManager.hpp"
#include "PhysicsManager.hpp"

class GameManager {
public:
    GameManager(WindowManager& windowManager, InputManager& inputManager);
    void run();
private:
    void handleInput();
    void update(float deltaTime);
    void render();
    void reset();
private:
    WindowManager& m_windowManager;
    InputManager& m_inputManager;
    PhysicsManager m_physicsManager;
    Ball m_ball;
    Paddle m_paddle;
    Brick m_brick;
    Border m_border;
    float m_ballSpeed;
};