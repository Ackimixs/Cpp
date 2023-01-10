#include "Foin.h"
#include "Poney.h"

Foin::Foin() : quantity(0) {}
Foin::Foin(int quantity) : quantity(quantity) {}
Foin::Foin(int quantity, Poney* poney) : quantity(quantity), poney(poney) {}
Foin::Foin(Foin const &f) : quantity(f.quantity) {}

int Foin::getQuantity() const {
    return this->quantity;
}

bool Foin::manger(int quantity) {
    if (quantity < 0) {
        std::cout << "quantity must be positive" << std::endl;
        return false;
    }
    if (quantity > this->quantity) {
        std::cout << "Oh no you don't have enough wheat" << std::endl;
        return false;
    }
    this->quantity -= quantity;
    return true;
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

void Foin::reset() {
    this->quantity = 0;
}