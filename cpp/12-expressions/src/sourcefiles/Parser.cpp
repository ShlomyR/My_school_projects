#include <iostream>
#include <cctype>
#include <string>
#include <stack>


#include "../hederfiles/Parser.hpp"
#include "../hederfiles/Expression.hxx"
#include "../hederfiles/BinaryExpr.hpp"
#include "../hederfiles/Arithmetics.hpp"
#include "../hederfiles/NumberExpr.hpp"
// #include "Parser.hpp"

std::string::size_type Parser::m_index;

std::unique_ptr<Expression> calculatePostfix(std::string post_exp)
{
    std::stack<std::unique_ptr<Expression>> stack;
    int len = post_exp.length();

    for (int i = 0; i < len; i++) {
        if (post_exp[i] >= '0' && post_exp[i] <= '9') {
            std::string s = "";
            int n = int(post_exp[i] - '0');
            if (n == -16) {
                continue;
                ;
            }
            while (!isdigit(n)) {
                s += post_exp[i];
                i++;
                int n = int(post_exp[i] - '0');
                if (n == -16) {
                    break;
                }
            }
            n = stod(s);

            stack.push(std::make_unique<NumberExpr>(n));
        } else if (post_exp[i] == ' ') {
            continue;
        } else {
            std::unique_ptr<Expression> a = std::move(stack.top());
            stack.pop();
            std::unique_ptr<Expression> b = std::move(stack.top());
            stack.pop();
            switch (post_exp[i])
            {
            case '+': // addition
                stack.push(std::make_unique<ArithmeticOp::PlusExpr>(std::move(a), std::move(b)));
                break;
            case '-': // subtraction
                stack.push(std::make_unique<ArithmeticOp::MinExpr>(std::move(a), std::move(b)));
                break;
            case '*': // multiplication
                stack.push(std::make_unique<ArithmeticOp::MulExpr>(std::move(a), std::move(b)));
                break;
            case '/': // division
                stack.push(std::make_unique<ArithmeticOp::DivExpr>(std::move(a), std::move(b)));
                break;
            case '^': // exponent
                stack.push(std::make_unique<ArithmeticOp::PowerExpr>(std::move(a), std::move(b)));
                break;
            case '%': // modulo
                stack.push(std::make_unique<ArithmeticOp::ModuloExpr>(std::move(a), std::move(b)));
                break;
                // case 'sin': // sin
                //           stack.push(new SinExpr(a));
                //           break;
            }
        }
    }
    // returning the calculated result
    return std::move(stack.top());
}

void Parser::buildTree(std::string const &s)
{

}

std::unique_ptr<Expression> Parser::parse(std::string const &line)
{
    std::unique_ptr<Expression> e = calculatePostfix(line);
    return e;
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