#include "Equation.h"

double Equation::getA() const {
    return a;
}

double Equation::getB() const {
    return b;
}

double Equation::getC() const {
    return c;
}

double Equation::getX1() const {
    return x1;
}

double Equation::getX2() const {
    return x2;
}

void Equation::setA(double a) {
    if (a < 0) {std::cout<<"error"<<std::endl;}
    else{this->a=a;}
}

void Equation::setB(double b) {
    this->b = b;
}

void Equation::setC(double c) {
    this->c = c;
}

void Equation::setX1(double x1) {
    this->x1 = x1;
}

void Equation::setX2(double x2) {
    this->x2 = x2;
}
void Equation::solve() {
    double d = b * b - 4 * a * c;
    if (d < 0) {
        std::cout << "No real roots" << std::endl;
    } else if (d == 0) {
        setX1(-b / (2 * a));
        setX2(-b / (2 * a));
    } else {
        setX1((-b + sqrt(d)) / (2 * a));
        setX2((-b - sqrt(d)) / (2 * a));
    }
}

void Equation::print() {
    std::cout << a << "x^2 + " << b << "x + " << c << std::endl;
    this->solve();
    std::cout << "x1 = " << getX1() << std::endl;
    std::cout << "x2 = " << getX2() << std::endl;
}

double Equation::calculate(double x) {
    return a * x * x + b * x + c;
}

void Equation::saisie() {
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;
}