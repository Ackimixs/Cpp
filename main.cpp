#include "PGM.h"

int main() {

    PGM pgm;

    pgm.lectureFichier("lena.pgm");

    pgm.ecrireFichier("lena2.pgm");

    pgm.flue(7);

    pgm.ecrireFichier("floue.pgm");

    //pgm.ecrireFichier("test.pgm");

    return 0;
}