#include "PPM.h"

int main() {

    PPM image;

    image.lectureFichier("myImage.ppm");

    image.ecrireFichier("myImage1.ppm");

    return 0;
}