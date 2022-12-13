//
// Created by acki on 12/6/22.
//

#include <cstring>
#include <iostream>
#include "Color.h"

#ifndef CONSTRUCT_WEAPON_H
#define CONSTRUCT_WEAPON_H


class Weapon {
private:
    char* name;
    int damage;
public:
    static int nbWeapon;
    Weapon();
    Weapon(char* name, int damage);
    ~Weapon();
    void display();
    int getDamage() const;
};


#endif //CONSTRUCT_WEAPON_H
