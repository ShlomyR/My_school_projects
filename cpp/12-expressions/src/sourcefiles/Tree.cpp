#include "../hederfiles/Tree.hpp"
// #include "Tree.hpp"

Tree::~Tree()
{
    delete m_root;
}

void Tree::push(int data)
{
    Node* newNode = new Node(data);
    if (!m_root) {
        m_root = newNode;
    } else {
        Node* focusNode = m_root;
        Node* parent;
    
        while (true) {
            parent = focusNode;
    
            if (data < focusNode->m_data) {
                focusNode = focusNode->m_left;
                if (focusNode == nullptr) {
                    parent->m_left = newNode;
                    return;
                }
            } else {
                focusNode = focusNode->m_right;
                if (focusNode == nullptr) {
                    parent->m_right = newNode;
                    return;
                }
            }
        }
    }
}

void Tree::preOrderTraversal(Node *focusNode)
{
    if (focusNode) {
        std::cout << focusNode->m_data << " ";
        preOrderTraversal(focusNode->m_left);
        preOrderTraversal(focusNode->m_right);
    }  
}

Node* Tree::getRoot()
{
    return m_root;
}