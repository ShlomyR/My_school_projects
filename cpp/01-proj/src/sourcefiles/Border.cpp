#include "../hederfiles/Border.hpp"

void Border::windowBorderDetection(
    std::unique_ptr<BallManager> &ball_manager
    , sf::FloatRect &ballBounds
)
{
    if (ballBounds.left <= 0 || ballBounds.left >= ball_manager->m_windowBoundWidth - ballBounds.width) {
        ball_manager->m_dx = -ball_manager->m_dx;
    } else if (ballBounds.top <= 0 || ballBounds.top >= ball_manager->m_windowBoundHeight - ballBounds.height) {
        ball_manager->m_dy = -ball_manager->m_dy;
        if (!(ballBounds.top <= 0)) {
            TextManager::getInstance()->decreaseHealth();
            ball_manager->isPressed = false;
        }

    }
}

void Border::ballCollideWithBrick(
    std::unique_ptr<Bricks> & brick_obj
    , std::unique_ptr<BallManager> & ball_manager
    , sf::FloatRect & ballBounds
)
{
    bool deleted = false;
    ballBounds.left += ball_manager->m_dx * ball_manager->m_speed;
    sf::FloatRect ballBoundX = sf::Rect<float>(ballBounds.left, ballBounds.top,ballBounds.width,ballBounds.height);
    for (int i = 0; i < brick_obj->getN(); i++) {
        if (ballBoundX.intersects(brick_obj->getSBrick(i).getGlobalBounds())) {
            deleted = true;
            if (deleted) {
                brick_obj->deleteBricks(i);
                TextManager::getInstance()->increaseScore();
                ball_manager->m_dx = -ball_manager->m_dx;
                break;
            }
            break;
        }
    }
    ballBounds.top += ball_manager->m_dy * ball_manager->m_speed;
    sf::FloatRect ballBoundY = sf::Rect<float>(ballBounds.left, ballBounds.top,ballBounds.width,ballBounds.height);
    for (int i = 0; i < brick_obj->getN(); i++) {
        if (ballBoundY.intersects(brick_obj->getSBrick(i).getGlobalBounds())) {
            deleted = true;
            if (deleted) {
                brick_obj->deleteBricks(i);
                TextManager::getInstance()->increaseScore();
                ball_manager->m_dy = -ball_manager->m_dy;
                break;
            }
            break;
        }
    }
}
