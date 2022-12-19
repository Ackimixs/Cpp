#include "Vehicule.h"

int main() {

    Point pos(0, 10);

    char identifier[] = "ML-888-VK";

    Vehicule vehicule(pos, identifier);

    float distance = vehicule.moveTo(10, 10);

    vehicule.print();

    std::cout << "Distance : " << distance << std::endl;
}