#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Command.hxx"
#include "Bricks.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Window.hpp"

class GameManagerCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
};

class BricksCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    std::unique_ptr<Bricks> bricks;
};

class BallCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    std::unique_ptr<Ball> ball;
};

class PaddleCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    std::shared_ptr<Paddle> paddle;
};

class WindowCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    std::unique_ptr<Window> window;
};

class VerCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
};

class EqualMapCommand : public Command
{
public:    
    int DoCommand(std::vector<std::string> const&) override;
private:
    void updateFromDB(std::vector<std::string> const&);
    void convertFromChToNum(std::vector<std::string> const&);
};

class WhileCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
    static double getVal(std::vector<std::string> const&);
    static double getVal(std::string const&);
    static std::string getStringVal(std::vector<std::string> const&);
    static std::string getStringVal(std::string const&);
};

class IfCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void ifFunc(std::string);
};

class SleepCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void sleepFunc(std::string);
};

class PrintCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void printFunc(std::string const);
    void printCurly(std::vector<std::string> const&);
};

class BreakCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void breakFunc(std::vector<std::string> const&);
};