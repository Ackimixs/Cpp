//
// Created by acki on 12/14/22.
//

#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#ifndef IMAGE_PPM_H
#define IMAGE_PPM_H

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

class PPM {
private:
    int largeur;
    int hauteur;
    int valeurMin;
    int valeurMax;
    Pixel **data;
public:
    static int nbImage;

    PPM();
    PPM(int largeur, int hauteur,int valeurMin, int valeurMax);
    PPM(const PPM &ppm);
    ~PPM();

    int getLargeur() const;
    int getHauteur() const;
    int getValeurMax() const;
    int getValeurMin() const;
    Pixel **getData() const;

    void setLargeur(int largeur);
    void setHauteur(int hauteur);
    void setValeurMax(int valeurMax);
    void setValeurMin(int valeurMin);
    void setData(Pixel **data);

    void initImage();
    void supprImage();
    void creeImage(int minpx=0, int maxpx=255);
    void afficherImage();
    void ecrireFichier(char* nom_fichier);
    void lectureFichier(char* nom_fichier);

    void dessinerLigne(int x1, int x2, int ligne, int r, int g, int b);
    void dessinerRect(int x1, int y1, int x2, int y2, int r, int g, int b);
    void dessinerCroix(int x0, int y0, int r, int g, int b, int size = 1);

    static int getNbImage();

    void floue(int size);

    int getAverage(int centerX, int centerY, int size, PPM* newPpm);

    Pixel getPixel(int x, int y);

    void setPixel(int x, int y, Pixel pixel);

    void filtrerImage(int k);

    Pixel getMedian(int x0, int y0, int size);

    void selectionSort(int* array, int size);
};


#endif //IMAGE_PPM_H
