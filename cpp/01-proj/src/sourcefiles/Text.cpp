#include "../hederfiles/Text.hpp"
#include "../hederfiles/GameManager.hpp"

void Text::init()
{
    TextManager::getInstance()->initVars();
    this->makeText(this->m_healthScoreText, this->m_font, sf::Color::Green, "NONE");
    this->makeText(this->m_gameOverText, this->m_font, sf::Color::Red, "");
    //this->makeText(this->m_currLevelText, this->m_font, sf::Color::Green, "NONE");
    this->makeText(this->m_spaceBarText, this->m_font, sf::Color::Green, "NONE");
    // this->makeText(this->m_highScoreText, this->m_font, sf::Color::Green, "NONE");
    // this->makeText(this->m_scoresText, this->m_font, sf::Color::Green, "NONE");
    // this->makeText(this->m_scoresText_2, this->m_font, sf::Color::Green, "NONE");
    // this->makeText(this->m_inputField, this->m_font, sf::Color::Green, "NONE");
}

void Text::initFonts()
{
    this->m_font.loadFromFile(TextManager::getInstance()->m_path);
}

void Text::renderText(std::unique_ptr<sf::RenderWindow> &target)
{
    target->draw(this->m_healthScoreText);
    target->draw(this->m_gameOverText);
    //target->draw(this->m_currLevelText);
    target->draw(this->m_spaceBarText);
    //target->draw(this->m_highScoreText);
}

void Text::makeText(
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

void Text::update()
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

    // this->updateText(
    //     str_curr_level,
    //     this->m_currLevelText,
    //     330,
    //     300,
    //     30,
    //     Texts::level
    // );

    this->updateText(
        str_space_bar,
        this->m_spaceBarText,
        170,
        350,
        25,
        Texts::space_bar
    );

    // this->updateText(
    //     str_high_score,
    //     this->m_highScoreText,
    //     300,
    //     10,
    //     25,
    //     Texts::high_score
    // );

    // this->updateText(
    //     str_scores,
    //     this->m_scoresText,
    //     100,
    //     150,
    //     30,
    //     Texts::high_names
    // );

    // this->updateText(
    //     str_scores,
    //     this->m_scoresText_2,
    //     600,
    //     150,
    //     30,
    //     Texts::high_scores
    // );

    // this->updateText(
    //     str_inputField,
    //     this->m_inputField,
    //     200,
    //     10,
    //     30,
    //     Texts::input
    // );
}

void Text::updateText(
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
        s_str << "Score: " << TextManager::getInstance()->m_score << "\n"
              << "Health: " << TextManager::getInstance()->m_health << "\n";
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
        TextManager::getInstance()->m_level;//Game::getInstance()->getCurrLevel() + 1;
        s_str << "LEVEL:  " << TextManager::getInstance()->m_level << "\n";
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
        if (TextManager::getInstance()->m_score < TextManager::getInstance()->m_highScore) {
            TextManager::getInstance()->m_highScore ;//= data[0].score;
        } else {
            TextManager::getInstance()->m_highScore = TextManager::getInstance()->m_score;
        }

        // this->m_highScore = data[0].score;
        s_str << "highScore: " << TextManager::getInstance()->m_highScore
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
        // if (TextManager::getInstance()->m_highScorePage && TextManager::getInstance()->m_counter == 0) {
        // this->m_strName = "Please enter you name: ";   
        // } else {
        //     this->m_strName = "";
        // }
        // s_str << this->m_strName << "\n"
        // << "           " << this->m_givenName << "\n";
        // text.setPosition(pos_x, pos_y);
        // text.setCharacterSize(charSize);
        // text.setString(s_str.str());
        break;
    }
}

void Text::gameOverTextLogic(
    std::stringstream &s_str,
    sf::Text &text,
    int pos_x,
    int pos_y,
    int charSize)
{
    if (TextManager::getInstance()->m_health == 0) {
        TextManager::getInstance()->m_counter = 0;
        text.setPosition(pos_x, pos_y);
        text.setCharacterSize(charSize);
        text.setString(s_str.str());
        if (TextManager::getInstance()->m_score < TextManager::getInstance()->m_highScore) {
            TextManager::getInstance()->m_highScore;// = data[0].score;
        } else {
            TextManager::getInstance()->m_highScorePage = true;  
        }
    } else {
        s_str << " ";
        text.setPosition(1000, 1000);
        text.setCharacterSize(0.05);
        text.setString(s_str.str());
    }
}

void Text::levelTextLogic(
    std::stringstream &s_str,
    sf::Text &text)
{
    if (GameManager::getInstance()->getBallManagerObj()->isPressed == false && TextManager::getInstance()->m_nextLev) {
        text.setString(s_str.str());
    } else {
        text.setPosition(-300, -300);
        text.setString(s_str.str());
    }
}

void Text::spaceBarTextLogic(
    std::stringstream &s_str,
    sf::Text &text)
{
    if (GameManager::getInstance()->getBallManagerObj()->isPressed == false && TextManager::getInstance()->m_gameStart) {
        text.setString(s_str.str());
    } else {
        s_str << " ";
        text.setPosition(1000, 1000);
        text.setCharacterSize(0.05);
        text.setString(s_str.str());
        TextManager::getInstance()->m_gameStart = false;
    }
}

void Text::scoreNameTextLogic(
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
        //scoresString += std::to_string(i+1) + "." + space_dot + data[i].name +  "\n";       
    }
    
    text.setString(scoresString);
}

void Text::scoreScoresTextLogic(
    sf::Text &text)
{
    std::string scoresString = "";
    std::string space_score = "";

    for (int i = 0; i < 10; i++) {
        //scoresString += space_score + std::to_string(data[i].score) +  "\n";       
    }
    
    text.setString(scoresString);
}
