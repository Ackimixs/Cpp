#include "PGM.h"

int main() {

    PGM pgm;

    pgm.lectureFichier("lena.pgm");

    pgm.flue(120, 200, 10);

    pgm.ecrireFichier("new.pgm");

    //pgm.ecrireFichier("test.pgm");

    return 0;
}