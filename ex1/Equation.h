#include <iostream>
#include <cmath>

#ifndef CLASS_EQUATION_H
#define CLASS_EQUATION_H


class Equation {
private:
    double a, b, c;
    double x1, x2;
public:
    double getA() const;
    double getB() const;
    double getC() const;
    double getX1() const;
    double getX2() const;

    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setX1(double x1);
    void setX2(double x2);

    void print();
    double calculate(double x);
    void saisie();
    void solve();
};


#endif //CLASS_EQUATION_H
