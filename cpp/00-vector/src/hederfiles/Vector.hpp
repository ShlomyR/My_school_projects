#pragma once

#include <iostream>

class Vector
{
public:
    explicit Vector();
    explicit Vector(int);
    ~Vector();
    explicit Vector(Vector const&);
    Vector& operator=(Vector const&);
    int& operator[](size_t);

    void push_front(int);
    void push_back(int value);
    void pop_back();
    void pop_front();
    int size();
    void print();
    int back();
    int front();
    int capacity();
    bool empty();

private:
    int* m_vector;
    int m_capacity;
    int m_size;
    int m_ip;
};