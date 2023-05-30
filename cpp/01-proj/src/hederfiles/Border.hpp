#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "BallManager.hpp"
#include "TextManager.hpp"
#include "Bricks.hpp"

struct Border
{
    void windowBorderDetection(
        std::unique_ptr<BallManager> &
        ,sf::FloatRect &
    );
    void ballCollideWithBrick(
        std::unique_ptr<Bricks> &
        ,std::unique_ptr<BallManager> &
        ,sf::FloatRect &
    );
    
};