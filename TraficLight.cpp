#include "TraficLight.h"

TraficLight::TraficLight(SignalColor color) {
    if (color != SignalColor::RED && color != SignalColor::YELLOW && color != SignalColor::GREEN) {
        setColor(SignalColor::RED);
    } else {
        setColor(color);
    }
}

void TraficLight::changeColor() {
    switch (getColor()) {
        case SignalColor::RED:
            setColor(SignalColor::GREEN);
            break;
        case SignalColor::YELLOW:
            setColor(SignalColor::RED);
            break;
        case SignalColor::GREEN:
            setColor(SignalColor::YELLOW);
            break;
    }
}

SignalColor TraficLight::getColor() const {
    return color;
}

void TraficLight::setColor(SignalColor color) {
    this->color = color;
}

void TraficLight::print() {
    std::cout << "+-----+" << std::endl << "|     |" << std::endl;
    if (getColor() == SignalColor::RED) {
        std::cout << "| (R) |" << std::endl;
    } else {
        std::cout << "| ( ) |" << std::endl;
    }
    std::cout << "|     |" << std::endl;
    if (getColor() == SignalColor::YELLOW) {
        std::cout << "| (Y) |" << std::endl;
    } else {
        std::cout << "| ( ) |" << std::endl;
    }
    std::cout << "|     |" << std::endl;
    if (getColor() == SignalColor::GREEN) {
        std::cout << "| (G) |" << std::endl;
    } else {
        std::cout << "| ( ) |" << std::endl;
    }
    std::cout << "|     |" << std::endl << "+-----+" << std::endl;

    std::cin.get();
    changeColor();
    print();
}