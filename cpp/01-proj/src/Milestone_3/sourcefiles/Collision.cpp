#include "../hederfiles/Collision.hpp"

bool Collision::checkCircleRectangleCollision(const sf::CircleShape &circle, const sf::RectangleShape &rectangle)
{
    sf::FloatRect circleBounds = circle.getGlobalBounds();
    sf::FloatRect rectangleBounds = rectangle.getGlobalBounds();

    return circleBounds.intersects(rectangleBounds);
}

bool Collision::checkCircleCircleCollision(const sf::CircleShape &circle1, const sf::CircleShape &circle2)
{
    sf::FloatRect circle1Bounds = circle1.getGlobalBounds();
    sf::FloatRect circle2Bounds = circle2.getGlobalBounds();
    return circle1Bounds.intersects(circle2Bounds);
}

void Collision::checkBallCollisions(
    std::unique_ptr<Ball> &m_ball
    , std::unique_ptr<Border> &m_border
    , std::shared_ptr<Paddle> &m_paddle
    , std::unique_ptr<Brick> &m_brick
    , std::unique_ptr<WindowAdapter> &m_window
)
{
    const sf::Vector2f ballPos = m_ball->getPosition();
    const float ballRadius = m_ball->getRadius();
    const sf::Vector2u windowSize = m_window->getSize();
    const sf::Vector2f borderPos = m_border->getPosition();
    const sf::Vector2f borderSize = m_border->getShape()->getSize();
    const sf::Vector2f paddlePos = m_paddle->getPosition();
    const sf::Vector2f paddleSize = m_paddle->getShape()->getSize();

    // Compute the new ball direction based on the collision type
    sf::Vector2f newDirection = m_ball->getDirection();

    if (ballPos.y - ballRadius < borderPos.y 
        || ballPos.y + ballRadius > borderPos.y + borderSize.y 
        || ballPos.y - ballRadius < 0.f 
        || ballPos.y + ballRadius > windowSize.y
        )
    {
        newDirection.y = -newDirection.y;
    }
    if (ballPos.x - ballRadius < borderPos.x 
        || ballPos.x + ballRadius > borderPos.x + borderSize.x 
        || ballPos.x - ballRadius < 0.f 
        || ballPos.x + ballRadius > windowSize.x
        )
    {
        newDirection.x = -newDirection.x;
    }
    if (ballPos.y + ballRadius >= paddlePos.y 
        && ballPos.y + ballRadius <= paddlePos.y + 10.f 
        && ballPos.x + ballRadius >= paddlePos.x 
        && ballPos.x - ballRadius <= paddlePos.x + paddleSize.x
        )
    {
        newDirection.y = -newDirection.y;
    }

    // Clamp the paddle position to stay within the border
    float newPaddleX = std::max(borderPos.x, std::min(paddlePos.x, borderPos.x + borderSize.x - paddleSize.x));
    if (newPaddleX != paddlePos.x)
    {
        m_paddle->setPosition(newPaddleX, paddlePos.y);
    }


    // Check for brick collisions
    sf::FloatRect ballBounds(ballPos.x - ballRadius, ballPos.y - ballRadius, ballRadius * 2.f, ballRadius * 2.f);
    for (size_t i = 0; i < m_brick->getVecBricks().size(); i++) {
        if (ballBounds.intersects(m_brick->getBrick(i).getGlobalBounds())) {
            m_brick->deleteBrick(i);
            newDirection.y = -newDirection.y;
            break;
        }
    }

    if (m_paddle->getIsPressed()) {
        m_ball->setDirection(newDirection);
    } else {
        m_ball->setPosition(m_paddle->getShape()->getGlobalBounds().left+50,m_paddle->getShape()->getGlobalBounds().top-13);
    }
    //m_ball->setDirection(newDirection);
}