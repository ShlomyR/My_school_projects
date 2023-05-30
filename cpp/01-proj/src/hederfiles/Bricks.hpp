#pragma once

#include <SFML/Audio.hpp>
#include<SFML/Graphics.hpp>

#include "Interface.hxx"

#include <vector>

#define SIZE 85

class Bricks : public Interface_grandson
{
public:
    explicit Bricks(const std::string color,const std::string numOfBricks,const int numOfHits,const std::string sound,const std::string filePath)
    :   m_color(color),
        m_numOfBricks(numOfBricks),
        m_numOfHits(numOfHits),
        m_sound(sound),
        m_filePath(filePath)
    {}
public:
    void spawnBricks();
    void init(std::unique_ptr<sf::RenderWindow> &) override ;
    void initSprite(std::unique_ptr<sf::RenderWindow> &) override;
    void update(std::unique_ptr<sf::RenderWindow> &) override;
    void render(std::unique_ptr<sf::RenderWindow> &) override;
    void deleteBricks(const int);
    void deleteBricks();

    int getMaxBricks();
    std::string getSound();
    sf::Sprite getSBrick(const int);
    
    int getN();
private:
    void divString();
    sf::Color whichColor(const std::string);
private:
    std::string m_color;
    std::string m_numOfBricks;
    int m_numOfHits;
    std::string m_sound;
    std::string m_filePath;
    sf::Texture m_tBrick;
    std::vector<sf::Sprite> m_bricks;
    std::string m_tempStr;
    std::vector<std::string> m_vecDivStr;
    size_t m_maxBricks;
    int m_n;
    int m_row;
    int m_colum;
    sf::Sprite m_sBrick[SIZE];
};