#ifndef TP7_POINT_H
#define TP7_POINT_H

#include <iostream>
#include <cstring>
#include <cmath>

template<class T> class Point {
private:
    T x;
    T y;
public:
    Point(T x, T y);
    Point(Point const &p);

    T getX() const;
    T getY() const;

    void setX(T x);
    void setY(T y);

    void setPoint(T x, T y);

    double distance(const Point<T>& p) const;
    double distance(T x, T y) const;

    void display() const;
};


template<class T> T Point<T>::getX() const {
    return this->x;
}

template<class T> T Point<T>::getY() const {
    return this->y;
}

template<class T> void Point<T>::setX(T x) {
    if (x < 0) {
        throw std::invalid_argument("x must be positive");
    }
    this->x = x;
}

template<class T> void Point<T>::setY(T y) {
    if (y < 0) {
        throw std::invalid_argument("y must be positive");
    }
    this->y = y;
}

template<class T> void Point<T>::setPoint(T x, T y) {
    this->setX(x);
    this->setY(y);
}

template<class T> Point<T>::Point(T x, T y) : x(x), y(y) {}

template<class T> Point<T>::Point(Point const &p) {
    this->x = p.x;
    this->y = p.y;
}

template<class T> double Point<T>::distance(const Point& p) const {
    return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
}

template<class T> double Point<T>::distance(T x, T y) const {
    return sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
}

template<class T> void Point<T>::display() const {
    std::cout << "Point (" << this->x << ", " << this->y << ")" << std::endl;
}
#endif //TP7_POINT_H
