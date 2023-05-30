#include "../hederfiles/Vector.hpp"

#include <iostream>
// #include "Vector.hpp"
// #include "Vector.hpp"

Vector::Vector()
:   m_vector(nullptr)
,   m_capacity(0)
,   m_size(0)
,   m_ip(-1)
{}

Vector::Vector(int size)
:   m_vector(new int[size])
,   m_capacity(size)
,   m_size(0)
,   m_ip(-1)
{}

Vector::~Vector()
{
    delete[] m_vector;
}

Vector::Vector(Vector const &other)
:   m_vector(new int[other.m_capacity])
,   m_capacity(other.m_capacity)
,   m_size(other.m_size)
,   m_ip(other.m_ip)
{
    for (int i = 0; i < other.m_size; ++i) {
        m_vector[i] = other.m_vector[i];
    }
}

Vector &Vector::operator=(Vector const &other)
{
    m_vector = new int[other.m_size];
    for (int i = 0; i < other.m_size; ++i) {
            m_vector[i] = other.m_vector[i];
    }
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_ip = other.m_size - 1;
    return *this;
}

int& Vector::operator[](size_t index)
{
    return m_vector[index];
}

int Vector::size()
{
    return m_size;
}

void Vector::print()
{
    std::cout << "\n";
    for (int i = 0; i < m_size; i++) {
        if (i + 1 == m_size) {
            std::cout << "[";
            std::cout << m_vector[i] << "].";
            break;
        }
        std::cout << "[";
        std::cout << m_vector[i] << "],";
    }
    std::cout << "\n";
}

int Vector::back()
{
    return m_vector[0];
}

int Vector::front()
{
    return  m_vector[m_ip];
}

int Vector::capacity()
{
    return m_capacity;
}

void Vector::push_front(int value)
{
    if (!empty()) {
        if (m_size == m_capacity) {
            int *tmp_vector = new int[++m_capacity];
            ++m_size;
            tmp_vector[0] = value;
            for (int i = 1; i < m_size; ++i) {
                    tmp_vector[i] = m_vector[i - 1];
            }
            delete[] m_vector;
            m_vector = tmp_vector;
            ++m_ip;
        } else {
            ++m_size;
            m_vector[++m_ip] = value;
            for (int i = 0; i < m_size; i++) {
                std::swap(m_vector[i],m_vector[m_ip]);
            }
        }
    } else {
        m_vector[++m_ip] = value;
        ++m_size;
    }
}

void Vector::push_back(int value)
{
    if (!empty()) {
        if (m_size == m_capacity) {
            int *tmp_vector = new int[++m_capacity];
            ++m_size;
            tmp_vector[m_size - 1] = value;
            for (int i = 0; i < m_size - 1; ++i) {
                    tmp_vector[i] = m_vector[i];
            }
            delete[] m_vector;
            m_vector = tmp_vector;
            ++m_ip;
        } else {
            ++m_size;
            m_vector[++m_ip] = value;
        }
    } else {
        m_vector[++m_ip] = value;
        ++m_size;
    }
}

void Vector::pop_back()
{
    int *tmp_vector = new int[m_size - 1];
    --m_size;
    for (int i = 0; i < m_size; ++i) {
            tmp_vector[i] = m_vector[i];
    }
    delete[] m_vector;
    m_vector = tmp_vector;
    --m_ip;
    // --m_ip;
    // --m_size;
}

void Vector::pop_front()
{
    int *tmp_vector = new int[m_size - 1];
    --m_size;
    for (int i = 0; i < m_size; ++i) {
            tmp_vector[i] = m_vector[i + 1];
    }
    delete[] m_vector;
    m_vector = tmp_vector;
    --m_ip;
}

bool Vector::empty()
{
    return m_ip == -1;
}
