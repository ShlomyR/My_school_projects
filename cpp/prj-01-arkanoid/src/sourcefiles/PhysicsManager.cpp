#include "../hederfiles/PhysicsManager.hpp"

#define MAX_BOUNCE_ANGLE 55

PhysicsManager::PhysicsManager() {}

void PhysicsManager::update(float deltaTime
    , Ball& ball
    , Paddle& paddle
    , Brick& brick
    , Border& border
    , GameState& game_state
) {
    checkPaddleCollision(ball, paddle);
    checkBrickCollision(ball, brick, game_state);
    checkBorderCollision(ball, border);
    checkPaddleBorderCollision(paddle, border);

    if (paddle.getIsPressed()) {
        ball.move(ball.getDirection().x * m_ballSpeed * deltaTime,ball.getDirection().y * m_ballSpeed * deltaTime);
    } else {
        ball.setPosition(paddle.getCenterPosition().x,paddle.getCenterPosition().y);
    }
}

void PhysicsManager::checkPaddleCollision(Ball& ball, Paddle& paddle) {
    sf::FloatRect ballBounds = ball.getShape()->getGlobalBounds();
    ballBounds.height += ball.getDirection().y;
    sf::FloatRect ballBoundX = sf::Rect<float>(ballBounds.left, ballBounds.top,ballBounds.width,ballBounds.height);

    if (ballBoundX.intersects(paddle.getShape()->getGlobalBounds())) {
        ball.setDirection(sf::Vector2f(std::sin(ball.getDirection().x), std::cos(-ball.getDirection().y )));
    }
}

void PhysicsManager::checkBrickCollision(Ball& ball, Brick& brick,GameState& game_state) {
    bool deleted = false;
    sf::FloatRect ballBounds = ball.getShape()->getGlobalBounds();
    ballBounds.height += ball.getDirection().y;
    sf::FloatRect ballBoundY = sf::Rect<float>(ballBounds.left, ballBounds.top,ballBounds.width,ballBounds.height);
    for (size_t i = 0; i < brick.getVecBricks().size(); ++i) {
        if (ballBoundY.intersects(brick.getBrick(i).getGlobalBounds())) {
            deleted = true;
            if (deleted) {
                brick.deleteBrick(i);
                game_state.increaseScore();
                ball.setDirection(sf::Vector2f(ball.getDirection().x, -ball.getDirection().y));
                break;
            }
            break;
        }
    }
}

void PhysicsManager::checkBorderCollision(Ball& ball, Border& border) {
    if (ball.getShape()->getPosition().x - ball.getShape()->getRadius() <= border.getShape()->getGlobalBounds().left || 
        ball.getShape()->getPosition().x + ball.getShape()->getRadius() >= border.getShape()->getGlobalBounds().width) {
        ball.setDirection(sf::Vector2f(-ball.getDirection().x, ball.getDirection().y));
    }
    if (ball.getShape()->getPosition().y - ball.getShape()->getRadius() <= border.getShape()->getGlobalBounds().top ||
        ball.getShape()->getPosition().y + ball.getShape()->getRadius() >= border.getShape()->getGlobalBounds().height) {
        ball.setDirection(sf::Vector2f(ball.getDirection().x, -ball.getDirection().y));
    }
}

void PhysicsManager::checkPaddleBorderCollision(Paddle& paddle, Border& border)
{
    const sf::Vector2f borderPos = border.getPosition();
    const sf::Vector2f borderSize = border.getShape()->getSize();
    const sf::Vector2f paddlePos = paddle.getPosition();
    const sf::Vector2f paddleSize = paddle.getShape()->getSize();
    float newPaddleX = std::max(borderPos.x, std::min(paddlePos.x, borderPos.x + borderSize.x - paddleSize.x));
    if (newPaddleX != paddlePos.x)
    {
        paddle.setPosition(newPaddleX, paddlePos.y);
    }
}