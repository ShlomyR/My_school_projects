#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Menu.hpp"
#include "Bricks.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Information.hpp"
#include "SymbolVar.hpp"

#include <thread>

class Game
{
public:
    virtual ~Game();
    static Game* getInstance();
    void start();
    void pause();
    void reset();

    void setObj(Bricks*);
    void setObj(Menu*);
    Ball *&setObj(Ball*&);
    Paddle *&setObj(Paddle*&);
    Information *&setObj(Information*&);

    Menu *&getMenu();
    Ball *&getBall();
    Paddle *&getPaddle();
    Information *&getInformation();
    std::vector<Bricks*>& getVecObj();
    int getCurrLevel();
    int incrementMaxLevel();
    void closeWindow();
    sf::Vector2f mouse_position;
    bool m_isMenuOpen;
    bool m_isMenuHighScore;
    bool m_isUpdateHighScore;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Music music;

private:
    Game() {}
    static void init();
    void pollEvents();
    void update();
    void render();
    void renderBG();
    bool running();
    void checkCurrentLevel(int);
    Bricks *&getBrick();
    int getLevel();
    void initVariables();
    void initWindow();
    void initBrick();
    void initMenu();
    void initTexture();
    void initSprite();
    void updateLevel();
    void checkNextLevelTrue();
    void checkNextLevel();
    void checkHighScore();
    bool validateScoreLv();
    void finishGame();
    void bgMusic();
    void resetBgMusic();

    template<typename T>
    void stdCout(T);
private:
    Menu* menu;
    Bricks* brick;
    Ball* ball;
    Paddle* paddle;
    Information* information;
    Menu* highScores;

    //window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //picture
    sf::Texture t_background;
    //sprite?
    sf::Sprite s_background;

    std::thread* t1;

    std::vector<Bricks*> m_vecBrickObj;
    std::vector<Menu*> m_vecMenuObj;
    sf::Vector2u m_windowSize;
    sf::FloatRect m_paddleBound;

    bool m_nextLevel;
    bool m_musicPlaying;
    bool m_gameOver;
    bool m_highScore;
    int m_counter;
    int m_level;
    int m_currLevel;
    int m_catchScore;
    int m_maxLevel = 0;
    double count;

};

// class IGame {
// public:
//     virtual ~IGame() {}
//     virtual void start() = 0;
//     virtual void pause() = 0;
//     virtual void reset() = 0;
// };

// class IGameObjManagement {
// public:
//     virtual void setBricks(Bricks*) = 0;
//     virtual void setMenu(Menu*) = 0;
//     virtual void setBall(Ball*&) = 0;
//     virtual void setPaddle(Paddle*&) = 0;
//     virtual void setInformation(Information*&) = 0;
//     virtual Bricks* getBricks() = 0;
//     virtual Menu* getMenu() = 0;
//     virtual Ball* getBall() = 0;
//     virtual Paddle* getPaddle() = 0;
//     virtual Information* getInformation() = 0;
//     virtual std::vector<Bricks*>& getBrickVector() = 0;
// };

// class ILevelManagement {
// public:
//     virtual int getCurrentLevel() = 0;
//     virtual int incrementMaxLevel() = 0;
//     virtual void checkCurrentLevel(int) = 0;
//     virtual void updateLevel() = 0;
// };

// class IGameWindowManagement {
// public:
//     virtual void closeWindow() = 0;
//     virtual sf::Vector2f getMousePosition() = 0;
//     virtual bool isMenuOpen() = 0;
//     virtual bool isMenuHighScore() = 0;
//     virtual bool isUpdateHighScore() = 0;
// };

// class IGameSoundManagement {
// public:
//     virtual sf::Sound& getSound() = 0;
//     virtual sf::Music& getMusic() = 0;
// };

// class Game : public IGame, public IGameObjManagement, public ILevelManagement, public IGameWindowManagement, public IGameSoundManagement {
// public:
//     Game() {}
//     virtual ~Game() {}
//     static Game* getInstance();
//     void start() override;
//     void pause() override;
//     void reset() override;
//     void setBricks(Bricks*) override;
//     void setMenu(Menu*) override;
//     void setBall(Ball*&) override;
//     void setPaddle(Paddle*&) override;
//     void setInformation(Information*&) override;
//     Bricks* getBricks() override;
//     Menu* getMenu() override;
//     Ball* getBall() override;
//     Paddle* getPaddle() override;
//     Information* getInformation() override;
//     std::vector<Bricks*>& getBrickVector() override;
//     int getCurrentLevel() override;
//     int incrementMaxLevel() override;
//     void checkCurrentLevel(int) override;
//     void updateLevel() override;
//     void closeWindow() override;
//     sf::Vector2f getMousePosition() override;
//     bool isMenuOpen() override;
//     bool isMenuHighScore() override;
//     bool isUpdateHighScore() override;
//     sf::Sound& getSound() override;
//     sf::Music& getMusic() override;
// private:
//     void initVariables();
//     void initWindow();
//     void initBrick();
//     void initMenu();
//     void initTexture();
//     void initSprite();
//     void pollEvents();
//     void update();
//     void render();
//     void renderBG();
//     bool running();
//     Bricks* m_bricks;
//     Menu* m_menu;
//     Ball* m_ball;
//     Paddle* m_paddle;
//     Information* m_information;
//     Menu* m_highScores;
//     sf::RenderWindow* m_window;
//     sf::VideoMode m_videoMode;
//     sf::Event m_ev;
//     sf::Texture m_tBackground;
   


// #include "GameLogic.hxx"
// #include "GameRendering.hxx"
// #include "GameInput.hxx"
// #include "Window.hxx"

// #include <thread>

// class Game
// {
// public:
//     explicit Game(GameLogic *gameLogic
//         ,IGameRendering *gameRendering
//         , IGameInput *gameInput
//         ,sf::RenderWindow *window
//     )
//     :   m_gameLogic(gameLogic)
//     ,   m_gameRendering(gameRendering)
//     ,   m_gameInput(gameInput)
//     ,   m_window(window)
//     {}

//     static Game *getInstance();

//     static void run();
// private:
//     Game() {}
//     void init();
//     void closeWindow();
// private:
//     GameLogic *m_gameLogic;
//     IGameRendering *m_gameRendering;
//     IGameInput *m_gameInput;
//     sf::RenderWindow *m_window;
//     sf::Event m_event;

//     bool m_running = true;

//     std::thread *m_t1;
// };