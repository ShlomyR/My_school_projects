#pragma once

#include <string>

#include <SFML/Graphics.hpp>


class Menu
{
public:
    explicit Menu(
        const std::string src,
        const std::string button_1,
        const std::string button_2,
        const std::string button_3,
        const std::string button_4,
        const std::string color,
        const std::string pos
    )
    :   m_src(src),
        m_startButton(button_1),
        m_optionsButton(button_2),
        m_highScoreButton(button_3),
        m_exitButton(button_4),
        m_color(color),
        m_pos(pos)
    {}
    explicit Menu(const std::string src)
    :   m_src(src)
    {}
    ~Menu()
    {
        //sound.stop();
        //buffer.~SoundBuffer();
    }
void initMenu(sf::RenderTarget* const);
void spawnMenu(sf::RenderTarget* const);
void renderMenu(sf::RenderTarget* const);
void divString();
const std::string getSound();
const sf::Color whichColor(std::string const);

private:
    void makeText(
        sf::Text&,
        const sf::Font&,
        const sf::Color,
        const sf::Color,
        const std::string,
        sf::RectangleShape&,
        const double,
        const double,
        sf::RenderTarget* const
    );
    enum ButtonType {
        start_game = 0,
        option,
        high_score,
        exit
    };
    void checkEvent(
        sf::RectangleShape&,
        int&,
        sf::Text&,
        ButtonType
    );

private:
    std::string m_src;
    std::string m_startButton;
    std::string m_optionsButton;
    std::string m_highScoreButton;
    std::string m_exitButton;
    std::string m_color;
    std::string m_pos;
    std::string m_sound;
    sf::Texture m_tMenu;
    sf::Sprite m_sMenu;
    std::string m_tempStr;
    std::vector<std::string> m_vecDivStr;
    sf::Font m_font;
    sf::Text m_startButtonText;
    sf::Text m_optionsButtonText;
    sf::Text m_highScoreButtonText;
    sf::Text m_exitButtonText;
    sf::RectangleShape shape_start;
    sf::RectangleShape shape_options;
    sf::RectangleShape shape_high_score;
    sf::RectangleShape shape_exit;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Vector2f localPosition;

    
    int start_count;
    int option_count;
    int high_score_count;
    int exit_count;
};