#include "../hederfiles/Vector.hpp"

#include <iostream>
#include <vector>

void testing_all_cases()
{
    Vector v(3);
    std::cout << "First vector: size-> : " << v.size() << '\n';  // should print 0
    v.push_front(1);
    v.push_front(2);
    v.push_front(3);
    std::cout << "First vector: size-> : " << v.size() << '\n';  // should print 3
    v.pop_back();
    std::cout << "First vector: size-> : " << v.size() << '\n';  // should print 2
    v.push_front(4);
    v.push_back(5);
    std::cout << "First vector: back-> : " << v.back() << '\n';   // should print 4
    std::cout << "First vector: front-> : " << v.front() << '\n';   // should print 5
    std::cout << "First vector: size-> : " << v.size() << '\n';   // should print 4
    std::cout << "First vector: capacity-> : " << v.capacity() << '\n';   // should print 4
    std::cout << "\n";
    Vector v1(v);
    std::cout << "Second vector: back-> : " << v1.back() << '\n';   // should print 4
    std::cout << "Second vector: front-> : " << v1.front() << '\n';   // should print 5
    std::cout << "Second vector: size-> : " << v1.size() << '\n';   // should print 4
    std::cout << "Second vector: capacity-> : " << v1.capacity() << '\n';   // should print 4
    for (int i = 0; i < v.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n\n";

    Vector v2;
    v2 = v1;
    std::cout << "Third vector: back-> : " << v2.back() << '\n';   // should print 4
    std::cout << "Third vector: front-> : " << v2.front() << '\n';   // should print 5
    std::cout << "Third vector: size-> : " << v2.size() << '\n';   // should print 4
    std::cout << "Third vector: capacity-> : " << v2.capacity() << '\n';   // should print 4

    v.print();
}

int main()
{
    
    testing_all_cases();

    return 0;
}