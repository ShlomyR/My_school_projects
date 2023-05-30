#pragma once

#include "Bricks.hpp"
#include "Ball.hpp"
#include "BallManager.hpp"
#include "Paddle.hpp"
#include "RenderBg.hpp"
#include "Text.hpp"
#include "TextManager.hpp"
#include "Window.hpp"

#include <memory>
#include <thread>

class GameManager
{
public:
    ~GameManager();
    static GameManager *getInstance();

    void start();
    void pause();
    void reset();
    static void init();

    std::unique_ptr<Text> &getTextObj();
    void setObj(std::unique_ptr<Bricks> &);
    std::unique_ptr<Bricks> &getBricksObj();
    void setObj(std::unique_ptr<Ball> &);
    std::unique_ptr<Ball> &getBallObj();
    void setObj(std::unique_ptr<BallManager> &);
    std::unique_ptr<BallManager> &getBallManagerObj();
    void setObj(std::shared_ptr<Paddle> &);
    std::shared_ptr<Paddle> &getPaddleObj();
    void setObj(std::unique_ptr<Window> &);
    std::unique_ptr<Window> &getWindowObj();
    std::unique_ptr<RenderBg> &getRenderBgObj();

private:
    GameManager() {}
    std::unique_ptr<Bricks> m_bricks;
    std::unique_ptr<Ball> m_ball;
    std::shared_ptr<Paddle> m_paddle;
    std::unique_ptr<Window> m_window;
    std::unique_ptr<BallManager> m_ball_manager = std::make_unique<BallManager>();
    std::unique_ptr<RenderBg> m_render_bg = std::make_unique<RenderBg>();
    std::unique_ptr<Text> m_text = std::make_unique<Text>();

    std::unique_ptr<std::thread> m_t1;

    bool m_running = true;
};