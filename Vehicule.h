#include <string>
#include "Point.h"
#include <istream>

#ifndef TP8_VEHICULE_H
#define TP8_VEHICULE_H


class Vehicule {
private:
    std::string name;
    Point position;
protected:
    float qtCarburant;
    float consommation;
public:

    Vehicule() : name("Vehicule"), position(0, 0), qtCarburant(0), consommation(0) {};
    Vehicule(std::string name, Point position, float qtCarburant, float consommation) : name(name), position(position), qtCarburant(qtCarburant), consommation(consommation) {};
    Vehicule(std::string name, int x, int y, float qtCarburant, float consommation) : name(name), position(x, y), qtCarburant(qtCarburant), consommation(consommation) {};
    Vehicule(Vehicule const &v) : name(v.name), position(v.position), qtCarburant(v.qtCarburant), consommation(v.consommation) {
        std::cout << "Vehicule(Vehicule const &v) " << this << std::endl;
    };

    virtual ~Vehicule() {
        // std::cout << "Destruction de Vehicule" << std::endl;
    };

    std::string getName() const {
        return name;
    };
    Point getPosition() const {return position;};

    void setName(std::string name) {this->name = name;};
    void setPosition(Point position) {this->position = position;};
    void setPosition(int x, int y) {
        this->position.setX(x);
        this->position.setY(y);
    };

    float getQtCarburant() const {return qtCarburant;};
    float getConsommation() const {return consommation;};

    void setQtCarburant(float qtCarburant) {this->qtCarburant = qtCarburant;};
    void setConsommation(float consommation) {this->consommation = consommation;};

    void affichage() const {
            std::cout << "[" << name << "] "; position.afficher(); std::cout << ", consomation : " << consommation << ", fuel left : " << qtCarburant;
    };

    float moveTo(Point p) {
        float distance = position.distance(p);
        float fuelNeeded = distance * consommation / 100;
        if (fuelNeeded > qtCarburant) {
            float d = 100 * qtCarburant / consommation;
            float ratio = d / distance;
            Point M((1-ratio) * position.getX() + ratio * p.getX(), (1-ratio) * position.getY() + ratio * p.getY());
            std::cout << "Not enough fuel, moving to ";
            M.afficher();
            setPosition(M);
            setQtCarburant(0);
            std::cout << std::endl;
            return d;
        }
        if (qtCarburant == 0) {
            std::cout << "No fuel left" << std::endl;
            return 0;
        }
        setQtCarburant(qtCarburant - fuelNeeded);
        position = p;
        return distance;
    };

    float moveTo(int x, int y) {
        return moveTo(Point(x, y));
    };

    void setIdentifier(std::string identifier) {
        this->name = std::move(identifier);
    }
};

class VehiculeDiesel : public Vehicule {
private:
    bool filtreAParticule;
public:
    VehiculeDiesel() : Vehicule() {};
    VehiculeDiesel(std::string name, Point position, float qtCarburant, float consommation, bool filtreAParticule) : Vehicule(name, position, qtCarburant, consommation), filtreAParticule(filtreAParticule) {};
    VehiculeDiesel(std::string name, int x, int y, float qtCarburant, float consommation, bool filtreAParticule) : Vehicule(name, x, y, qtCarburant, consommation), filtreAParticule(filtreAParticule) {};
    VehiculeDiesel(VehiculeDiesel const &v) : Vehicule(v), filtreAParticule(v.filtreAParticule) {
        std::cout << "VehiculeDiesel(VehiculeDiesel const &v) " << this << std::endl;
    };

    virtual ~VehiculeDiesel() {
        // std::cout << "Destruction de VehiculeDiesel" << std::endl;
    };

    bool getFiltreAParticule() const {return filtreAParticule;};

    void setFiltreAParticule(bool filtreAParticule) {this->filtreAParticule = filtreAParticule;};

    void affichage() const {
        Vehicule::affichage();
        std::cout << ", filter : " << (this->filtreAParticule ? "yes" : "no") << std::endl;
    };
};

class VehiculeGaz : public Vehicule {
private:
    int tauxOctane;
public:
    VehiculeGaz() : Vehicule() {};
    VehiculeGaz(std::string name, Point position, float qtCarburant, float consommation, int tauxOctane) : Vehicule(name, position, qtCarburant, consommation), tauxOctane(tauxOctane) {
        if (tauxOctane > 95) {
            this->consommation = consommation * (tauxOctane - 1) / 100;
        };
    };
    VehiculeGaz(std::string name, int x, int y, float qtCarburant, float consommation, int tauxOctane) : Vehicule(name, x, y, qtCarburant, consommation), tauxOctane(tauxOctane) {};
    VehiculeGaz(VehiculeGaz const &v) : Vehicule(v), tauxOctane(v.tauxOctane) {
        std::cout << "VehiculeGaz(VehiculeGaz const &v) " << this << std::endl;
    };

    virtual ~VehiculeGaz() {
        // std::cout << "Destruction de VehiculeGaz" << std::endl;
    };

    int getTauxOctane() const {return tauxOctane;};

    void setTauxOctane(int tauxOctane) {this->tauxOctane = tauxOctane;};

    void affichage() const {
        Vehicule::affichage();
        std::cout << ", octane rating : " << tauxOctane << std::endl;
    };
};

#endif //TP8_VEHICULE_H
