#pragma once

template<typename T>
struct Node
{
    Node(T);

    T m_data;
    Node<T>* m_next;
};

template <typename T>
Node<T>::Node(T data)
    :   m_data(data)
    ,   m_next(nullptr)

{}

 
template<typename T>
class LinkedList 
{
public:
    LinkedList();
    ~LinkedList();
    LinkedList(LinkedList const&);
    LinkedList<T>& operator=(LinkedList const &obj) = delete;

    void push_front(T data);
    void pop_front();
    void push_back(T data);
    void pop_back();
    void print();
    int size();
    
    // template<typename Iter>
    // T begin(Iter,Iter);
    // template<typename Iter>
    // T end(Iter,Iter);
private:
    // My code cleaning functions
    void init_new_node(Node<T>*);
    void if_nodes();
    
    void find_merge(Node<T>*, Node<T>*, Node<T>*); 

private:
    T m_size;
    Node<T>* m_head;
    Node<T>* m_tail;
};

#include "../hederfiles/LinkedList_1.inl"