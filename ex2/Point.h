#include <iostream>
#include <cmath>

#ifndef CLASS_POINT_H
#define CLASS_POINT_H


class Point {
private:
    double x, y;

public:
    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    double distance(Point p);
    Point milieu(Point p);

    void exe();

    void print() const;
    void get();
};


#endif //CLASS_POINT_H
