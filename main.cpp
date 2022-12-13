#include "Perso.h"
#include <iostream>


int main() {

    Weapon* weapon = new Weapon();

    Perso* p1 = new Perso(10);

    Perso* p2 = new Perso(weapon);

    p2->display();

    std::cout << Perso::nbPerso << std::endl;

    delete p1;
    delete p2;

    return 0;
}
