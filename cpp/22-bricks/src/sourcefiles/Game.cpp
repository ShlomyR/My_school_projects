#include <iostream>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
 


// #include "Game.hpp"

#include "../hederfiles/Game.hpp"
// #include "Game.hpp"
// #include "Game.hpp"

#define GameGet Game::getInstance()

Game::~Game()
{
    std::cout <<  "Score: " << this->m_catchScore << "\n";
    delete this->window;
    delete this->brick;
    delete this->menu;
    music.stop();
    if (t1->joinable()) {
        this->t1->detach();
        delete this->t1;
    }
    
    for (auto &i : this->m_vecBrickObj) {
        delete i;
    }

    for (auto &i : this->m_vecMenuObj) {
        delete i;
    }
}

Game *Game::getInstance()
{
    static Game m_instance;
    return &m_instance;   
}

void Game::start()
{
    this->initVariables();
    this->initWindow();
    this->initTexture();
    this->initSprite();
    this->t1  = new std::thread(init);
}

void Game::init()
{
    while (GameGet->running() && !GameGet->information->getEndGame()) {
        GameGet->update();
        GameGet->render();
    }

    if (!GameGet->window->isOpen()) {
        SymbolVar::getInstance()->map_strDB.at("isWinOpen") = "false";
    }
}

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev)) {
        if (this->ev.type == sf::Event::Closed) {
            this->m_catchScore = this->information->getScore();
            this->window->close();
        } if (this->ev.key.code == sf::Keyboard::Escape) {
            this->m_catchScore = this->information->getScore();
            this->m_isMenuOpen = true;
            this->m_isMenuHighScore = false;
            this->m_isUpdateHighScore = false;
            this->information->m_highScorePage = false;
            this->reset();
        
        } if (this->ev.type == sf::Event::TextEntered) {
            if (this->m_isUpdateHighScore) {
                this->information->updateHighScore(this->ev);
            }
            
        }
    }
}

void Game::update()
{   
    this->checkCurrentLevel(this->m_level);
    
    this->pollEvents();
    
    this->mouse_position = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
    
    if (!this->information->getEndGame()) {
        this->updateLevel();
        if (this->m_isMenuOpen) {
            this->m_vecMenuObj[0]->spawnMenu(this->window);
            this->paddle->updatePaddle(this->window);
            this->ball->updateBall();
            this->information->updateTexts();
        } else if (this->m_isMenuHighScore) {
            this->m_vecMenuObj[1]->spawnMenu(this->window);
            this->information->updateTexts();
        } else if (this->information->m_highScorePage) {
            this->m_isUpdateHighScore = true;
            this->m_vecMenuObj[1]->spawnMenu(this->window);
            this->information->updateTexts();
        } else {
            this->paddle->updatePaddle(this->window);
            this->ball->updateBall();
            this->information->updateTexts();
        }
    }
}

void Game::updateLevel()
{
    this->checkNextLevelTrue();
    this->checkNextLevel();
    //this->checkHighScore();
}

void Game::checkNextLevelTrue()
{
    if (this->validateScoreLv()) {
        this->m_nextLevel = true;
        this->ball->isPressed = false;
        this->m_level++;
        this->m_counter++;
    }
}

bool Game::validateScoreLv()
{
   return this->information->getScore()
    == 
    (this->m_vecBrickObj[this->m_currLevel]->getMaxBricks() * this->m_level) 
   && 
   this->m_counter == this->m_level -1;
}

void Game::checkNextLevel()
{
    if (this->m_level > this->m_maxLevel) {
        this->finishGame();
    } else if (this->m_nextLevel && this->m_nextLevel < this->m_maxLevel) {
        this->initBrick();
    }
    this->m_nextLevel = false;
    if (this->information->getScore() == this->m_vecBrickObj[this->m_currLevel]->getMaxBricks() * this->m_currLevel)
    {
        this->information->setNextLev(true);
    } else {
        this->information->setNextLev(false);
    }
    
}

void Game::finishGame()
{
    this->m_catchScore = this->information->getScore();
    this->information->setEndGame("true");
    SymbolVar::getInstance()->map_strDB.at("isWinOpen") = "false";
}

void Game::render()
{
    if (this->m_level > this->m_maxLevel) {
        return;
    }
    
    this->window->clear();
    if (this->m_isMenuOpen) {
        this->m_vecMenuObj[0]->renderMenu(this->window);
        this->bgMusic();
    } else if (this->m_isMenuHighScore) {
            this->m_vecMenuObj[1]->renderMenu(this->window);
            this->information->renderHighScore(this->window);
            this->bgMusic();
    } else if (this->information->m_highScorePage) {
            this->m_vecMenuObj[1]->renderMenu(this->window);
            this->information->renderHighScore(this->window);
            this->bgMusic();
    } else {
        this->resetBgMusic();
        this->renderBG();
        this->m_vecBrickObj[this->m_currLevel]->renderBlocks(this->window);
        this->paddle->renderPaddle(this->window);
        this->ball->renderBall(this->window);
        this->information->renderText(this->window);
    }
    this->window->display();
    if (this->information->getHealth() == 0) {
        sleep(3);
        this->information->setGameOver(false);
    }
}

