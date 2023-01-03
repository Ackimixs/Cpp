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

Pixel **PPM::getData() const {
    return data;
}

void PPM::setData(Pixel **data) {
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
            data[y][x].r = rand() % (maxpx - minpx) + minpx;
            data[y][x].g = rand() % (maxpx - minpx) + minpx;
            data[y][x].b = rand() % (maxpx - minpx) + minpx;
        }
    }
}

void PPM::initImage() {
    data = new Pixel*[getHauteur()];
    for (int y = 0; y < getHauteur(); y++) {
        data[y] = new Pixel[getLargeur()];
    }
    **data = {0};
}

void PPM::supprImage() {
    for (int y = 0; y < getHauteur(); y++) {
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
    data = new Pixel*[getHauteur()];
    for (int y = 0; y < getHauteur(); y++) {
        data[y] = new Pixel[getLargeur()];
        for (int x = 0; x < getLargeur(); x++) {
            data[y][x].r = ppm.data[y][x].r;
            data[y][x].g = ppm.data[y][x].g;
            data[y][x].b = ppm.data[y][x].b;
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
        for (int x = 0; x < getLargeur(); x++) {
            cout << data[y][x].r << " " << data[y][x].g << " " << data[y][x].b << " ";
        }
        cout << endl;
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
                fichier << data[y][x].r << " " << data[y][x].g << " " << data[y][x].b << " ";
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
                s >> data[y][x].r >> data[y][x].g >> data[y][x].b;
            }
        }
    }
    monfichier.close();
}

void PPM::dessinerRect(int x1, int y1, int x2, int y2, int r, int g, int b) {
    for (int y = y1; y < y2; y++) {
        for (int x = x1; x < x2; x++) {
            if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur()) {
                data[y][x].r = r;
                data[y][x].g = g;
                data[y][x].b = b;
            }
        }
    }
}

void PPM::dessinerLigne(int x1, int x2, int ligne, int r, int g, int b) {
    for (int x = x1; x <= x2; x++) {
        data[ligne][x].r = r;
        data[ligne][x].g = g;
        data[ligne][x].b = b;
    }
}

void PPM::dessinerCroix(int x0, int y0, int r, int g, int b, int size) {
    for (int x = x0 - size; x < x0 + size; x++) {
        data[y0][x].r = r;
        data[y0][x].g = g;
        data[y0][x].b = b;
    }
    for (int y = y0 - size; y < y0 + size; y++) {
        data[y][x0].r = r;
        data[y][x0].g = g;
        data[y][x0].b = b;
    }
}

int PPM::getNbImage() {
    return nbImage;
}

void PPM::floue(int size) {
    PPM tmp(*this);
    for (int y = 0; y < getHauteur(); y++) {
        for (int x = 0; x < getLargeur(); x++) {
            int r = 0, g = 0, b = 0;
            int nb = 0;
            for (int y2 = y - size; y2 <= y + size; y2++) {
                for (int x2 = x - size; x2 <= x + size; x2++) {
                    if (x2 >= 0 && x2 < getLargeur() && y2 >= 0 && y2 < getHauteur()) {
                        r += tmp.data[y2][x2].r;
                        g += tmp.data[y2][x2].g;
                        b += tmp.data[y2][x2].b;
                        nb++;
                    }
                }
            }
            data[y][x].r = r / nb;
            data[y][x].g = g / nb;
            data[y][x].b = b / nb;
        }
    }
}

Pixel PPM::getPixel(int x, int y) {
    return data[y][x];
}

void PPM::setPixel(int x, int y, Pixel pixel) {
    data[y][x].r = pixel.r;
    data[y][x].g = pixel.g;
    data[y][x].b = pixel.b;
}

void PPM::filtrerImage(int k) {
    PPM* newPgm = new PPM(*this);

    Pixel median;
    for (int y = 0; y < getHauteur(); y++) {
        for (int x = 0; x < getLargeur(); x++) {
            median = newPgm->getMedian(x, y, k);
            setPixel(x, y, median);
        }
    }
}

Pixel PPM::getMedian(int x0, int y0, int size) {
    int* r = new int[size*size];
    int* g = new int[size*size];
    int* b = new int[size*size];
    int i = 0;
    for (int y = y0-((int) size/2); y < y0+((int) size/2); y++) {
        for (int x = x0 - ((int) size/2); x < x0 + ((int) size/2); x++) {
            if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur()) {
                r[i] = data[y][x].r;
                g[i] = data[y][x].g;
                b[i] = data[y][x].b;
                i++;
            }
        }
    }

    selectionSort(r, i);
    selectionSort(g, i);
    selectionSort(b, i);

    int R = r[i/2];
    int G = g[i/2];
    int B = b[i/2];

    delete[] r;
    delete[] g;
    delete[] b;

    return {R, G, B};
}

void PPM::selectionSort(int* array, int size) {
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