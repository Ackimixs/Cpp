//
// Created by acki on 1/3/23.
//

#include "Foin.h"


Foin::Foin() : quantity(0) {}
Foin::Foin(int quantity) : quantity(quantity) {}
Foin::Foin(int quantity, Poney* poney) : quantity(quantity), poney(poney) {}
Foin::Foin(Foin const &f) : quantity(f.quantity) {}

int Foin::getQuantity() const {
    return this->quantity;
}

void Foin::manger(int quantity) {
    if (quantity < 0) {
        throw std::invalid_argument("quantity must be positive");
    }
    if (quantity > this->quantity) {
        throw std::invalid_argument("quantity must be less than the quantity of foin");
    }
    this->quantity -= quantity;
}

void Foin::remplir(int quantity) {
    if (quantity < 0) {
        throw std::invalid_argument("quantity must be positive");
    }
    this->quantity += quantity;
}

void Foin::print() const {
    std::cout << "Foin: " << this->quantity << std::endl;
}