#include "Poney.h"
#include "Foin.h"

void PoneyIdTest() {
    Point position(0,10);
    char identifier[] = "Fluttershy la poneyte";
    Poney poney(identifier, position);
    poney.print(); // affichage 1
    const char * retrieveId = poney.getIdentifier();
    //retrieveId[0] = 'B';
    poney.print(); // affichage 2
}

void poneyIdTest2() {
    Point position(0,10);
    char identifier[] = "Rainbow dash";
    Poney poney(identifier, position);
    poney.print(); // affichage 1
    identifier[0] = 'X';
    poney.print(); // affichage 2
}

void poneyCopyTest(){
    Poney p1("Rarity", Point(0,0));
    Poney p2 = p1;
    p1.setIdentifier("Twilight");
    p1.print();
    p2.print();
}

void poneyMoveTests(){
    Poney p1("Twilight", Point(0,0));
    Poney p2("Spike", Point(0,10));
    Point p = p1.getPosition();
    float distance = 0;
    distance = p1.moveTo(p2);
    std::cout << "distance : " << distance << std::endl; // affichage 1
    p1.print(); // affichage 2
    p.setY(50);
    std::cout << p.getY();
    p1.print(); // affichage 3
    distance = p1.moveTo(p);
    std::cout << "distance : " << distance << std::endl; // affichage 4
    p1.print(); // affichage 5
    distance = p1.moveTo(0, 80);
    std::cout << "distance : " << distance << std::endl; // affichage 6
    p1.print(); // affichage 7
    p2.print(); // affichage 8
}

int main() {

    Foin* foin = new Foin(10);

    Poney* p1 = new Poney("Twilight", Point(0,0), foin);

    p1->getFoin()->print();


    return 0;
}