#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <ostream>
#include <cmath>

struct Rational
{
public:
    Rational(int a) 
    : m_numer(a), m_denom(1) 
    {}
    Rational(int a, int b) 
    : m_numer(a), m_denom(b)
    {}

    double value() const;

    Rational mul(int n) const;
    Rational div(int n) const;
    Rational add(int n) const;
    Rational sub(int n) const;

    Rational mul(Rational);
    Rational div(Rational);
    Rational add(Rational);
    Rational sub(Rational);

    Rational operator*(Rational) const;
    Rational operator/(Rational) const;
    Rational operator+(Rational) const;
    Rational operator-(Rational) const;

    Rational operator*(int) const;
    Rational operator/(int) const;
    Rational operator+(int) const;
    Rational operator-(int) const;

    void operator+=(Rational);
    void operator-=(Rational);
    void operator*=(Rational);
    void operator/=(Rational);
    void reduce();

    int getNumber();
    int getDenom();

private:
    int gcd(int m, int n);

private:
    int m_numer;
    int m_denom;
};

std::ostream &operator<<(std::ostream&,Rational);

/*
2 ctor
make all relevant functions const
add operator overloading
+ - * /
+= -= *= /=

< > !=   <= >=

print
*/

#endif