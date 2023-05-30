#include "../hederfiles/LinkedList_1.hpp"

#include <iostream>

template <typename T>
LinkedList<T>::LinkedList()
    : m_size(0)
    , m_head(nullptr)
    , m_tail(nullptr)

{}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> const& list)
    : m_size(0)
    , m_head(nullptr)
    , m_tail(nullptr)
{  
    if (list.m_head == nullptr) {
      m_head = nullptr;
    } else {
        Node<T>* node = list.m_head;
        while (node) {
            push_front(node->m_data);
            node = node->m_next;
        } 
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T>* tempPtr = m_head;
    while (m_head) {
        m_head = m_head->m_next;
        delete tempPtr;
        tempPtr = m_head;
        m_size--;
    }    
}

template <typename T>
void LinkedList<T>::push_front(T data)
{
    Node<T>* new_node = new Node<T>(data);
    m_size++;

    if (!m_head) {
        init_new_node(new_node);
    } else {
        Node<T>* tempNode = m_head;
        m_head = new_node;
        new_node->m_next = tempNode;
    }
}

template <typename T>
void LinkedList<T>::pop_front()
{
    Node<T>* tempPtr = m_head;
    m_head = m_head->m_next;
    delete tempPtr;
    m_size--;
}

template <typename T>
void LinkedList<T>::push_back(T data)
{
    Node<T>* new_node = new Node<T>(data);
    m_size++;

    if (!m_tail) {
        init_new_node(new_node);
    } else {
        m_tail->m_next = new_node;
        m_tail = new_node;
        new_node->m_next = nullptr;
    }
}

template <typename T>
void LinkedList<T>::pop_back()
{
    if (m_size == 1) {
        m_tail = nullptr;
        m_head = nullptr;
    } else {
        if_nodes();
    }
    m_size--;
}

template <typename T>
void LinkedList<T>::print()
{
    Node<T>* tempPtr = m_head;
    if(!tempPtr) {
        std::cout << "NULL";
    }

    while (tempPtr) {
        if (tempPtr->m_next == nullptr) {
            std::cout << tempPtr->m_data << "-->NULL";
        } else {
            std::cout << tempPtr->m_data << "-->";
        }
        tempPtr = tempPtr->m_next; 
    }
    std::cout << "\n";
}

template <typename T>
int LinkedList<T>::size()
{
    return m_size;
}

// template <typename Iter>
// T LinkList<T>::begin(Iter start, Iter end)
// {
//     return ;
// }

// template <typename Iter>
// T LinkList<T>::end(Iter start, Iter end)
// {
//     return ;
// }

template <typename T>
void LinkedList<T>::init_new_node(Node<T> *new_node)
{
    m_head = new_node;
    m_tail = new_node;
    new_node->m_next = nullptr;
}

template <typename T>
void LinkedList<T>::if_nodes()
{
    Node<T>* tempPtr = m_head;
    while (tempPtr->m_next != m_tail) {
        tempPtr = tempPtr->m_next;        
    }
    m_tail = tempPtr;
    m_tail->m_next = nullptr;
}