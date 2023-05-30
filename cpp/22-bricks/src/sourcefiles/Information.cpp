#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>

// #include "Information.hpp"

#include "../hederfiles/Information.hpp"
#include "../hederfiles/Game.hpp"
// #include "Information.hpp"

void Information::setScore(int val)
{
    this->m_score = val;
}

void Information::setHighScore(int val)
{
    this->m_highScore = val;
}

int Information::setHealth(int val)
{
    SymbolVar::getInstance()->map_doubleDB.at("health") = val;
    return this->m_health = val;
}

bool Information::setEndGame(std::string str)
{
    SymbolVar::getInstance()->map_strDB.at("endGame") = str;
    return m_endGame = true;
}

void Information::setGameStart(bool boolean)
{
    this->m_gameStart = boolean;
}

void Information::setNextLev(bool boolean)
{
    this->m_nextLev = boolean;
}

bool Information::getGameOver()
{
    return this->m_gameOver;
}

void Information::setGameOver(bool type)
{
    this->m_gameOver = type;
}

const std::vector<std::string> Information::splitByWord(std::string const &str, const char Delim)
{
    std::string token;
    std::stringstream stream(str);
    std::vector<std::string> vec_str;

    while (getline(stream, token, Delim))
    {
        vec_str.push_back(token);
    }
    return vec_str;
}

int Information::currScore()
{
    return this->m_highScore;
}

int Information::oldScore()
{
    return this->m_score;
}

void Information::initializeFile()
{
    // Check if the file exists
    std::ifstream file_in("src/HighScore/scores.txt");
    if (!file_in.good()) {
        // Open file for writing
        std::ofstream file_out("src/HighScore/scores.txt");

        // Initialize the data with the initial values
        for (int i = 0; i < 10; i++) {
            data[i].name = "00000";
            data[i].score = 0;
            file_out << data[i].name << " " << data[i].score << "\n";
        }
        file_out.close();
    } else {
        file_in.close();
    }

    std::ifstream file_in2("src/HighScore/scores.txt");
    for(int i=0;i<10;i++){
        file_in2 >> data[i].name >> data[i].score;
    }
    file_in2.close();
    
}

int Information::getScore()
{
    return this->m_score;
}


int Information::getHealth()
{
    return this->m_health;
}

bool Information::getEndGame()
{
    return this->m_endGame;
}

void Information::decreaseHealth()
{
    SymbolVar::getInstance()->map_doubleDB.at("health") = --(this->m_health);
}

void Information::initFonts()
{
    this->m_font.loadFromFile(this->m_path);
}

void Information::initTexts()
{
    this->makeText(this->m_healthScoreText, this->m_font, sf::Color::Green, "NONE");
    this->makeText(this->m_gameOverText, this->m_font, sf::Color::Red, "");
    this->makeText(this->m_currLevelText, this->m_font, sf::Color::Green, "NONE");
    this->makeText(this->m_spaceBarText, this->m_font, sf::Color::Green, "NONE");
    this->makeText(this->m_highScoreText, this->m_font, sf::Color::Green, "NONE");
    this->makeText(this->m_scoresText, this->m_font, sf::Color::Green, "NONE");
    this->makeText(this->m_scoresText_2, this->m_font, sf::Color::Green, "NONE");
    this->makeText(this->m_inputField, this->m_font, sf::Color::Green, "NONE");
}

void Information::initVars()
{
    this->m_gameStart = true;
    this->m_nextLev = true;
    this->m_gameOver = false;
    this->m_highScorePage = false;
    this->m_counter = 0;
    this->m_strName = "";
    
    this->initializeFile();
}

