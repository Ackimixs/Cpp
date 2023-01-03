#include "PGM.h"

int main() {

    PGM image;

    image.lectureFichier("lena.pgm");

    image.ecrireFichier("myImage1.pgm");

    return 0;
}