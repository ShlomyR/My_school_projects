#include "Matrix.hpp"

int main()
{
    Matrix m(10,8);
    m.at(3,7) = 101;

    std::cout << m.at(3,7)  << '\n';

    m[8] = 5;

    std::cout << m.at(1,0)  << '\n';

    Matrix once(10,8,2);

    std::cout << once.at(1,1)  << '\n';
    std::cout << once.at(2,2)  << '\n';

    m.at(3,1) = 771;
    once.at(2,2) = 78;
    
    std::cout << m.at(3,1)  << '\n';
    
    std::cout << once.at(2,2)  << '\n';

    once.count(78);

    Matrix num1(4,2,1), num2(4,2,2);
    
   
    

    // add two objects
    auto sum = num1 + num2;

    std::cout << sum.at(1,1) << "\n";

    return 0;
}