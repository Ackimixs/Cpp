#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include "Color.h"

#ifndef CLASS_JEUMORPIONS_H
#define CLASS_JEUMORPIONS_H

enum Content {VIDE, ROND, CROIX};

class JeuMorpions {
private:
    char grille[3][3];
    bool placer_coup(int ligne, int colonne, Content c);
    string nameUser1;
    string nameUser2;
public:
    void init();

    void setNameUser1(string name);
    void setNameUser2(string name);

    string getNameUser1() const { return nameUser1; }
    string getNameUser2() const { return nameUser2; }

    void setUser();

    bool placer_rond(int ligne, int colonne);
    bool placer_croix(int ligne, int colonne);
    void print();
    void game();
    bool win();

    bool playUser1();
    bool playUser2();
};


#endif //CLASS_JEUMORPIONS_H
