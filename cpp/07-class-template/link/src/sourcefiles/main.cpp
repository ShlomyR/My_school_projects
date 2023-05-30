#include "../hederfiles/LinkedList_1.hpp"

void testing_all_functions()
{
    LinkedList<int> ll;

    for (int i = 1; i < 6; i++) {
        ll.push_front(i);
    }
    
    ll.print();
    std::cout << "size: " << ll.size() << "\n";

    ll.pop_front();
    ll.print();

    ll.push_back(6);
    ll.print();
    std::cout << "size: " << ll.size() << "\n";

    for (int i = 1; i < 6; i++) {
        ll.pop_back();
    }

    ll.print();
    ll.push_front(5);
    ll.print();
    std::cout << "size: " << ll.size() << "\n";

    LinkedList<int> ll_1(ll);
    ll_1.print();
}


int main()
{
    testing_all_functions();
    
    return 0;
}