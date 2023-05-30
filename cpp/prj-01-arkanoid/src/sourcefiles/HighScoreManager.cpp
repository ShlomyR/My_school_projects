#include "../hederfiles/HighScoreManager.hpp"


#include <fstream>

HighScoreManager::HighScoreManager()
{
    initializeFile();
}

void HighScoreManager::updateHighScore(sf::Event &event,size_t new_high_score,Hud &hud)
{
    //if (m_counter == 0) {
    m_givenName = " ";
    sf::Text inputField;
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128 && event.text.unicode != '\b' && event.text.unicode != '\r') {
            //if (m_givenName.length() < 10) {
                m_givenName += static_cast<char>(event.text.unicode);
                //inputField.setString(this->m_givenName);
                //hud.getInputFieldText().setString(this->m_givenName);
                //m_strName = m_givenName;
            //}
        }
        if (event.text.unicode == '\b') {
            if (m_givenName.length() > 0) {
                m_givenName.pop_back();
                //inputField.setString(this->m_givenName);
                hud.getInputFieldText().setString(this->m_givenName);
                // m_strName = m_givenName;
            }
        }
        if (event.text.unicode == '\r') {
            m_givenScore = new_high_score;
    
            data[0].name = m_givenName;
            data[0].score = m_givenScore;

            // Open the file for writing
            std::ofstream file_out("src/scores/top10.dat");
            file_out << data[0].name << " " << data[0].score << "\n";
            file_out.close();


            m_givenName = "";
            //m_strName = "";
            //m_counter = 1;
        }
    }
    // inputField.setPosition(50,50);
    // inputField.setCharacterSize(50);
}

void HighScoreManager::updateHighScoreToFile(size_t new_high_score)
{
    m_givenScore = new_high_score;
    
    data[0].score = m_givenScore;
    data[0].name = m_givenName;

    // Open the file for writing
    std::ofstream file_out("src/scores/top10.dat");
    for (int i = 0; i < 10; i++) {
        file_out << data[i].name << " " << data[i].score << "\n";
    }
    file_out.close();
}

size_t HighScoreManager::getFirstHighScore()
{
    return data[0].score;
}

std::string &HighScoreManager::getStringName()
{
    return m_givenName;
}

sf::Text &HighScoreManager::getInputString()
{
    return m_inputField;
}

void HighScoreManager::setIsHighScoreShown(bool value)
{
    m_isHighScoreShown = value;
}

bool HighScoreManager::getIsHighScoreShown()
{
    return m_isHighScoreShown;
}

void HighScoreManager::drew(sf::RenderWindow &window)
{
    window.draw(m_inputField);
}

void HighScoreManager::initializeFile()
{
    // Check if the file exists
    std::ifstream file_in("src/scores/top10.dat");
    if (!file_in.good()) {
        // Open file for writing
        std::ofstream file_out("src/scores/top10.dat");

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

    std::ifstream file_in2("src/scores/top10.dat");
    for(int i=0;i<10;i++){
        file_in2 >> data[i].name >> data[i].score;
    }
    file_in2.close();
}

void HighScoreManager::scoreNameTextLogic()
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

    m_scoreText.setString(scoresString);
}

void HighScoreManager::scoreScoresTextLogic()
{
    std::string scoresString = "";
    std::string space_score = "";

    for (int i = 0; i < 10; i++) {
        scoresString += space_score + std::to_string(data[i].score) +  "\n";       
    }

    m_titleText.setString(scoresString);
}
