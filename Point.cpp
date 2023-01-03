#include "Point.h"

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

void Point::setX(int x) {
    if (x < 0) {
        throw std::invalid_argument("x must be positive");
    }
    this->x = x;
}

void Point::setY(int y) {
    if (y < 0) {
        throw std::invalid_argument("y must be positive");
    }
    this->y = y;
}

void Point::setPoint(int x, int y) {
    this->setX(x);
    this->setY(y);
}

Point::Point(int x, int y) {
    setX(x);
    setY(y);
}

Point::Point(Point const &p) {
    this->x = p.x;
    this->y = p.y;
}

float Point::distance(const Point& p) const {
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
}

float Point::distance(int x, int y) const {
    return sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
}