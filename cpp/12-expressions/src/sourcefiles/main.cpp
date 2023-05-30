#include <iostream>
#include <vector>
#include <string>

#include "../hederfiles/Expression.hxx"
#include "../hederfiles/BinaryExpr.hpp"
#include "../hederfiles/Arithmetics.hpp"
#include "../hederfiles/NumberExpr.hpp"

#include "../hederfiles/Lexer.hpp"
#include "../hederfiles/Parser.hpp"
#include "../hederfiles/Rpn.hpp"


#define PATH "script/Script.txt"

int main(int argc, char *argv[])
{
    std::string file_name;

    if (argc > 1) {
        file_name = argv[1];
    } else {
        file_name = PATH;
    }
    Lexer lexer(file_name);

    std::vector<std::string> tokens = lexer.doLexer();
    Rpn rpn_obj(tokens);
    auto rpn = rpn_obj.infixToPostfix();

    Parser parse;

    for (size_t i = 0; i < tokens.size(); i++) {
        std::cout << "Postfix: " << tokens[i] << "\n";
        std::cout << "Infix: " << rpn[i] << "\n";
        std::unique_ptr<Expression> tree = parse.parse(rpn[i]);
        std::cout << "Result: ";
        tree->print(tree->calc());
        std::cout << "\n";
    }
    return 0;
}