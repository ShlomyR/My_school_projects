#include "LinkedList.hpp"

void basic_test()
{
    std::cout << "\n" << "---------------------------------------------basic test--------------------------------------" << "\n\n";
    LinkedList<int> linked_list;
    for (int i = 0; i < 10; i++)
    {
        linked_list.push(i);
    }

    linked_list.pop();


    linked_list.print();
    linked_list.reverse();

    linked_list.print();
    linked_list.reverse();

    linked_list.size();

    for (int i = 0; i < 5; i++)
    {
        linked_list.deleteNode(i);
    }

    //linked_list.deleteNode(20);
    
    linked_list.print();
    linked_list.size();

    linked_list.contains(9);
    linked_list.contains(12);

    std::cout << "\n" << "---------------------------------------------double--------------------------------------" << "\n\n";

    LinkedList<double> linked_list_d;
    for (double i = 0.5; i < 10.5; i++)
    {
        linked_list_d.push(i);
    }

    linked_list_d.print();
    linked_list_d.reverse();

    linked_list_d.print();
    linked_list_d.reverse();

    linked_list_d.size();

    for (double i = 0.5; i < 10.5; i++)
    {
        linked_list_d.deleteNode(i);
    }

    linked_list_d.print();
    linked_list_d.size();

    for (double i = 0.5; i < 10.5; i++)
    {
        linked_list_d.push(i);
    }

    linked_list_d.contains(9.5);
    linked_list_d.contains(12);

    linked_list_d.deleteNode(9563);
}

void copy_test()
{
    std::cout << "\n" << "---------------------------------------------copy test--------------------------------------" << "\n\n";
    LinkedList<int> linked_list_1;

    for (int i = 0; i < 10; i++)
    {
        linked_list_1.push(i);
    }

    linked_list_1.print();

    LinkedList<int> linked_list_2(linked_list_1); // or LinkedList<int> linked_list_2 = linked_list_1;

    linked_list_1.pop();
    linked_list_1.pop();
    
    linked_list_2.print();
    
}

void assignmentOP_equal_test()
{
    std::cout << "\n" << "---------------------------------------------assignment OP equal test--------------------------------------" << "\n\n";
    LinkedList<int> linked_list_1,linked_list_2;

    for (int i = 0; i < 10; i++)
    {
        linked_list_1.push(i);
    }

    linked_list_1.print();

    linked_list_2 = linked_list_1;

    linked_list_1.pop();
    linked_list_1.pop();

    linked_list_2.print();

}

void assignmentOP_plus_test()
{
    std::cout << "\n" << "---------------------------------------------assignment OP plus test--------------------------------------" << "\n\n";
    LinkedList<int> linked_list_1,linked_list_2;

    for (int i = 0; i < 10; i++)
    {
        linked_list_1.push(i);
    }

    linked_list_1.print();

    for (int i = 10; i < 20; i++)
    {
        linked_list_2.push(i);
    }
   
    linked_list_2.print();

    LinkedList<int> linked_list_3 = linked_list_1 + linked_list_2;

    linked_list_3.pop();

    linked_list_1.print();
    linked_list_2.print();

    linked_list_3.print();
    
    linked_list_3.size();
    linked_list_1.size();

}

int main()
{
    basic_test();

    copy_test();

    assignmentOP_equal_test();

    assignmentOP_plus_test();

    return 0;
}