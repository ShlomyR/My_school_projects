#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Stack {

public:
    Stack() {}
    void push(T);
    T pop();
    T top();
    bool is_empty() const;
    size_t size() const;
private:
    std::vector<T> data;
};

#include "MyStack.inl"