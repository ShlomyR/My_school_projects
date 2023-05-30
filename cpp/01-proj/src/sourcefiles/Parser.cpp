#include <iostream>
#include <cctype>

// #include "Parser.hpp"
// #include "Command.hpp"


#include "../hederfiles/Command.hxx"
#include "../hederfiles/Parser.hpp"



Parser::Parser()
{
    m_command_map["game_manager"] = new GameManagerCommand();
    m_command_map["brick"] = new BricksCommand();
    m_command_map["ball"] = new BallCommand();
    m_command_map["paddle"] = new PaddleCommand();
    m_command_map["window"] = new WindowCommand();
    m_command_map["++"] = new EqualMapCommand();
    m_command_map["var"] = new VerCommand();
    m_command_map["="] = new EqualMapCommand();
    m_command_map["while"] = new WhileCommand();
    m_command_map["if"] = new IfCommand();
    m_command_map["sleep"] = new SleepCommand();
    m_command_map["print"] = new PrintCommand();
}

Parser::~Parser()
{
    delete m_command_map.at("game_manager");
    delete m_command_map.at("brick");
    delete m_command_map.at("ball");
    delete m_command_map.at("paddle");
    delete m_command_map.at("window");
    delete m_command_map.at("++");
    delete m_command_map.at("var");
    delete m_command_map.at("=");
    delete m_command_map.at("while");
    delete m_command_map.at("if");
    delete m_command_map.at("sleep");
    delete m_command_map.at("print");
}

std::string::size_type Parser::m_index;

void Parser::parse(std::vector<std::vector<std::string>> const&arr)
{
    Parser::resetIndex();
    for (Parser::getIndex(); Parser::getIndex() < arr.size(); Parser::incrementIndex()) {
        Command *c;
        if (arr[Parser::getIndex()].empty() || arr[Parser::getIndex()][0] == " "|| arr[Parser::getIndex()][0] == "}" || arr[Parser::getIndex()][0] == "{") {
            continue;
        } else if (arr[Parser::getIndex()][1] == "++") {
            c = m_command_map.at(arr[Parser::getIndex()][1]);
        } else if (arr[Parser::getIndex()][1] == "=") {
            c = m_command_map.at(arr[Parser::getIndex()][1]);
        } else {
            c = m_command_map.at(arr[Parser::getIndex()][0]);
        }
        Parser::m_index += c->DoCommand(arr[Parser::getIndex()]);
    }
}

std::string::size_type Parser::getIndex()
{
    return m_index;
}

void Parser::incrementIndex()
{
    Parser::m_index++;
}

void Parser::resetIndex()
{
    Parser::m_index = 0;
}