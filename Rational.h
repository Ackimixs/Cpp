//
// Created by acki on 12/19/22.
//

#include <iostream>

#ifndef TP5_RATIONAL_H
#define TP5_RATIONAL_H


class Rational {
private:
    int num;
    int den;
    int pgcd(int a, int b);
    int ppcm(int a, int b);

public:
    Rational();
    Rational(int num, int den);
    Rational(const Rational& r);

    int getNum() const;
    int getDen() const;
    void setNum(int num);
    void setDen(int den);

    void print() const;

    void simplifier();

    bool equals(const Rational& r) const;

    Rational operator+(const Rational& r) const;
    Rational add(const Rational& r) const;
    Rational operator*(const Rational& r) const;
    Rational multiply(const Rational& r) const;
};


#endif //TP5_RATIONAL_H
