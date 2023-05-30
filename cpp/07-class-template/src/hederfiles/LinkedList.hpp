#pragma once

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <cassert>


template<typename T>
struct Node
{
    Node(T data);
    T m_data;
    Node<T>* m_next;
};
 
template<typename T>
class LinkedList 
{
public:

    LinkedList();
    ~LinkedList();
    LinkedList(LinkedList<T> const& list);
    LinkedList<T>& operator=(LinkedList<T> const& list);
    LinkedList<T>& operator+(LinkedList<T> const& listA);

    void reverse();
    void print();
    void push(T data);
    void pop();
    int size();
    void contains(T x);

    void sort(T list); //sort the list nodes by value 
    
    // my functions
    void makeCircle(T a,T b);
    void findCircle();
    Node<T>* deleteNode(T i);

private:

    T m_size;
    Node<T>* m_head;
    Node<T>* m_tail;

};

#include "LinkedList.inl"