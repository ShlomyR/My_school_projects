#include "brainfuck.hpp"

int main()
{
    BrainFuckInterpreter inter("++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.");

    inter.run();

    return 0;
}