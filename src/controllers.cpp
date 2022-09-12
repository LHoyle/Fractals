#include "image_menu.h"

int assignment1(std::istream &is, std::ostream &os)
{
    int value = askQuestions3(is, os);
    return value;
}

int assignment2(std::istream &is, std::ostream &os)
{
    Image imag = Image();
    diagonalQuadPattern(is, os, imag);
    drawAsciiImage(is, os, imag);
    return 0;
}

/*int assignment3(std::istream &is, std::ostream &os)
{
    PPM ppm = PPM();
    stripedDiagonalPattern(is, os, ppm);
    writeUserImage(is, os, ppm);
    return 0;
}*/