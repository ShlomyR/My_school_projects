#include <iostream>
#include <sstream>

#include "../hederfiles/Game.hpp"
#include "../hederfiles/Menu.hpp"

//#include <SFML/Audio.hpp>

// #include "Menu.hpp"

void Menu::initMenu(sf::RenderTarget *target)
{
    if(!this->m_tMenu.loadFromFile(this->m_src)) {
        std::cout << "Cant load texture menu!!! " << "\n";
    }
    this->m_sMenu.setTexture(this->m_tMenu);
    this->m_font.loadFromFile("src/fonts/rexlia_rg.otf");

    this->makeText(
        this->m_startButtonText,
        this->m_font,
        sf::Color::Green,
        sf::Color::Blue,
        this->m_startButton,
        this->shape_start,
        2,
        3.8,
        target
    );
    this->makeText(
        this->m_optionsButtonText,
        this->m_font,
        sf::Color::Green,
        sf::Color::Blue,
        this->m_optionsButton,
        this->shape_options,
        2,
        2.3,
        target
    );
    this->makeText(
        this->m_highScoreButtonText,
        this->m_font,
        sf::Color::Green,
        sf::Color::Blue,
        this->m_highScoreButton,
        this->shape_high_score,
        2,
        1.65,
        target
    );
    this->makeText(
        this->m_exitButtonText,
        this->m_font,
        sf::Color::Green,
        sf::Color::Red,
        this->m_exitButton,
        this->shape_exit,
        2,
        1.3,
        target
    );

    this->start_count = 0;
    this->option_count = 0;
    this->high_score_count = 0;
    this->exit_count = 0;
   
    if (!buffer.loadFromFile("src/sounds/Menu_Selection_Click.wav")) {
        std::cout << "Cant load sound menu!!! " << "\n";
    }
    
    sound.setBuffer(buffer);
    //sound.setVolume(80);
    
    m_tempStr = "";
    m_vecDivStr = {};
    this->localPosition = {0,0};
    this->divString();
}

void Menu::spawnMenu(sf::RenderTarget*)
{
    this->localPosition = Game::getInstance()->mouse_position;
    this->checkEvent(this->shape_start,this->start_count,this->m_startButtonText,ButtonType::start_game);
    this->checkEvent(this->shape_options,this->option_count,this->m_optionsButtonText,ButtonType::option);
    this->checkEvent(this->shape_high_score,this->high_score_count,this->m_highScoreButtonText,ButtonType::high_score);
    this->checkEvent(this->shape_exit,this->exit_count,this->m_exitButtonText,ButtonType::exit);
}

void Menu::renderMenu(sf::RenderTarget* const target)
{
    target->draw(this->m_sMenu);
    target->draw(this->m_startButtonText);
    target->draw(this->m_optionsButtonText);
    target->draw(this->m_highScoreButtonText);
    target->draw(this->m_exitButtonText);
}

void Menu::divString()
{
    for (size_t i = 0; i < this->m_pos.length(); i++) {
        while (isdigit(this->m_pos[i])) {
            m_tempStr += this->m_pos[i];
            i++;
        }
        m_vecDivStr.push_back(m_tempStr);
        m_tempStr = "";
    }
}

const std::string Menu::getSound()
{
    return this->m_sound;
}


const sf::Color Menu::whichColor(std::string const color)
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

void Menu::makeText(
        sf::Text &text,
        const sf::Font &font,
        const sf::Color color,
        const sf::Color outlineColor,
        const std::string buttonName,
        sf::RectangleShape &Sp,
        const double pos_x,
        const double pos_y,
        sf::RenderTarget* const target
    )
{
    text.setFont(font);
    text.setCharacterSize(28);
    text.setFillColor(color);
    text.setOutlineColor(outlineColor);
    text.setString(buttonName);
    sf::Vector2u windowView = target->getSize();
    sf::FloatRect textBounds = text.getGlobalBounds();
    int posX = (windowView.x/pos_x) - (textBounds.width/pos_x);
    int posY = (windowView.y/pos_y) - (textBounds.height/pos_y);
    Sp.setPosition(sf::Vector2f(posX,posY));
    Sp.setFillColor(sf::Color::Transparent);
    Sp.setSize(sf::Vector2f(textBounds.width,textBounds.height));
    text.setPosition(
        Sp.getPosition().x,
        Sp.getPosition().y
    );

}

void Menu::checkEvent(sf::RectangleShape& Sp,int& count,sf::Text& text,ButtonType button)
{
    if (Sp.getGlobalBounds().contains(this->localPosition)) {
        if (count == 0) {
            this->sound.play();
            count = 1;
        }
        text.setOutlineThickness(2);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            switch (button)
            {
            case ButtonType::start_game :
                Game::getInstance()->m_isMenuOpen = false;
                break;
            case ButtonType::option :
                /* code */
                break;
            case ButtonType::high_score :
                Game::getInstance()->m_isMenuOpen = false;
                Game::getInstance()->m_isMenuHighScore = true;
                break;
            case ButtonType::exit :
                Game::getInstance()->closeWindow();
                break;
            }
        }
    } else {
        text.setOutlineThickness(0);
        count = 0;
    }
}