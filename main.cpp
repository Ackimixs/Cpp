#include "Point.h"
#include "array.h"
#include "Personnage.h"

int main() {

    // Point<float> p1(1.4, 2.8);

    // p1.display();
/*
    array<int> a1(10);

    for (int i = 0; i < 10; i++) {
        a1[i] = i;
    }

    a1.display();

    iterator<int> it(a1);

    it.decalage(3);

    it++;

    it.set(42);

    a1.display();

    it.decalage(2);

    it.set(50);

    a1.display();

    it--;

    it.set(100);

    a1.display();
*/
    Personnage<Epee> p1(100, "Bob", new Fourreau<Epee>(new Epee()));

    Personnage<Katana> p2(100, "Alice", new Fourreau<Katana>(new Katana()));

    Personnage<Pistolet> p3(100, "John", new Fourreau<Pistolet>(new Pistolet()));

    p1.attaque(p2);

    p2.attaque(p3);

    p3.attaque(p1);
    p3.attaque(p1);
    p3.attaque(p1);

    p1.display();

    p2.display();

    p3.display();

    return 0;
}