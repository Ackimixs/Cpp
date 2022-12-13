#include "user.h"

User::User(string name) {
    this->name = name;
    health = 100;
    weapon = nullptr;
    x = 0;
    y = 0;
    isAlive = true;
}

string User::getName() const {
    return name;
}

int User::getHealth() const {
    return health;
}

Weapon* User::getWeapon() const {
    return weapon;
}

int User::getX() const {
    return x;
}

int User::getY() const {
    return y;
}

bool User::getIsAlive() const {
    return isAlive;
}

void User::setName(string name) {
    this->name = name;
}

void User::setHealth(int health) {
    this->health = health > 0 ? health : 0;
}

void User::setPosition(int x, int y) {
    if (x < 0 || y < 0) {
        cout << "Position cannot be negative" << endl;
    } else if (x > 19 || y > 19) {
        cout << "Position cannot be greater than 20" << endl;
    } else {
        this->x = x;
        this->y = y;
    }
}

void User::setWeapon(Weapon *weapon) {
    this->weapon = weapon;
}

void User::setIsAlive(bool isAlive) {
    this->isAlive = isAlive;
}

void User::print() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    weapon->print();
    std::cout << "Position: " << x << ", " << y << std::endl;
}

void User::setDead() {
    this->x=-1;
    this->y=-1;
    setIsAlive(false);
}

void User::attack(User *user) {
    if (user->getIsAlive()) {
        if (this->distance(user) <= this->getWeapon()->getRange()) {
            if (this->getWeapon()->getAmmo() > 0) {
                user->setHealth(user->getHealth() - this->getWeapon()->getDamage());
                this->getWeapon()->setAmmo(this->getWeapon()->getAmmo() - 1);
                if (user->getHealth() <= 0) {
                    user->setDead();
                }
            } else {
                cout << "No ammo" << endl;
            }
        } else {
            cout << "Out of range" << endl;
        }
    } else {
        cout << "User is dead" << endl;
    }
}

int User::distance(User* user) {
    return sqrt(pow(user->getX() - this->getX(), 2) + pow(this->getY() - user->getY(), 2));
}
