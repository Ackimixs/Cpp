//
// Created by acki on 12/13/22.
//
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>

#ifndef IMAGE_PGM_H
#define IMAGE_PGM_H

//IMPORTANT utilisation des coordonée en base cartésienne => (x,y) => (colonne, ligne) donc data[y][x]
class PGM {
private:
    int largeur;
    int hauteur;
    int valeurMin;
    int valeurMax;
    int **data;
public:

    static int nbImage;

    PGM();
    PGM(int largeur, int hauteur,int valeurMin, int valeurMax);
    PGM(const PGM &pgm);
    ~PGM();


    int getLargeur() const;

    void setLargeur(int largeur);

    int getHauteur() const;

    void setHauteur(int hauteur);

    int getValeurMax() const;

    void setValeurMax(int valeurMax);

    int **getData() const;

    void setData(int **data);

    int getValeurMin() const;

    void setValeurMin(int valeurMin);

    void initImage();

    void supprImage();

    void creeImage(int minpx=0, int maxpx=255);

    void afficherImage();

    void ecrireFichier(char* nom_fichier);

    static int getNbImage();

    void dessinRect(int x1, int y1, int x2, int y2, int val);

    void dessinLigne(int x1, int x2, int line, int val);

    void dessinCroix(int x0, int y0, int val, int size = 1);

    void lectureFichier(char* nom_fichier);

    void seuil(int seuil);

    void floue(int size);

    int getAverage(int centerX, int centerY, int size, PGM* newPgm);

    int getPixel(int x, int y);

    void setPixel(int x, int y, int val);

    void filtrerImage(int k);

    int getMedian(int x, int y, int size);

    void selectionSort(int* array, int size);

    void printArray(int* array, int size);
};


#endif //IMAGE_PGM_H