void Information::updateTexts()
{
    std::stringstream str_health_Score;
    std::stringstream str_game_over;
    std::stringstream str_curr_level;
    std::stringstream str_space_bar;
    std::stringstream str_high_score;
    std::stringstream str_scores;
    std::stringstream str_inputField;

    this->updateText(
        str_health_Score,
        this->m_healthScoreText,
        10,
        10,
        28,
        Texts::health_Score
    );

    this->updateText(
        str_game_over,
        this->m_gameOverText,
        250,
        300,
        40,
        Texts::game_over
    );

    this->updateText(
        str_curr_level,
        this->m_currLevelText,
        330,
        300,
        30,
        Texts::level
    );

    this->updateText(
        str_space_bar,
        this->m_spaceBarText,
        170,
        350,
        25,
        Texts::space_bar
    );

    this->updateText(
        str_high_score,
        this->m_highScoreText,
        300,
        10,
        25,
        Texts::high_score
    );

    this->updateText(
        str_scores,
        this->m_scoresText,
        100,
        150,
        30,
        Texts::high_names
    );

    this->updateText(
        str_scores,
        this->m_scoresText_2,
        600,
        150,
        30,
        Texts::high_scores
    );

    this->updateText(
        str_inputField,
        this->m_inputField,
        200,
        10,
        30,
        Texts::input
    );

}

void Information::renderText(sf::RenderTarget *target)
{
    target->draw(this->m_healthScoreText);
    target->draw(this->m_gameOverText);
    target->draw(this->m_currLevelText);
    target->draw(this->m_spaceBarText);
    target->draw(this->m_highScoreText);
}

void Information::renderHighScore(sf::RenderTarget *target)
{
    target->draw(this->m_scoresText);
    target->draw(this->m_scoresText_2);
    target->draw(this->m_inputField);
}

void Information::increaseHealth()
{
    SymbolVar::getInstance()->map_doubleDB.at("score") = this->m_score += 10;
}

void Information::makeText(
    sf::Text &text,
    const sf::Font &font,
    const sf::Color color,
    const std::string Name)
{
    text.setFont(font);
    text.setCharacterSize(28);
    text.setFillColor(color);
    text.setString(Name);
}

void Information::updateText(
    std::stringstream &s_str,
    sf::Text &text,
    int pos_x,
    int pos_y,
    int charSize,
    Texts texts
    )
{
    switch (texts)
    {
    case Texts::health_Score:
        s_str << "Score: " << this->m_score << "\n"
              << "Health: " << this->m_health << "\n";
        text.setPosition(pos_x, pos_y);
        text.setCharacterSize(charSize);
        text.setString(s_str.str());
        break;
    case Texts::game_over:
        s_str << "GAME OVER!!! "
              << "\n";
        text.setPosition(pos_x, pos_y);
        text.setCharacterSize(charSize);
        this->gameOverTextLogic(s_str, text, pos_x, pos_y, charSize);
        
        break;
    case Texts::level:
        this->m_level = Game::getInstance()->getCurrLevel() + 1;
        s_str << "LEVEL:  " << this->m_level << "\n";
        text.setPosition(pos_x, pos_y);
        text.setCharacterSize(charSize);
        this->levelTextLogic(s_str, text);
        break;
    case Texts::space_bar:
        s_str << "please press the space bar to start"
              << "\n";
        text.setPosition(pos_x, pos_y);
        text.setCharacterSize(charSize);
        this->spaceBarTextLogic(s_str, text);
        break;
    case Texts::high_score:
        if (this->m_score < this->m_highScore) {
            this->m_highScore = data[0].score;
        } else {
            this->m_highScore = this->m_score;
        }

        // this->m_highScore = data[0].score;
        s_str << "highScore: " << this->m_highScore
              << "\n";
        text.setPosition(pos_x, pos_y);
        text.setCharacterSize(charSize);
        text.setString(s_str.str());
        break;
    case Texts::high_names:   
        text.setPosition(pos_x, pos_y);
        text.setCharacterSize(charSize);
        this->scoreNameTextLogic(text);
        break;
    case Texts::high_scores:
        text.setPosition(pos_x, pos_y);
        text.setCharacterSize(charSize);
        this->scoreScoresTextLogic(text);
        break;
    case Texts::input:
        if (this->m_highScorePage && this->m_counter == 0) {
        this->m_strName = "Please enter you name: ";   
        } else {
            this->m_strName = "";
        }
        s_str << this->m_strName << "\n"
        << "           " << this->m_givenName << "\n";
        text.setPosition(pos_x, pos_y);
        text.setCharacterSize(charSize);
        text.setString(s_str.str());
        break;
    }
}

