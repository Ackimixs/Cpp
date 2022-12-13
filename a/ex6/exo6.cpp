#include "exo6.hpp"

#include <utility>

int main() {
    eleves me[10];
    int size = 10;

    setAll(me, size);
    printAllEleve(me, size);
    return 0;
}

void remplir(eleves& eleve, int& age) {
    if (age > 0 && age < 100) {
        eleve.age = age;
    } else {
        exit(1);
    }
}

void remplir(eleves& eleve, float& poids) {
    if (poids > 30 && poids < 200) {
        eleve.poids = poids;
    } else {
        exit(1);
    }
}

void remplir(eleves& eleve, string name) {
    eleve.name = std::move(name);
}

void remplir(eleves& eleve, bool& sympa) {
  eleve.sympa = sympa;
}

string getRandomName(string* nameEleve, int& size) {
    int random = rand() % 20;
    string name = nameEleve[random];
    for (int i = random; i < size-1; i++) {
        nameEleve[i] = nameEleve[i + 1];
    }
    size--;
    return name;
}

void printEleve(eleves& eleve) {
    std::cout << "Age : " << eleve.age << std::endl;
    std::cout << "Poids : " << eleve.poids << std::endl;
    std::cout << "Nom : " << eleve.name << std::endl;
    std::cout << "Sympa : " << eleve.sympa << std::endl;
}

void printAllEleve(eleves* eleve, int size) {
    for (int i = 0; i < size; i++) {
        printEleve(eleve[i]);
    }
}

void printArray(string* nameEleve, int& size) {
    for (int i = 0; i < size; i++) {
        cout << nameEleve[i] << endl;
    }
}

void setAll(eleves* eleve, int size) {
    string nameEleve[20] = {"eleve1", "eleve2", "eleve3", "eleve4", "eleve5", "eleve6", "eleve7", "eleve8", "eleve9", "eleve10", "eleve11", "eleve12", "eleve13", "eleve14", "eleve15", "eleve16", "eleve17", "eleve18", "eleve18", "eleve20"};
    int nameEleveSize = 20;
    for (int i = 0; i < size-3; i++) {
        int randAge = rand() % 50;
        float randPoids = rand() % 170;
        bool randSympa = rand() % 2;


        remplir(eleve[i], randAge);
        remplir(eleve[i], randPoids);
        remplir(eleve[i], getRandomName(nameEleve, nameEleveSize));
        remplir(eleve[i], randSympa);
    }
}