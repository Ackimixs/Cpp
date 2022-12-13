//
// Created by acki on 12/6/22.
//

#ifndef CONSTRUCT_PERSO_H
#define CONSTRUCT_PERSO_H


#include "Weapon.h"

class Perso {
private:
    char* name;
    int pv;
    struct Position {
        int x;
        int y;
    } pos;
    Weapon* weapon;
    bool alive;
public:
    static int nbPerso;

    Perso();
    Perso(int x, int y);
    Perso(char* name);
    Perso(int pv);
    Perso(Weapon* weapon);
    Perso(char* name = nullptr, int pv = 100, int x = 0, int y = 0, Weapon* weapon = new Weapon());
    Perso(const Perso& perso);
    ~Perso();


    char *getName() const;
    int getPv() const;
    const Position &getPos() const;
    Weapon *getWeapon() const;
    bool isAlive() const;

    void setAlive(bool alive);
    void setName(char *name);
    void setPv(int pv);
    void setPos(const Position &pos);
    void setWeapon(Weapon *weapon);

    static int getNbPerso();


    void move(int x, int y);
    void attack(Perso& target);
    void display();

};



#endif //CONSTRUCT_PERSO_H
