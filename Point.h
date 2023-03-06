#ifndef TP6_POINT_H
#define TP6_POINT_H

#include <iostream>
#include <cmath>

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y);
    Point(Point const &p);

    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);

    void setPoint(int x, int y);

    float distance(const Point& p) const;
    float distance(int x, int y) const;

    void afficher() const;
};


#endif //TP6_POINT_H
