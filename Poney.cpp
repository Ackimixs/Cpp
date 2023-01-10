#include "Poney.h"
#include "Foin.h"

Poney::Poney() : Poney("Hello World", {0, 0}, new Foin()) {}

Poney::Poney(int x, int y) : Poney("Hello World", {x, y}, new Foin()) {}

Poney::Poney(char* identifier, Point position) : Poney(identifier, position, new Foin()) {}

Poney::Poney(char *identifier, Point position, Foin *foin) : position(position), foin(foin) {
    this->identifier = new char[strlen(identifier) + 1];
    strcpy(this->identifier, identifier);
}

Poney::Poney(Poney const &p) : position(p.position) {
    this->identifier = new char[strlen(p.identifier) + 1];
    strcpy(this->identifier, p.identifier);
    this->foin = p.foin;
}

Poney::~Poney() {
    delete[] this->identifier;
}

Point Poney::getPosition() const {
    return this->position;
}

const char *Poney::getIdentifier() const {
    return this->identifier;
}

Foin *Poney::getFoin() const {
    return this->foin;
}

void Poney::setPosition(Point position) {
    this->position = position;
}

void Poney::setIdentifier(char *identifier) {
    delete[] this->identifier;
    this->identifier = new char[strlen(identifier) + 1];
    strcpy(this->identifier, identifier);
}

void Poney::setFoin(Foin *foin) {
    this->foin = foin;
}

float Poney::moveTo(Point p) {
    float distance = this->position.distance(p);
    this->position = p;
    this->foin->manger((int) distance);
    return distance;
}

float Poney::moveTo(Poney &p) {
    float distance = this->position.distance(p.position);
    this->position = p.position;
    this->foin->manger((int) distance);
    return distance;
}

float Poney::moveTo(int x, int y) {
    float distance = this->position.distance(x, y);
    bool valid = this->foin->manger((int) (distance / 2));
    if (valid) {
        this->position.setPoint(x, y);
        return distance;
    }
    return 0;
}

void Poney::print() const {
    std::cout << "[" << this->identifier << "] position : (" << this->position.getX() << ", " << this->position.getY() << ")" << std::endl;
    this->foin->print();
}

void Poney::reset() {
    this->position.setPoint(0, 0);
    strcpy(this->identifier, "Hello World");
    this->foin->reset();
}