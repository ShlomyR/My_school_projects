#include "../hederfiles/Queue.hpp"

#include <iostream>
// #include "Queue.hpp"


Queue::Queue()
:   m_queue(nullptr)
,   m_capacity(0)
,   m_size(0)
,   m_ip(-1)
{

}

Queue::Queue(int size)
:   m_queue(new int[size])
,   m_capacity(size)
,   m_size(0)
,   m_ip(-1)
{}

Queue::Queue(Queue const &other)
:   m_queue(new int[other.m_capacity])
,   m_capacity(other.m_capacity)
,   m_size(other.m_size)
,   m_ip(other.m_size - 1)
{
    for (int i = 0; i < other.m_size; ++i) {
        m_queue[i] = other.m_queue[i];
    }
}

Queue &Queue::operator=(Queue const &other)
{
    m_queue = new int[other.m_size];
    for (int i = 0; i < other.m_size; ++i) {
            m_queue[i] = other.m_queue[i];
    }
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_ip = other.m_size - 1;
    return *this;
}

Queue::~Queue()
{
    delete[] m_queue;
}

int Queue::front()
{
    return m_queue[0];
}

int Queue::size()
{
    return m_size;
}

int Queue::back()
{
    return m_queue[m_ip];
}

int Queue::capacity()
{
    return m_capacity;
}

void Queue::push(int value)
{
    if (!empty()) {
       if (m_size == m_capacity) {
            std::cout << "The queue is full!!!" << "\n";
            return;
        } else {
            ++m_size;
            m_queue[++m_ip] = value;
        }
    } else {
        m_queue[++m_ip] = value;
        ++m_size;
    }
}

void Queue::pop()
{
    if (empty()) {
        std::cout << "The queue is empty!!!" << "\n";
        return;
    }
    int *tmp_arr = new int[m_capacity];
    for (int i = 0; i < m_size; i++) {
        tmp_arr[i] = m_queue[i + 1];
    }
    delete m_queue;
    m_queue = tmp_arr;
    --m_ip; 
    --m_size;
}

bool Queue::empty()
{
    return m_ip == -1;
}