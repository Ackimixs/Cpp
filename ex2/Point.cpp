#include "Point.h"

void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::distance(Point p) {
    return sqrt(pow(p.getX() - getX(), 2) + pow(p.getY() - getY(), 2));
}

Point Point::milieu(Point p) {
    Point m;
    m.setX((p.getX() + getX()) / 2);
    m.setY((p.getY() + getY()) / 2);
    return m;
}

void Point::exe() {
    Point p2;

    std::cout << "Point 1" << std::endl;
    this->get();
    this->print();

    std::cout << "Point 2" << std::endl;
    p2.get();
    p2.print();

    std::cout << "MILIEU DE AB" << std::endl;
    Point m = this->milieu(p2);
    std::cout << "L'absisse est " << m.getX() << " et l'ordonnée est " << m.getX() << std::endl;

    std::cout << "**La distance entre A et B est " << this->distance(p2) << "**" << std::endl;
}

void Point::get() {
    std::cout << "Tapez l'abscisse : ";
    std::cin >> this->x;
    std::cout << "Tapez l'ordonnée : ";
    std::cin >> this->y;
}

void Point::print() const {
    std::cout << "L'abscisse est " << this->x << " et l'ordonnée est " << this->y << std::endl;
}