void Game::bgMusic()
{
    if(!m_musicPlaying) {
        music.play();
        m_musicPlaying = true;
    }
    count += 0.005;
    if (count >= 6) {
        m_musicPlaying = false;
        count = 0;
    }
}

void Game::resetBgMusic()
{
    count = 0;
    m_musicPlaying = false;
    music.stop();
}

void Game::renderBG()
{
    this->window->draw(this->s_background);
}

bool Game::running()
{
    return this->window->isOpen();
}

void Game::closeWindow()
{
    this->window->close();
}

void Game::pause()
{
    sleep(1);
}

void Game::reset()
{
    this->m_paddleBound = this->paddle->getSprite().getGlobalBounds();

    this->m_counter = 0;
    this->m_level = 1;
    this->ball->isPressed = false;
    this->information->setGameStart(true);
    this->m_vecBrickObj[0]->initBricks();
    this->m_vecBrickObj[0]->spawnBricks();
    this->information->setHealth(5);
    this->information->m_givenScore = this->information->getScore();
    this->information->setScore(0);
    this->paddle->getSprite().setPosition(
        this->m_windowSize.x/2 - this->m_paddleBound.width/2,
        this->m_windowSize.y - this->m_paddleBound.height
    );
}

void Game::setObj(Bricks *obj)
{
    this->m_vecBrickObj.push_back(obj);
}

void Game::setObj(Menu *obj)
{
    this->m_vecMenuObj.push_back(obj);
    //this->menu = obj;
    // return obj;
}

Ball *&Game::setObj(Ball *&obj)
{
    this->ball = obj;
    return obj;
}

Paddle *&Game::setObj(Paddle *&obj)
{
    this->paddle = obj;
    return obj;
}

Information *&Game::setObj(Information *&obj)
{
    this->information = obj;
    return obj;
}

Bricks *&Game::getBrick()
{
    return this->brick;
}

Menu *&Game::getMenu()
{
    return this->menu;
}

Ball *&Game::getBall()
{
    return this->ball;
}

Paddle *&Game::getPaddle()
{
    return this->paddle;
}

Information *&Game::getInformation()
{
    return this->information;
}

std::vector<Bricks*>& Game::getVecObj()
{
    return this->m_vecBrickObj;
}

int Game::getLevel()
{
    return this->m_level;
}

int Game::incrementMaxLevel()
{
    return m_maxLevel++;
}

int Game::getCurrLevel()
{
    return this->m_currLevel;
}

void Game::checkCurrentLevel(int Current_level)
{
    this->m_currLevel = Current_level -1;
}

template <typename T>
void Game::stdCout(T print)
{
    std::cout << print << "\n";
}

void Game::initBrick()
{
    this->m_vecBrickObj[this->m_level - 1]->initBricks();
    this->m_vecBrickObj[this->m_level - 1]->spawnBricks();
}

void Game::initMenu()
{
    this->m_vecMenuObj[0]->initMenu(this->window);
    this->m_vecMenuObj[1]->initMenu(this->window);

    //this->m_vecMenuObj[this->m_level - 1]->spawnBricks();
}

void Game::initVariables()
{
    this->window = nullptr;
    this->t1 = nullptr;
    this->m_vecBrickObj = {};
    this->m_vecMenuObj = {};
    this->m_level = 1;
    this->m_nextLevel = false;
    this->m_isMenuOpen = true;
    this->m_isMenuHighScore = false;
    this->m_isUpdateHighScore = false;
    this->m_counter = 0;
    this->m_catchScore = 0;
    this->m_musicPlaying = false;
    this->count = 0;


    this->initBrick();
    
    this->ball->initBall();
    this->information->initVars();
    if (!buffer.loadFromFile("src/sounds/pop2.ogg")) {
        std::cout << "Cant load sound game!!! " << "\n";
    }
    
    sound.setBuffer(buffer);
    sound.setVolume(80);

    if (!music.openFromFile("src/sounds/b423b42.wav")) {
        std::cout << "Cant load sound music!!! " << "\n";
    }
    // this->information->highScoreRead();
    // this->information->highScoreWrite();
}

void Game::initWindow()
{
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    this->window = new sf::RenderWindow(this->videoMode, "Play the Game....!");
    this->window->setFramerateLimit(60);
    this->window->setPosition(sf::Vector2i(400,300));
    this->initMenu();
    this->m_windowSize = this->window->getSize();
}

void Game::initTexture()
{
    this->t_background.loadFromFile("src/images/wallpapersden.com_colorful-space_800x600.jpg");
    this->information->initFonts();
}


void Game::initSprite()
{
    this->s_background.setTexture(this->t_background);
    this->paddle->initSprite(this->window);
    this->ball->initSprite(this->window);
    this->information->initTexts();
}