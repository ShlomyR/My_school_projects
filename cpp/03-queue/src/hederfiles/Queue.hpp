#pragma once

class Queue
{
public:
    explicit Queue();
    explicit Queue(int);
    Queue(Queue const&);
    Queue& operator=(Queue const&);
    ~Queue();

    void push(int value);
    void pop();
    int front();
    int size();
    int back();
    int capacity();
    bool empty();

private:
    int* m_queue;
    int m_capacity;
    int m_size;
    int m_ip;
};