#include "Point.h"
#include "NegativeDimensionException.h"

#include <string>
#include <cstring>
using std::string;
using std::to_string;
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define __CONTEXT__ ( string("[") + __FILENAME__ + ":" + std::to_string(__LINE__) + ":" + __FUNCTION__ + "] ")

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}

void Point::setX(int x) {
    if (x < 0) {
        throw NegativeDimensionException(__CONTEXT__, "x", x);
    }
    this->x = x;
}

void Point::setY(int y) {
    if (y < 0) {
        throw NegativeDimensionException(__CONTEXT__, "y", y);
    }
    this->y = y;
}

void Point::setPoint(int x, int y) {
    this->setX(x);
    this->setY(y);
}

Point::Point(int x, int y) {
    this->setX(x);
    this->setY(y);
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

void Point::afficher() const {
    std::cout << "position : " << "(" << this->x << ", " << this->y << ")";
}