void Information::gameOverTextLogic(
    std::stringstream &s_str,
    sf::Text &text,
    int pos_x,
    int pos_y,
    int charSize)
{
    if (this->m_health == 0) {
        this->m_counter = 0;
        text.setPosition(pos_x, pos_y);
        text.setCharacterSize(charSize);
        text.setString(s_str.str());
        if (this->m_score < this->m_highScore) {
            this->m_highScore = data[0].score;
        } else {
            this->m_highScorePage = true;  
        }
        // this->m_gameOver = true;
    } else {
        s_str << " ";
        text.setPosition(1000, 1000);
        text.setCharacterSize(0.05);
        text.setString(s_str.str());
    }
}

void Information::levelTextLogic(
    std::stringstream &s_str,
    sf::Text &text)
{
    if (Game::getInstance()->getBall()->isPressed == false && this->m_nextLev) {
        text.setString(s_str.str());
    } else {
        text.setPosition(-300, -300);
        text.setString(s_str.str());
    }
}

void Information::spaceBarTextLogic(
    std::stringstream &s_str,
    sf::Text &text)
{
    if (Game::getInstance()->getBall()->isPressed == false && this->m_gameStart) {
        text.setString(s_str.str());
    } else {
        s_str << " ";
        text.setPosition(1000, 1000);
        text.setCharacterSize(0.05);
        text.setString(s_str.str());
        this->m_gameStart = false;
    }
}

void Information::scoreNameTextLogic(
    sf::Text &text)
{
    std::string scoresString = "";
    std::string space_dot = "";

    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            space_dot = "   ";
        } else if (i == 9) {
            space_dot = " ";
        } else {
            space_dot = "  ";
        }
        scoresString += std::to_string(i+1) + "." + space_dot + data[i].name +  "\n";       
    }
    
    text.setString(scoresString);
}

void Information::scoreScoresTextLogic(
    sf::Text &text)
{
    std::string scoresString = "";
    std::string space_score = "";

    for (int i = 0; i < 10; i++) {
        scoresString += space_score + std::to_string(data[i].score) +  "\n";       
    }
    
    text.setString(scoresString);
}

void Information::updateHighScore(sf::Event& event)
{
    
    if (this->m_counter == 0) {
        
        if (event.text.unicode < 128 && event.text.unicode != '\b' && event.text.unicode != '\r') {
            if (this->m_givenName.length() < 10) {
                this->m_givenName += static_cast<char>(event.text.unicode);
                this->m_inputField.setString(this->m_givenName);
            }
        }
        if (event.text.unicode == '\b') {
            if (this->m_givenName.length() > 0) {
                this->m_givenName.pop_back();
                this->m_inputField.setString(this->m_givenName);
            }
        }
        if (event.text.unicode == '\r') {
            // Check if the given score is greater than any score in the array
            int index = -1;
            for(int i=0;i<10;i++){
                if(data[i].score < this->m_givenScore){
                    if(index==-1) index = i; // first occurrence
                    else if(this->m_givenScore > data[index].score) index = i;
                }
            }
            
            // Update the score and name in the array
            if(index != -1){
                data[index].score = this->m_givenScore;
                data[index].name = this->m_givenName;
            }

            // sort the data array in descending order
            for(int i = 0; i < 9; i++) {
                for(int j = i+1; j < 10; j++) {
                    if(data[i].score < data[j].score) {
                        std::swap(data[i], data[j]);
                    }
                }
            }

            // Open the file for writing
            std::ofstream file_out("src/HighScore/scores.txt");
            for (int i = 0; i < 10; i++) {
                file_out << data[i].name << " " << data[i].score << "\n";
            }
            file_out.close();


            this->m_givenName = "";
            this->m_strName = "";
            this->m_counter = 1;
        } 
    }
}