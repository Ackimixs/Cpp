//
// Created by acki on 12/13/22.
//

#include <cstdlib>
#include <ctime>
#include <sstream>
#include "PGM.h"

using namespace std;

int PGM::nbImage = 0;

int PGM::getLargeur() const {
    return largeur;
}

void PGM::setLargeur(int largeur) {
    PGM::largeur = largeur;
}

int PGM::getHauteur() const {
    return hauteur;
}

void PGM::setHauteur(int hauteur) {
    PGM::hauteur = hauteur;
}

int PGM::getValeurMax() const {
    return valeurMax;
}

void PGM::setValeurMax(int valeurMax) {
    PGM::valeurMax = valeurMax;
}

int **PGM::getData() const {
    return data;
}

void PGM::setData(int **data) {
    PGM::data = data;
}

void PGM::creeImage(int minpx, int maxpx) {
    srand (time(NULL));

    for (int i = 0; i < largeur; i++) {
        for (int j = 0; j < hauteur; j++) {
            data[i][j] = rand() % (maxpx - minpx) + minpx;
        }
    }
}

PGM::PGM() : largeur(0), hauteur(0), valeurMax(0), data(nullptr) {
    nbImage++;
}

PGM::PGM(int largeur, int hauteur, int valeurMin, int valeurMax) : largeur(largeur), hauteur(hauteur), valeurMin(valeurMin), valeurMax(valeurMax), data(nullptr) {
    initImage();
    nbImage++;
}

int PGM::getValeurMin() const {
    return valeurMin;
}

void PGM::setValeurMin(int valeurMin) {
    PGM::valeurMin = valeurMin;
}

void PGM::initImage() {
    data = new int*[largeur];
    for (int i = 0; i < largeur; i++) {
        data[i] = new int[hauteur];
    }

    **data = {0};
}

void PGM::supprImage() {
    for (int i = 0; i < largeur; i++) {
        delete[] data[i];
    }
    delete[] data;
}

PGM::~PGM() {
    supprImage();
}

PGM::PGM(const PGM &pgm) {
    largeur = pgm.largeur;
    hauteur = pgm.hauteur;
    valeurMax = pgm.valeurMax;
    valeurMin = pgm.valeurMin;
    initImage();
    for (int i = 0; i < largeur; i++) {
        for (int j = 0; j < hauteur; j++) {
            data[i][j] = pgm.data[i][j];
        }
    }
    nbImage++;
}

void PGM::afficherImage() {
    for (int i = 0 ; i < largeur; i++) {
        for (int j = 0; j < hauteur; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void PGM::ecrireFichier(char *nom_fichier) {
    ofstream myfile;
    myfile.open(nom_fichier);
    myfile << "P2" << endl;
    myfile << largeur << " " << hauteur << endl;
    myfile << valeurMax << endl;
    for (int i = 0; i < largeur; i++) {
        for (int j = 0; j < hauteur; j++) {
            myfile << data[i][j] << " ";
        }
        myfile << endl;
    }
}

int PGM::getNbImage() {
    return nbImage;
}

void PGM::dessinRect(int x1, int y1, int x2, int y2, int val) {
    for (int i = 0; i < largeur; i++) {
        for (int j = 0; j < hauteur; j++) {
            if ((i == x1 || i == x2) && (j >= y1 && j <= y2)) {
                data[i][j] = val;
            }
            else if ((j == y1 || j == y2) && (i >= x1 && i <= x2)) {
                data[i][j] = val;
            }
        }
    }
}

void PGM::dessinLigne(int x1, int x2, int line, int val) {
    for (int i = 0; i < largeur; i++) {
        for (int j = 0; j < hauteur; j++) {
            if (i == line && (j >= x1 && j <= x2)) {
                data[i][j] = val;
            }
        }
    }
}

void PGM::dessinCroix(int x, int y, int val) {
    for (int i = 0; i < largeur; i++) {
        for (int j = 0; j < hauteur; j++) {
            if (data[i][j] == valeurMin) {
                if (i == x && (j >= y-1 && j <= y+1)) {
                    data[i][j] = valeurMax;
                } else if (j == y && (i >= x-1 && i <= x+1)) {
                    data[i][j] = valeurMax;
                }
            }
        }
    }
}

void PGM::lectureFichier(char* nom_fichier) {
    ifstream monfichier;
    string ligne;
    stringstream s;
    monfichier.open(nom_fichier);
    if (monfichier.is_open()){
        getline(monfichier,ligne);
        s << monfichier.rdbuf();
        s >> largeur >> hauteur;
        s >> valeurMax;
        initImage();
        for (int i = 0; i < largeur; i++) {
            for (int j = 0; j < hauteur; j++) {
                s >> data[i][j];
            }
        }
    }
    monfichier.close();
}

void PGM::seuil(int seuil) {
    for (int i = 0; i < largeur; i++) {
        for (int j = 0; j < hauteur; j++) {
            if (data[i][j] > seuil) {
                data[i][j] = valeurMax;
            } else {
                data[i][j] = 0;
            }
        }
    }
}

void PGM::flue(int centerX, int centerY, int size) {
    PGM* newPgm = new PGM(*this);

    int average;
    for (int i = centerX-size; i < centerX+size; i++) {
        for (int j = centerY-size; j < centerY+size; j++) {
            average = getMoyenne(i, j, size, newPgm);
            cout << average << endl;
            data[i][j] = average;
        }
    }
}

int PGM::getMoyenne(int centerX, int centerY, int size, PGM* newPgm) {
    int nbMoyenne = 0;
    int pixelAverage = 0;
    for (int i=centerX-size; i < centerX+size; i++) {
        for (int j=centerY-size; i < centerY+size; i++) {
            if (i > 0 && i < newPgm->getLargeur() && j > 0 && j < newPgm->getHauteur()) {
                pixelAverage+=newPgm->data[i][j];
                nbMoyenne++;
            }
        }
    }
    if (nbMoyenne) {
        return pixelAverage/nbMoyenne;
    }
    return pixelAverage;
}