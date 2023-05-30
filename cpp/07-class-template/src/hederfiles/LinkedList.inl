#include "LinkedList.hpp"


template<typename T>
Node<T>::Node(T data)
    : m_data(data)
    , m_next(nullptr)
{}



template<typename T>
LinkedList<T>::LinkedList()
    : m_size(0)
    , m_head(nullptr)
    , m_tail(nullptr)
{}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *node_h;
    while (m_head) {
        node_h = m_head->m_next;
        delete m_head;
        m_head = node_h;
    }
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> const& list)
    : m_size(0)
    , m_head(nullptr)
    , m_tail(nullptr)
{
    Node<T>* node = list.m_head;
    while (node) {
        push(node->m_data);
        node = node->m_next;
    } if (node) {
        reverse();
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> const& list)
{
    if (this != &list) {
        LinkedList<T> copy(list);
        std::swap(copy.m_size, m_size);
        std::swap(copy.m_head, m_head);
        std::swap(copy.m_tail, m_tail);
    }
    return *this;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator+(LinkedList<T> const& listA)
{
    Node<T>* tempNode = this->m_head;//= new Node<T>(listA) ;
    Node<T>* tempNodePtr = this->m_head;
    T prevSize = m_size;
    T count = 0;

    m_size += listA.m_size;

    while (tempNode->m_next != nullptr)  {
        tempNode = tempNode->m_next;
    }
    tempNode->m_next = listA.m_head;

    while (tempNodePtr->m_next != nullptr) {
        if (count == prevSize) {
            tempNodePtr->m_next = nullptr;
            break;
        }
        count++;
        tempNodePtr = tempNodePtr->m_next;
    }
        
    return *this;
}

template<typename T>
void LinkedList<T>::reverse()
{
    Node<T>* current = m_head;
    Node<T>* prev = nullptr, *next = nullptr;
    
    while (current != nullptr)  {
        next = current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }
    m_head = prev;
}

template<typename T>
void LinkedList<T>::print()
{
    Node<T>* node = m_head;
    while (node != nullptr)  {
        if (node->m_next == nullptr) {
            std::cout << node->m_data << "-> " << "NULL" ;
        } else {
            std::cout << node->m_data << "->";
        }
        node = node->m_next;
    }
    std::cout << "\n";

    if (m_size == 0) {
        std::cout << "empty list" << "\n";
    }
    
}

template<typename T>
void LinkedList<T>::push(T data)
{
    Node<T>* node = new Node<T>(data);
    Node<T>* tempNode = m_head;

    if (m_head == nullptr) {
        m_head = node;
        m_head->m_next = nullptr;
    } else {
        while (tempNode->m_next != nullptr) {
            tempNode = tempNode->m_next;
        }
        tempNode->m_next = node;
        node = m_head;
        while (node->m_next != nullptr) {
            node = node->m_next;
        }
    }
    m_size += 1;
    m_tail = node;
    //delete node;
}

template<typename T>
void LinkedList<T>::pop()
{
    m_head = m_head->m_next;
    m_size -= 1;
}

template<typename T>
int LinkedList<T>::size()
{
    std::cout << "\nThe numbers of nodes in the linked list is: " << m_size << "\n";
    return m_size;
}

template<typename T>
void LinkedList<T>::contains(T x)
{
    Node<T>* tempNode = m_head;
    while (tempNode) {
        if (tempNode->m_data == x) {
            std::cout << "\nThe linked list has " << x << "\n";
            return;
        }
        tempNode = m_head->m_next;
        m_head = tempNode;
    }
    std::cout << "\nThe linked list dont have " << x << "\n";
    
}


template<typename T>
void LinkedList<T>::makeCircle(T a,T b)
{
    if (a <= b) {
        std::cout << "\nThe left num smaller from the right num please change it" << "\n";
        return;
    }
    
    Node<T>* node = m_head;
    Node<T>* tempNode = m_head;
    for (int i = 0; i < a; i++) {
        node = node->m_next;
    }
    for (int i = 0; i < b; i++) {
        tempNode = tempNode->m_next;       
    }
    node->m_next = tempNode;
    //head = node;
}

template<typename T>
void LinkedList<T>::findCircle()
{
    Node<T>* ptr1 = m_head->m_next;
    Node<T>* ptr2 = m_head->m_next->m_next;

    while (ptr2 && ptr2->m_next) {
        if (ptr1 == ptr2) {
            break;
        }
        ptr1 = ptr1->m_next;
        ptr2 = ptr2->m_next->m_next; 
    }
    if (ptr1 != ptr2) {
        std::cout << "\nNo circle fond" << "\n";
        return;
    }
    //std::cout << ptr2->m_data << "\n";

    ptr1 = m_head;
    while (ptr1 != ptr2) {
        ptr1 = ptr1->m_next;
        ptr2 = ptr2->m_next; 
    }
    std::cout << ptr2->m_data << "\n";
}

template<typename T>
Node<T>* LinkedList<T>::deleteNode(T i)
{
    Node<T> *n = new Node<T>(i);
    n = m_head;

    if (!n)  {
        std::cout << "\nThe node "<< i << " doesn't exists in the linked list" << "\n";
        return m_head;
    } else if (n->m_data == i) {
        m_size -= 1;
        return m_head = m_head->m_next;
    }
    
    while (n->m_next != nullptr) {
        if (n->m_next->m_data == i) {
            n->m_next = n->m_next->m_next;
            m_size -= 1;
            return m_head;
        }
        if(n->m_next->m_next == nullptr && n->m_next->m_data != i) {
            std::cout << "\nThe node "<< i << " doesn't exists in the linked list" << "\n";
            return m_head;
        }
      
        n = n->m_next;  
    }

    delete n;

    return m_head;
}