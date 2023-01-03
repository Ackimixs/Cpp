//
// Created by acki on 12/13/22.
//


#include "PGM.h"

using namespace std;

int PGM::nbImage = 0;

int PGM::getLargeur() const {
    return largeur;
}

void PGM::setLargeur(int largeur) {
    this->largeur = largeur;
}

int PGM::getHauteur() const {
    return hauteur;
}

void PGM::setHauteur(int hauteur) {
    this->hauteur = hauteur;
}

int PGM::getValeurMax() const {
    return valeurMax;
}

void PGM::setValeurMax(int valeurMax) {
    this->valeurMax = valeurMax;
}

int **PGM::getData() const {
    return data;
}

void PGM::setData(int **data) {
    this->data = data;
}

void PGM::creeImage(int minpx, int maxpx) {
    srand (time(NULL));

    for (int i = 0; i < getHauteur(); i++) {
        for (int j = 0; j < getLargeur(); j++) {
            data[i][j] = rand() % (maxpx - minpx) + minpx;
        }
    }
}

PGM::PGM() : largeur(0), hauteur(0), valeurMax(0), valeurMin(0), data(nullptr) {
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
    this->valeurMin = valeurMin;
}

void PGM::initImage() {
    data = new int*[getHauteur()];
    for (int y = 0; y < getHauteur(); y++) {
        data[y] = new int[getLargeur()];
    }

    **data = {0};
}

void PGM::supprImage() {
    for (int y = 0; y < getHauteur(); y++) {
        delete[] data[y];
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
    for (int y = 0; y < getHauteur(); y++) {
        for (int x = 0; x < getLargeur(); x++) {
            setPixel(x, y, pgm.data[y][x]);
        }
    }
    nbImage++;
}

void PGM::afficherImage() {
    for (int y = 0 ; y < getHauteur(); y++) {
        for (int x = 0; x < getLargeur(); x++) {
            cout << getPixel(x, y) << " ";
        }
        cout << endl;
    }
}

void PGM::ecrireFichier(char *nom_fichier) {
    ofstream myfile;
    myfile.open(nom_fichier);
    myfile << "P2" << endl;
    myfile << getLargeur() << " " << getHauteur() << endl;
    myfile << getValeurMax() << endl;
    for (int y = 0; y < getHauteur(); y++) {
        for (int x = 0; x < getLargeur(); x++) {
            myfile << data[y][x] << " ";
        }
        myfile << endl;
    }
}

int PGM::getNbImage() {
    return nbImage;
}

void PGM::dessinRect(int x1, int y1, int x2, int y2, int val) {
    for (int y = y1; y < y2; y++) {
        for (int x = x1; x < x2; x++) {
            if ((x == x1 || x == x2) && (y >= y1 && y <= y2)) {
                setPixel(x, y, val);
            }
            else if ((y == y1 || y == y2) && (x >= x1 && x <= x2)) {
                setPixel(x, y, val);
            }
        }
    }
}

void PGM::dessinLigne(int x1, int x2, int line, int val) {
    for (int x = x1; x <= x2; x++) {
        setPixel(x, line, val);
    }
}


void PGM::dessinCroix(int x0, int y0, int val, int size) {
    for (int y = y0-size; y < y0+size; y++) {
        for (int x = x0-size; x < x0+size; x++) {
            if (x == x0 && (y >= y0-size && y <= y0+size)) {
                setPixel(x, y, val);
            } else if (y == y0 && (x >= x0-size && x <= x0+size)) {
                setPixel(x, y, val);
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
        for (int y = 0; y < getHauteur(); y++) {
            for (int x = 0; x < getLargeur(); x++) {
                s >> data[y][x];
            }
        }
    }
    monfichier.close();
}

void PGM::seuil(int seuil) {
    for (int y = 0; y < getLargeur(); y++) {
        for (int x = 0; x < getHauteur(); x++) {
            if (getPixel(x, y) > seuil) {
                setPixel(x, y, valeurMax);
            } else {
                setPixel(x, y, 0);
            }
        }
    }
}

void PGM::floue(int size) {
    PGM* newPgm = new PGM(*this);

    int average;
    for (int y = 0; y < getHauteur(); y++) {
        for (int x = 0; x < getLargeur(); x++) {
            average = newPgm->getAverage(x, y, size, newPgm);
            setPixel(x, y, average);
        }
    }
}

int PGM::getAverage(int centerX, int centerY, int size, PGM* newPgm) {
    int nbMoyenne = 0;
    int pixelAverage = 0;
    for (int y=centerY-size; y < centerY+size; y++) {
        for (int x=centerX-size; x < centerX+size; x++) {
            if (x >= 0 && x < newPgm->getLargeur() && y >= 0 && y < newPgm->getHauteur()) {
                pixelAverage+=newPgm->getPixel(x, y);
                nbMoyenne++;
            }
        }
    }
    if (nbMoyenne != 0) {
        return pixelAverage/nbMoyenne;
    }
    return pixelAverage;
}

int PGM::getPixel(int x, int y) {
    return data[y][x];
}

void PGM::setPixel(int x, int y, int val) {
    data[y][x] = val;
}

void PGM::filtrerImage(int k) {
    PGM* newPgm = new PGM(*this);

    int median;
    for (int y = 0; y < getHauteur(); y++) {
        for (int x = 0; x < getLargeur(); x++) {
            median = newPgm->getMedian(x, y, k);
            setPixel(x, y, median);
        }
    }
}

int PGM::getMedian(int x0, int y0, int size) {
    int* array = new int[size*size];
    int i = 0;
    for (int y = y0-((int) size/2); y < y0+((int) size/2); y++) {
        for (int x = x0 - ((int) size/2); x < x0 + ((int) size/2); x++) {
            if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur()) {
                array[i] = getPixel(x, y);
                i++;
            }
        }
    }

    selectionSort(array, i);

    int nb = array[(int) ceil(i/2)];

    delete[] array;

    return nb;
}

void PGM::selectionSort(int* array, int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void PGM::printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}