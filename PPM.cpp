//
// Created by acki on 12/14/22.
//

#include "PPM.h"

int PPM::nbImage = 0;

int PPM::getLargeur() const {
    return largeur;
}

void PPM::setLargeur(int largeur) {
    this->largeur = largeur;
}

int PPM::getHauteur() const {
    return hauteur;
}

void PPM::setHauteur(int hauteur) {
    this->hauteur = hauteur;
}

int PPM::getValeurMax() const {
    return valeurMax;
}

void PPM::setValeurMax(int valeurMax) {
    this->valeurMax = valeurMax;
}

int ***PPM::getData() const {
    return data;
}

void PPM::setData(int ***data) {
    this->data = data;
}

int PPM::getValeurMin() const {
    return valeurMin;
}

void PPM::setValeurMin(int valeurMin) {
    PPM::valeurMin = valeurMin;
}

void PPM::creeImage(int minpx, int maxpx) {
    srand (time(NULL));
    for (int y = 0; y < getHauteur(); y++) {
        for (int x = 0; x < getLargeur(); x++) {
            data[y][x][0] = rand() % (maxpx - minpx) + minpx;
            data[y][x][1] = rand() % (maxpx - minpx) + minpx;
            data[y][x][2] = rand() % (maxpx - minpx) + minpx;
        }
    }
}

void PPM::initImage() {
    data = new int**[getHauteur()];
    for (int y = 0; y < getHauteur(); y++) {
        data[y] = new int*[getLargeur()];
        for (int x = 0; x < getLargeur(); x++) {
            data[y][x] = new int[3];
        }
    }
    ***data = {0};
}

void PPM::supprImage() {
    for (int y = 0; y < getHauteur(); y++) {
        for (int x = 0; x < getLargeur(); x++) {
            delete[] data[y][x];
        }
        delete[] data[y];
    }
    delete[] data;
}

PPM::PPM() : largeur(0), hauteur(0), valeurMax(0), valeurMin(0), data(nullptr) {
    nbImage++;
}

PPM::PPM(int largeur, int hauteur, int valeurMin, int valeurMax) : largeur(largeur), hauteur(hauteur), valeurMin(valeurMin), valeurMax(valeurMax), data(nullptr) {
    initImage();
    nbImage++;
}

PPM::PPM(const PPM &ppm) {
    largeur = ppm.largeur;
    hauteur = ppm.hauteur;
    valeurMin = ppm.valeurMin;
    valeurMax = ppm.valeurMax;
    data = new int**[getHauteur()];
    for (int y = 0; y < getHauteur(); y++) {
        data[y] = new int*[getLargeur()];
        for (int x = 0; x < getLargeur(); x++) {
            data[y][x] = new int[3];
            data[y][x][0] = ppm.data[y][x][0];
            data[y][x][1] = ppm.data[y][x][1];
            data[y][x][2] = ppm.data[y][x][2];
        }
    }
    nbImage++;
}

PPM::~PPM() {
    supprImage();
    nbImage--;
}

void PPM::afficherImage() {
    cout << "P3" << endl;
    cout << getLargeur() << " " << getHauteur() << endl;
    cout << getValeurMax() << endl;

    for (int y = 0; y < getHauteur(); y++) {
        for (int i = 0; i < 3; i++) {
            for (int x = 0; x < getLargeur(); x++) {
                cout << data[y][x][i] << " ";
            }
            cout << endl;
        }
    }
}

void PPM::ecrireFichier(char *nom_fichier) {
    ofstream fichier(nom_fichier, ios::out | ios::trunc);
    if (fichier) {
        fichier << "P3" << endl;
        fichier << getLargeur() << " " << getHauteur() << endl;
        fichier << getValeurMax() << endl;

        for (int y = 0; y < getHauteur(); y++) {
            for (int x = 0; x < getLargeur(); x++) {
                fichier << data[y][x][0] << " " << data[y][x][1] << " " << data[y][x][2] << " ";
            }
            fichier << endl;
        }
        fichier.close();
    } else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void PPM::lectureFichier(char *nom_fichier) {
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
        for (int y = 0; y < getHauteur(); y++) {
            for (int x = 0; x < getLargeur(); x++) {
                s >> data[y][x][0] >> data[y][x][1] >> data[y][x][2];
            }
        }
    }
    monfichier.close();
}

void PPM::dessinerRect(int x1, int y1, int x2, int y2, int r, int g, int b) {
    for (int y = y1; y < y2; y++) {
        for (int x = x1; x < x2; x++) {
            if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur()) {
                data[y][x][0] = r;
                data[y][x][1] = g;
                data[y][x][2] = b;
            }
        }
    }
}

void PPM::dessinerLigne(int x1, int x2, int ligne, int r, int g, int b) {
    for (int x = x1; x <= x2; x++) {
        data[ligne][x][0] = r;
        data[ligne][x][1] = g;
        data[ligne][x][2] = b;
    }
}

void PPM::dessinerCroix(int x0, int y0, int r, int g, int b, int size) {
    for (int x = x0 - size; x < x0 + size; x++) {
        data[y0][x][0] = r;
        data[y0][x][1] = g;
        data[y0][x][2] = b;
    }
    for (int y = y0 - size; y < y0 + size; y++) {
        data[y][x0][0] = r;
        data[y][x0][1] = g;
        data[y][x0][2] = b;
    }
}

int PPM::getNbImage() {
    return nbImage;
}