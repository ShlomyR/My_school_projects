#pragma once

#include <SFML/Graphics.hpp>

#include "WindowManager.hpp"
#include "InputManager.hpp"
#include "PhysicsManager.hpp"
#include "GameState.hpp"
#include "Hud.hpp"
#include "Menu.hpp"
#include "HighScoreManager.hpp"

enum class GameStateKey {
    BRICK_EMPTY,
    BALL_OUT_OF_BOUNDS,
    NO_HEALTH,
    UPDATE_HIGH_SCORE
};

class GameManager {
public:
    GameManager(
            WindowManager& windowManager
        ,   InputManager& inputManager
        ,   Ball &ball
        ,   Brick &brick
        ,   Paddle &paddle
        ,   Border &border
    );
    void run();
private:
    void showMenu();
    void handleInput();
    void update(float deltaTime);
    void render();
    void reset();
private:
    WindowManager &m_windowManager;
    InputManager &m_inputManager;
    PhysicsManager m_physicsManager;
    Ball &m_ball;
    Brick &m_brick;
    Paddle &m_paddle;
    Border &m_border;
    Hud m_hud;
    Menu m_menu;
    HighScoreManager m_high_score_manager;
    GameState m_gameState;

    std::unordered_map<GameStateKey, std::function<void()>> m_game_state_map;

    float m_ballSpeed;
    sf::Vector2u windowSize;
};