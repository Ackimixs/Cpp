#include "Vehicule.h"
#include <iostream>
#include <vector>

void gasVehicleCopyTest(){
     VehiculeGaz original("XY-358-PQ", Point(25,3), 60, 6.8, 95);
     VehiculeGaz copy = original;
     original.setIdentifier("XXX");
     original.affichage();
     copy.affichage();
}

void dieselVehicleDestructionTest() {
     VehiculeDiesel* dieselVehicle = new VehiculeDiesel("HD-888-ZY", Point(2, 10), 40, 5.5, true);
     Vehicule* vehicle = dieselVehicle; // upcast
     delete vehicle;
}

void octaneRatingConsumptionTests(){
    VehiculeGaz gasVehicle95("XY-358-PQ", Point(0,0), 30, 5, 95);
    std::cout << "Traveled distance : " << gasVehicle95.moveTo(0, 100) << std::endl;
    gasVehicle95.affichage();
    VehiculeGaz gasVehicle98("HD-888-ZY", Point(0,0), 30, 5, 98);
    std::cout << "Traveled distance : " << gasVehicle98.moveTo(0, 100) << std::endl;
    gasVehicle98.affichage();
}

void octaneRatingConsumptionTestsWithUpcast2(std::vector<Vehicule*> &vehicles){
    for (auto vehicle : vehicles) {
        std::cout << "Traveled distance : " << vehicle->moveTo(0, 100) << std::endl;
        vehicle->affichage();
        std::cout << std::endl;
    }
}

void octaneRatingConsumptionTestsWithUpcast(){
    VehiculeGaz gasVehicle95("XY-358-PQ", Point(0,0), 30, 5, 95);
    VehiculeGaz gasVehicle98("HD-888-ZY", Point(0,0), 30, 5, 98);
    std::vector<Vehicule*> vehicles = { &gasVehicle95, &gasVehicle98 };
    octaneRatingConsumptionTestsWithUpcast2(vehicles);
}



int main() {
    //gasVehicleCopyTest();

    // dieselVehicleDestructionTest();

    // octaneRatingConsumptionTests();

    octaneRatingConsumptionTestsWithUpcast();

    return 0;
}
