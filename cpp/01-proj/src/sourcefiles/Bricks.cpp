#include <iostream>

// #include "Bricks.hpp"
#include "../hederfiles/Bricks.hpp"

void Bricks::init(std::unique_ptr<sf::RenderWindow> &)
{
    if(!this->m_tBrick.loadFromFile(this->m_filePath)) {
        std::cout << "Cant load texture brick!!! " << "\n";
    }
    this->m_sBrick->setColor(whichColor(this->m_color));
    m_n = 0;
    m_tempStr = "";
    m_vecDivStr = {};
    this->divString();
    this->m_row = stoi(m_vecDivStr[0]);
    this->m_colum = stoi(m_vecDivStr[1]);
    this->m_maxBricks = this->m_row*this->m_colum;
}

void Bricks::initSprite(std::unique_ptr<sf::RenderWindow> &)
{
    return;
}

void Bricks::update(std::unique_ptr<sf::RenderWindow> &)
{
    return;
}

void Bricks::spawnBricks()
{
    m_n = 0;

    for (int i = 0; i < this->m_row; i++) {
        for (int j = 0; j < this->m_colum; j++) {
            m_sBrick[m_n].setTexture(this->m_tBrick);
            m_sBrick[m_n].setPosition((i+0.5)* 45, (j+4) * 30);
            m_sBrick[m_n].setColor(whichColor(this->m_color));
            m_bricks.push_back(m_sBrick[m_n]);
            m_n++;
        }
    }
}

void Bricks::deleteBricks(int const i)
{
    if (this->m_bricks.empty()) {
        return ;
    }
       
    this->m_bricks.erase(this->m_bricks.begin() + i);
    this->m_sBrick[i].setPosition(-100, 0);
}

void Bricks::deleteBricks()
{
    while (m_bricks.size() != 0) {
        this->m_bricks.pop_back();
    }
}

void Bricks::render(std::unique_ptr<sf::RenderWindow> &target)
{
    for (auto &e : this->m_sBrick) {
        target->draw(e);
    }
}

void Bricks::divString()
{
    for (size_t i = 0; i < this->m_numOfBricks.length(); i++) {
        while (isdigit(this->m_numOfBricks[i])) {
            m_tempStr += this->m_numOfBricks[i];
            i++;
        }
        m_vecDivStr.push_back(m_tempStr);
        m_tempStr = "";
    }
}

std::string Bricks::getSound()
{
    return this->m_sound;
}

sf::Sprite Bricks::getSBrick(int const i)
{
    return m_sBrick[i];
}

sf::Color Bricks::whichColor(std::string color)
{
    if (color == "red") {
        return sf::Color::Red;
    } else if (color == "black") {
        return sf::Color::Black;
    } else if (color == "white") {
        return sf::Color::White;
    } else if (color == "green") {
        return sf::Color::Green;
    } else if (color == "blue") {
        return sf::Color::Blue;
    } else if (color == "yellow") {
        return sf::Color::Yellow;
    } else if (color == "magenta") {
        return sf::Color::Magenta;
    } else if (color == "cyan") {
        return sf::Color::Cyan;
    } else {
        throw std::runtime_error("Color not found!!!");
    } 
}

int Bricks::getN()
{
    return m_n;
}

int Bricks::getMaxBricks()
{
    return this->m_maxBricks *10;
}