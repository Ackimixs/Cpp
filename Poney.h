//
// Created by acki on 1/3/23.
//

#ifndef TP6_PONEY_H
#define TP6_PONEY_H

#include "Point.h"

class Foin;

class Poney {
private:
    char* identifier;
    Point position;
    Foin* foin;
public:
    Poney();
    Poney(char* identifier, Point position);
    Poney(char* identifier, Point position, Foin* foin);
    Poney(Poney const &p);
    ~Poney();

    Point getPosition() const;
    const char* getIdentifier() const;
    Foin* getFoin() const;

    void setPosition(Point position);
    void setIdentifier(char* identifier);
    void setFoin(Foin* foin);

    float moveTo(Point p);
    float moveTo(Poney& p);
    float moveTo(int x, int y);

    void print() const;
    void reset();
};


#endif //TP6_PONEY_H
