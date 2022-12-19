#include "Point.h"

#ifndef TP6_VEHICULE_H
#define TP6_VEHICULE_H


class Vehicule {
private:
    Point position;
    char* identifier;
public:
    Vehicule();
    Vehicule(Point position, char* identifier);
    Vehicule(Vehicule const &v);

    Point getPosition() const;
    char* getIdentifier() const;

    void setPosition(Point position);
    void setIdentifier(char* identifier);


    float moveTo(Point p);
    float moveTo(Vehicule v);
    float moveTo(int x, int y);

    void print();
};


#endif //TP6_VEHICULE_H
