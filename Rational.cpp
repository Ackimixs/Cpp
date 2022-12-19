#include "Rational.h"

Rational::Rational() {
    setDen(1);
    setNum(0);
}

Rational::Rational(int num, int den) {
    setDen(den);
    setNum(num);
}

Rational::Rational(const Rational &r) {
    setDen(r.getDen());
    setNum(r.getNum());
}

int Rational::getNum() const {
    return num;
}

int Rational::getDen() const {
    return den;
}

void Rational::setNum(int num) {
    this->num = num;
}

void Rational::setDen(int den) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be 0");
    }
    this->den = den;
}

void Rational::print() const {
    std::cout << num << "/" << den << std::endl;
}

void Rational::simplifier() {
    for (int i = 2; i <= num; i++) {
        if (num % i == 0 && den % i == 0) {
            num /= i;
            den /= i;
        }
    }
}

bool Rational::equals(const Rational &r) const {
    return num / den == r.getNum() / r.getDen();
}

Rational Rational::operator+(const Rational &r) const {
    int newNum = num * r.getDen() + r.getNum() * den;
    int newDen = den * r.getDen();
    Rational newRational(newNum, newDen);
    newRational.simplifier();
    return newRational;
}

Rational Rational::add(const Rational &r) const {
    int newNum = num * r.getDen() + r.getNum() * den;
    int newDen = den * r.getDen();
    Rational newRational(newNum, newDen);
    newRational.simplifier();
    return newRational;
}

Rational Rational::operator*(const Rational &r) const {
    int newNum = num * r.getNum();
    int newDen = den * r.getDen();
    Rational newRational(newNum, newDen);
    newRational.simplifier();
    return newRational;
}

Rational Rational::multiply(const Rational &r) const {
    int newNum = num * r.getNum();
    int newDen = den * r.getDen();
    Rational newRational(newNum, newDen);
    newRational.simplifier();
    return newRational;
}