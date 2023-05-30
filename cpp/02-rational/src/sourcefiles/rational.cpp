#include "rational.hpp"

#include <iostream>

double Rational::value() const
{
    return (double)m_numer / m_denom;
}

Rational Rational::mul(int n) const
{
    return Rational(m_numer * n, m_denom);
}

Rational Rational::div(int n) const
{
    return Rational(m_numer, m_denom * n);
}

Rational Rational::add(int n) const
{
    return Rational(m_numer + n * m_denom, m_denom);
}

Rational Rational::sub(int n) const
{
    return Rational(m_numer - n * m_denom, m_denom);
}

Rational Rational::mul(Rational r)
{
    return Rational(m_numer * r.m_numer, m_denom * r.m_denom);
}

Rational Rational::div(Rational r)
{
    return Rational(m_numer * r.m_denom, m_denom * r.m_numer);
}

Rational Rational::add(Rational r)
{
    return Rational(m_numer * r.m_denom + r.m_numer * m_denom, m_denom * r.m_denom);
}

Rational Rational::sub(Rational r)
{
    return Rational(m_numer * r.m_denom - r.m_numer * m_denom, m_denom * r.m_denom);
}

Rational Rational::operator*(Rational r) const
{
    return Rational(m_numer * r.m_numer, m_denom * r.m_denom);
}

Rational Rational::operator/(Rational r) const
{
    return Rational(m_numer * r.m_denom, m_denom * r.m_numer);
}

Rational Rational::operator+(Rational r) const
{
    return Rational(m_numer * r.m_denom + r.m_numer * m_denom, m_denom * r.m_denom);
}

Rational Rational::operator-(Rational r) const
{
    return Rational(m_numer * r.m_denom - r.m_numer * m_denom, m_denom * r.m_denom);
}

Rational Rational::operator*(int n) const
{
    return Rational(m_numer * n, m_denom);
}

void Rational::operator+=(Rational r)
{
    *this = *this + r;
}

void Rational::operator-=(Rational r)
{ 
    *this = *this - r; 
}
void Rational::operator*=(Rational r)
{ 
    *this = *this * r; 
}
void Rational::operator/=(Rational r)
{
    *this = *this / r; 
}

// GCD method
int Rational::gcd(int m, int n)
{
    int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

void Rational::reduce()
{

    int div = gcd(m_numer, m_denom);
    m_numer /= div;
    m_denom /= div;
    if (m_denom < 0)
    {
        m_numer = -m_numer;
        m_denom = -m_denom;
    }
}

int Rational::getNumber()
{
    return this->m_numer;
}

int Rational::getDenom()
{
    return this->m_denom;
}

std::ostream &operator<<(std::ostream &os, Rational r)
{

    os << r.getNumber();
    if (r.getDenom() != 1)
    {
        os << "/" << r.getDenom();
    }
    return os;
}

int main()
{
    Rational r1(1, 2);
    Rational r2(2, 3);

    Rational r3 = r1 + r2;
    std::cout << r3.value() << "\n";

    r1 += r2;
    std::cout << r1.value() << "\n";

    r1 *= r2;
    std::cout << r1.value() << "\n";

    r1 = r1 * r2;
    std::cout << r1.value() << "\n";

    r1.reduce();
    std::cout << r1.value() << "\n";

    std::cout << r1 << "\n";

    return 0;
}
