#include "TraficLight.h"
#include "Rational.h"

int main() {

    Rational r1(2, 6);
    Rational r2(1, 3);

    Rational r3 = r1.multiply(r2);

    Rational r5 = r1 * r2;

    std::cout << r1.equals(r2) << std::endl;

    r3.print();

    r5.print();

    Rational r4 = r1 + r2;

    r4.print();


    return 0;
}