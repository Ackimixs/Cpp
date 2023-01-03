//
// Created by acki on 1/3/23.
//

#ifndef TP6_FOIN_H
#define TP6_FOIN_H


#include <iostream>

class Poney;

class Foin {
private:
    int quantity;
    Poney* poney;
public:
    Foin();
    Foin(int quantity);
    Foin(int quantity, Poney* poney);
    Foin(Foin const &f);

    int getQuantity() const;

    void manger(int quantity);
    void remplir(int quantity);

    void print() const;
};


#endif //TP6_FOIN_H
