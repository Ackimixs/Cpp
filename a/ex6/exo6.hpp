#include <iostream>
#include <string>

using namespace std;

typedef struct eleves {
  int age;
  float poids;
  string name;
  bool sympa;
} eleves;


void remplir(eleves& eleve, int& age);
void remplir(eleves& eleve, float& poids);
void remplir(eleves& eleve, string name);
void remplir(eleves& eleve, bool& sympa);

string getRandomName(string* nameEleve, int& size);

void setAll(eleves* eleve, int size);

void printAllEleve(eleves* eleve, int size);
void printArray(string* nameEleve, int& size);
void printEleve(eleves& eleve);
