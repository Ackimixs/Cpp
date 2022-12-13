//
// Created by acki on 12/6/22.
//

#include "Weapon.h"

int Weapon::nbWeapon = 0;

Weapon::Weapon(): name(new char[30]), damage(10) {
    strcpy(this->name, "Default Weapon");
    Weapon::nbWeapon++;
}

void Weapon::display() {
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Damage: " << this->damage << std::endl;
}

Weapon::~Weapon() {
    delete[] this->name;
}

int Weapon::getDamage() const {
    return this->damage;
}