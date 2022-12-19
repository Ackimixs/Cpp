#include "Vehicule.h"

Vehicule::Vehicule() : position(0, 0) {
    identifier = new char[10*sizeof(char)];
    strcpy(identifier, "");
}

Vehicule::Vehicule(Point position, char *identifier) : position(position) {
    this->identifier = new char[strlen(identifier)*sizeof(char)];
    strcpy(this->identifier, identifier);
}

Vehicule::Vehicule(Vehicule const &v) : position(v.position) {
    this->identifier = new char[strlen(v.identifier)*sizeof(char)];
    strcpy(this->identifier, v.identifier);
}

Point Vehicule::getPosition() const {
    return position;
}

char *Vehicule::getIdentifier() const {
    return identifier;
}

void Vehicule::setPosition(Point position) {
    this->position = position;
}

void Vehicule::setIdentifier(char *identifier) {
    this->identifier = new char[strlen(identifier)*sizeof(char)];
    strcpy(this->identifier, identifier);
}

float Vehicule::moveTo(int x, int y) {
    float distance = sqrt(pow(position.getX() - x, 2) + pow(position.getY() - y, 2));
    position.setX(x);
    position.setY(y);
    return distance;
}

float Vehicule::moveTo(Point p) {
    return moveTo(p.getX(), p.getY());
}

float Vehicule::moveTo(Vehicule v) {
    return moveTo(v.getPosition());
}

void Vehicule::print() {
    std::cout << "[" << identifier << "] position : (" << position.getX() << ", " << position.getY() << ")" << std::endl;
}