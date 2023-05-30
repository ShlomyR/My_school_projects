#include <iostream>

#include "../hederfiles/Stack.hpp"

int main()
{

    Stack_1<double> sd(5);
    sd.push(1.5);
    sd.push(2.5);
    sd.push(3.5);
    sd.push(4.5);
    sd.push(5.5);

    std::cout << "Stack double size: " << sd.size() << std::endl;
    std::cout << "Stack double capacity: " << sd.capacity() << std::endl;
    std::cout << "Stack double top: " << sd.top() << std::endl;
    std::cout << "Stack double empty: " << (sd.empty() ? "true" : "false") << std::endl;

    Stack_1<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    std::cout << "Stack size: " << s.size() << std::endl;
    std::cout << "Stack capacity: " << s.capacity() << std::endl;
    std::cout << "Stack top: " << s.top() << std::endl;
    std::cout << "Stack empty: " << (s.empty() ? "true" : "false") << std::endl;
    //std::cout << "Stack full: " << (s.full() ? "true" : "false") << std::endl;

    s.pop();
    s.pop();

    std::cout << "Stack size: " << s.size() << std::endl;
    std::cout << "Stack top: " << s.top() << std::endl;

    Stack_1<int> s2(s);
    std::cout << "Stack 2 size: " << s2.size() << std::endl;

    Stack_1<int> s3(3);
    s3 = s;
    std::cout << "Stack 3 size: " << s3.size() << std::endl;
    return 0;
}