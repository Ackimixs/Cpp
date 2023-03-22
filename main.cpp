#include <map>
#include "Vehicule.h"
#include <list>
#include <algorithm>

void displayTests1(){

    Vehicule vehicule("CC-987-JU", Point(5,6), 50, 5.3);
    VehiculeGaz gasVehicule("XY-358-PQ", Point(25,3), 60, 6.8, 95);

    VehiculeDiesel dieselVehicule("HD-888-ZY", Point(2,10), 40, 5.5, true);
}

void displayTests2(){

    Vehicule vehicle("CC-987-JU", Point(5,6), 50, 5.3);
    vehicle.affichage();

    std::cout << std::endl;

    VehiculeGaz gasVehicle("XY-358-PQ", Point(25,3), 60, 6.8, 95);
    gasVehicle.affichage();

    VehiculeDiesel dieselVehicle("HD-888-ZY", Point(2,10), 40, 5.5, true);
    dieselVehicle.affichage();
}

void consumptionTests(){
    VehiculeDiesel dieselVehicle("XY-358-PQ", Point(2,10), 8, 5, false);
    std::cout << "*******" << std::endl;
    float traveletDist1 = dieselVehicle.moveTo(0, 100);
    std::cout << "Traveled distance: " << traveletDist1 << std::endl;
    dieselVehicle.affichage();
    std::cout << "*******" << std::endl;
    float traveletDist2 = dieselVehicle.moveTo(0, 200);
    std::cout << "Traveled distance : " << traveletDist2 << std::endl;
    dieselVehicle.affichage();
}

void testHiterence() {
    VehiculeDiesel v1("VehiculeDiesel", 1, 2, 3, 4, true);
    VehiculeGaz v2("VehiculeGas", 5, 7, 4, 2, 5);

    v1.setPosition(Point(5, 5));
    v1.setFiltreAParticule(false);
    v1.setConsommation(10);
    v1.setQtCarburant(40);

    std::cout << v1.getFiltreAParticule() << std::endl << v1.getConsommation() << std::endl << v1.getName() << std::endl << v1.getQtCarburant() << std::endl;
}

int main() {
/*
    Point p1(4, 6);

    VehiculeDiesel v1("VehiculeDiesel", 1, 2, 3, 4, true);

    VehiculeDiesel v2(v1);

    v2.setPosition(p1);

    v2.affichage();

    VehiculeGaz v3("VehiculeGas", 5, 7, 4, 2, 5);

    v3.affichage();
*/

    // testHiterence();

    // displayTests2();

    consumptionTests();


    return 0;
}
