#include <iostream>


// #include "Parser.hpp"
// #include "SymbolVar.hpp"
// #include "Game.hpp"
// #include "WhileLoop.hpp"
// #include "ifCondition.hpp"
// #include "Store.hpp"

#include "../hederfiles/Parser.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/WhileLoop.hpp"
#include "../hederfiles/ifCondition.hpp"
#include "../hederfiles/GameManager.hpp"
#include "../hederfiles/Window.hpp"

// #include "Command.hpp"
// #include "../hederfiles/Store.hpp"

int GameManagerCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line[1] == "init()") {
        GameManager::getInstance()->start();
    } else if (line[1] == "pause()") {
        GameManager::getInstance()->pause();
    } else if (line[1] == "reset()") {
        GameManager::getInstance()->reset();
    } else {
        throw std::runtime_error("Command not found");
    }
    return 0;
}

int BricksCommand::DoCommand(std::vector<std::string> const&line)
{
    std::string color = line[1];
    std::string num_of_bricks = line[2]; 
    std::string num_of_hits = line[3];
    std::string sound = line[4];
    std::string file_path = line[5];

    this->bricks = std::make_unique<Bricks>(WhileCommand::getStringVal(color),
                            WhileCommand::getStringVal(num_of_bricks),
                            WhileCommand::getVal(num_of_hits),
                            WhileCommand::getStringVal(sound),
                            WhileCommand::getStringVal(file_path)
                            );

    GameManager::getInstance()->setObj(this->bricks);

    return 0;
}

int BallCommand::DoCommand(std::vector<std::string> const&line)
{
    this->ball = std::make_unique<Ball>(WhileCommand::getStringVal(line[1]));

    GameManager::getInstance()->setObj(this->ball);

    return 0;
}

int PaddleCommand::DoCommand(std::vector<std::string> const&line)
{
    this->paddle = std::make_shared<Paddle>(WhileCommand::getStringVal(line[1]));

    GameManager::getInstance()->setObj(this->paddle);

    return 0;
}

int WindowCommand::DoCommand(std::vector<std::string> const&line)
{
    this->window =  std::make_unique<Window>(WhileCommand::getVal(line[1]),WhileCommand::getVal(line[2]));

    GameManager::getInstance()->setObj(this->window);

    return 0;
}

int VerCommand::DoCommand(std::vector<std::string> const&line)
{
    SymbolVar::getInstance()->createVar(line);
    
    return 0;
}

int EqualMapCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line.size() == 3) {
       updateFromDB(line);
    } else if (line[1] == "++") {
        int tempIncrement = SymbolVar::getInstance()->map_doubleDB.at(line[0]);
        SymbolVar::getInstance()->map_doubleDB.at(line[0]) = ++tempIncrement;
    } else {
        SymbolVar::getInstance()->createVar(line);
    }

    return 0;
}


int WhileCommand::DoCommand(std::vector<std::string> const&line)
{
    int temp_row_num = Parser::getIndex()+1;
    WhileLoop::whileLoop(line);
    return temp_row_num;
}

int IfCommand::DoCommand(std::vector<std::string> const&line)
{
    int temp_row_num = Parser::getIndex()+1;
    ifCondition::ifCon(line);
    return temp_row_num;
}

int SleepCommand::DoCommand(std::vector<std::string> const&line)
{
    sleepFunc(line[1]);
    return 0;
}


int PrintCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line.size() > 2) {
        printCurly(line);
    } else {
        printFunc(line[1]);
    }

    return 0;
}