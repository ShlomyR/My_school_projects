#include "../hederfiles/Queue.hpp"

#include <iostream>


void testing_all_cases()
{
    Queue q_1(3);
    q_1.push(1);
    q_1.push(2);
    q_1.push(3);
    std::cout << "First queue: front-> " << q_1.front() << '\n';  // should print 1
    q_1.pop();
    std::cout << "First queue: front-> " << q_1.front() << '\n';  // should print 2
    q_1.push(4);
    std::cout << "First queue: back-> " << q_1.back() << '\n';   // should print 4
    std::cout << "First queue: size-> " << q_1.size() << '\n';   // should print 3

    Queue q_2(q_1);
    std::cout << "Second queue: back-> " << q_2.back() << '\n';   // should print 4
    std::cout << "Second queue: size-> " << q_2.size() << '\n';   // should print 2
    q_2.pop();
    std::cout << "Second queue: front-> " << q_2.front() << '\n';  // should print 1
    std::cout << "Second queue: back-> " << q_2.back() << '\n';   // should print 4
    std::cout << "Second queue: size-> " << q_2.size() << '\n';   // should print 2
    Queue q_3;
    q_3 = q_2;
    std::cout << "Third queue: front-> " << q_3.front() << '\n';  // should print 1
    std::cout << "Third queue: back-> " << q_3.back() << '\n';   // should print 4
    std::cout << "Third queue: size-> " << q_3.size() << '\n';   // should print 2
    std::cout << "Third queue: capacity-> " << q_3.capacity() << '\n';   // should print 3
    q_3.push(5);
    q_3.push(6);
    q_3.pop();
    q_3.pop();
    q_3.pop();
    q_3.push(7);
    q_3.pop();
    q_3.pop();
}

int main()
{
    testing_all_cases();

    return 0;
}