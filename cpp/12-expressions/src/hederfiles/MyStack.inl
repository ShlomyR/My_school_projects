#pragma once

#include <iostream>

#include "MyStack.hpp"

template <typename T>
void Stack<T>::push(T value)
{
    data.push_back(value);
}

template <typename T>
T Stack<T>::pop()
{
    if (data.empty()) {
        throw std::out_of_range("Stack is empty.");
    }
    T value = data.back();
    data.pop_back();

    return value;
}

template <typename T>
T Stack<T>::top()
{
    if (data.empty()) {
        throw std::out_of_range("Stack is empty.");
    }
    T value = data.back();

    return value;
}

template <typename T>
bool Stack<T>::is_empty() const
{
    return data.empty();
}

template <typename T>
size_t Stack<T>::size() const
{
    return data.size();
}