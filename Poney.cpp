#include "Poney.h"

Poney::Poney() : position(0, 0) {
    this->identifier = new char[10];
    strcpy(this->identifier, "");
}

Poney::Poney(char* identifier, Point position) : position(position) {
    this->identifier = new char[strlen(identifier) + 1];
    strcpy(this->identifier, identifier);
}

Poney::Poney(char *identifier, Point position, Foin *foin) : position(position), foin(foin) {
    this->identifier = new char[strlen(identifier) + 1];
    strcpy(this->identifier, identifier);
}

Poney::Poney(Poney const &p) : position(p.position) {
    this->identifier = new char[strlen(p.identifier) + 1];
    strcpy(this->identifier, p.identifier);
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
    return distance;
}

float Poney::moveTo(Poney &p) {
    float distance = this->position.distance(p.position);
    this->position = p.position;
    return distance;
}

float Poney::moveTo(int x, int y) {
    float distance = this->position.distance(x, y);
    this->position.setPoint(x, y);
    return distance;
}

void Poney::print() const {
    std::cout << "[" << this->identifier << "] position : (" << this->position.getX() << ", " << this->position.getY() << ")" << std::endl;
}

void Poney::reset() {
    this->position.setPoint(0, 0);
    strcpy(this->identifier, "");
}