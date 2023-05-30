#pragma once

#include <iostream>

struct Node {
    Node(int data)
    :   m_data(data)
    ,   m_left(nullptr)
    ,   m_right(nullptr)
    {}

    int m_data;
    Node* m_left;
    Node* m_right;
};

class Tree
{
public:
    Tree()
    :   m_root(nullptr)
    {}
    ~Tree();
    void push(int);
    void preOrderTraversal(Node*);
    Node* getRoot();
private:
    Node* m_root;
};