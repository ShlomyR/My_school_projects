#include "../hederfiles/PhysicsManager.hpp"

#define MAX_BOUNCE_ANGLE 0.3

PhysicsManager::PhysicsManager() {}

void PhysicsManager::update(float deltaTime, Ball& ball, Paddle& paddle, Brick& brick, Border& border) {
    checkPaddleCollision(ball, paddle);
    checkBrickCollision(ball, brick);
    checkBorderCollision(ball, border);

    ball.move(ball.getDirection().x * m_ballSpeed * deltaTime,ball.getDirection().y * m_ballSpeed * deltaTime);
}

void PhysicsManager::checkPaddleCollision(Ball& ball, Paddle& paddle) {
    if (ball.getShape()->getGlobalBounds().intersects(paddle.getShape()->getGlobalBounds())) {
        float ballCenterX = ball.getShape()->getPosition().x + ball.getShape()->getRadius();
        float paddleCenterX = paddle.getShape()->getPosition().x + paddle.getShape()->getSize().x / 2.f;
        float relativeIntersectX = ballCenterX - paddleCenterX;
        float normalizedRelativeIntersectX = relativeIntersectX / (paddle.getShape()->getSize().x / 2.f);

        // Calculate bounce angle
        float angle = normalizedRelativeIntersectX * MAX_BOUNCE_ANGLE;
        ball.setDirection(sf::Vector2f(std::sin(angle), -std::cos(angle)));
    }
}

void PhysicsManager::checkBrickCollision(Ball& ball, Brick& brick) {
    for (int i = 0; i < Brick::ROW_COUNT; i++) {
        for (int j = 0; j < Brick::COLUMN_COUNT; j++) {
            if (ball.getShape()->getGlobalBounds().intersects(brick.getBrick(i).getGlobalBounds())) {
                // Collision with brick detected, change direction of ball
                float ballCenterX = ball.getShape()->getPosition().x + ball.getShape()->getRadius();
                float brickCenterX = brick.getBrick(i).getPosition().x + brick.getBrick(i).getSize().x / 2.f;
                float relativeIntersectX = ballCenterX - brickCenterX;
                float normalizedRelativeIntersectX = relativeIntersectX / (brick.getBrick(i).getSize().x / 2.f);

                // Calculate bounce angle
                float angle = normalizedRelativeIntersectX * MAX_BOUNCE_ANGLE;
                ball.setDirection(sf::Vector2f(std::sin(angle), -std::cos(angle)));

                // Destroy brick
                brick.deleteBrick(i);
            }
        }
    }
}

void PhysicsManager::checkBorderCollision(Ball& ball, Border& border) {
    if (ball.getShape()->getPosition().x - ball.getShape()->getRadius() <= border.getShape()->getGlobalBounds().left || 
        ball.getShape()->getPosition().x + ball.getShape()->getRadius() >= border.getShape()->getGlobalBounds().width) {
        ball.setDirection(sf::Vector2f(-ball.getDirection().x, ball.getDirection().y));
    }
    if (ball.getShape()->getPosition().y - ball.getShape()->getRadius() <= border.getShape()->getGlobalBounds().top) {
        ball.setDirection(sf::Vector2f(ball.getDirection().x, -ball.getDirection().y));
    }
}