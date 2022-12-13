#include "weapon.h"
#include <cmath>

#ifndef CLASS_USER_H
#define CLASS_USER_H

class User {
private:
    string name;
    int health;
    Weapon* weapon;
    int x;
    int y;
    bool isAlive;
public:
    User(string name);

    void setName(string name);
    void setHealth(int health);
    void setWeapon(Weapon* weapon);
    void setPosition(int x, int y);
    void setIsAlive(bool isAlive);
    string getName() const;
    int getHealth() const;
    Weapon* getWeapon() const;
    int getX() const;
    int getY() const;
    bool getIsAlive() const;

    void setDead();

    void print();

    void attack(User* user);
    int distance(User* user);
};


#endif //CLASS_USER_H