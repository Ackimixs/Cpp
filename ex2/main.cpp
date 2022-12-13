#include "Point.h"

int main() {

    int x=1, y=3;

    Point p1 = new Point();
    Point p2 = new Point();
    p1.setX(x);
    p1.setY(y);
    p2.setX(x);
    p2.setY(y);


    delete p1;
    delete p2;

    return 0;
}