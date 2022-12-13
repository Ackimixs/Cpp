#include "weapon.h"

int Weapon::getAmmo() const {
    return ammo;
}

int Weapon::getDamage() const {
    return damage;
}

string Weapon::getName() const {
    return name;
}

int Weapon::getRange() const {
    return range;
}

void Weapon::setAmmo(int ammo) {
    if (ammo < 0) {
        cout << "Ammo cannot be negative" << endl;
    } else {
        this->ammo = ammo;
    }
}

void Weapon::setDamage(int damage) {
    if (damage < 0) {
        cout << "Damage cannot be negative" << endl;
    } else {
        this->damage = damage;
    }
}

void Weapon::setName(string name) {
    this->name = name;
}

void Weapon::setRange(int range) {
    if (range < 0) {
        cout << "Range cannot be negative" << endl;
    } else {
        this->range = range;
    }
}

void Weapon::print() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Range: " << range << std::endl;
    std::cout << "Ammo: " << ammo << std::endl;
}

Weapon **Weapon::initWeapon() {
    Weapon** weapons = new Weapon*[3];
    weapons[0] = new Weapon();
    weapons[0]->setName("AK-47");
    weapons[0]->setDamage(15);
    weapons[0]->setRange(10);
    weapons[0]->setAmmo(100);

    weapons[1] = new Weapon();
    weapons[1]->setName("M4A1");
    weapons[1]->setDamage(10);
    weapons[1]->setRange(15);
    weapons[1]->setAmmo(100);

    weapons[2] = new Weapon();
    weapons[2]->setName("M16A4");
    weapons[2]->setDamage(12);
    weapons[2]->setRange(12);
    weapons[2]->setAmmo(100);

    return weapons;
}