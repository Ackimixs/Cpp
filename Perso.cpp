//
// Created by acki on 12/6/22.
//

#include "Perso.h"

int Perso::nbPerso = 0;

Perso::Perso(): Perso(nullptr, 100, 0, 0, new Weapon) {}

Perso::Perso(int pv): Perso(nullptr, pv, 0, 0, new Weapon) {}

Perso::Perso(int x, int y) : Perso(nullptr, 100, x, y, new Weapon) {}

Perso::Perso(char *name) : Perso(name, 100, 0, 0, new Weapon) {}

Perso::Perso(Weapon *weapon) : Perso(nullptr, 100, 0, 0, weapon) {}

Perso::Perso(char* name, int pv, int x, int y, Weapon *weapon) : name(new char[30]), pv(pv), pos({x,y}), weapon(weapon), alive(true) {
    if (name == nullptr) {
        strcpy(this->name, "Default Perso");
    } else {
        strcpy(this->name, name);
    }
    Perso::nbPerso++;
}

Perso::Perso(const Perso &perso) {
    this->name = new char[10];
    strcpy(this->name, perso.name);
    this->pv = perso.pv;
    this->pos = perso.pos;
    this->weapon = new Weapon(*perso.weapon);
    this->alive = perso.alive;
    Perso::nbPerso++;
}

void Perso::display() {
    Color::Modifier red(Color::FG_RED);
    Color::Modifier bold(Color::BOLD);
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier yellow(Color::FG_YELLOW);
    Color::Modifier reset(Color::RESET);

    std::cout << bold << red << "Name: " << this->name << reset << std::endl;
    std::cout << bold << blue << "PV: " << this->pv<< reset  << std::endl;
    std::cout << bold << green << "Position: (" << this->pos.x << ", " << this->pos.y << ")"<< reset  << std::endl;
    std::cout << bold << yellow << "Weapon: " << reset << std::endl;
    this->weapon->display();
}

Perso::~Perso() {
    delete[] this->name;
    delete this->weapon;
}

void Perso::attack(Perso& target) {
    target.setPv(target.getPv()-this->weapon->getDamage());
}

void Perso::move(int x, int y) {
    setPos({x, y});
}

char *Perso::getName() const {
    return name;
}

void Perso::setName(char *name) {
    this->name = name;
}

int Perso::getPv() const {
    return pv;
}

void Perso::setPv(int pv) {
    if (this->getPv() - pv <= 0) {
        this->pv = 0;
        this->alive = false;
    } else {
        this->pv = pv;
    }
}

const Perso::Position &Perso::getPos() const {
    return pos;
}

void Perso::setPos(const Perso::Position &pos) {
    this->pos = pos;
}

Weapon *Perso::getWeapon() const {
    return weapon;
}

void Perso::setWeapon(Weapon *weapon) {
    this->weapon = weapon;
}

int Perso::getNbPerso() {
    return nbPerso;
}

bool Perso::isAlive() const {
    return alive;
}

void Perso::setAlive(bool alive) {
    Perso::alive = alive;
}