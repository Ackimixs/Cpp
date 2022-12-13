#include <iostream>
#include <string>

using namespace std;

#ifndef CLASS_WEAPON_H
#define CLASS_WEAPON_H


class Weapon {
private:
    string name;
    int damage;
    int range;
    int ammo;

public:
    void setName(string name);
    void setDamage(int damage);
    void setRange(int range);
    void setAmmo(int ammo);
    string getName() const;
    int getDamage() const;
    int getRange() const;
    int getAmmo() const;

    void print();

    Weapon** initWeapon();
};


#endif //CLASS_WEAPON_H
