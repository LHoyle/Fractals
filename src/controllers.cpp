#include "image_menu.h"
#include "Image.h"

int assignment1(std::istream &is, std::ostream &os)
{
    int value = askQuestions3(is, os);
    return value;
}

int assignment2(std::istream &is, std::ostream &os)
{
    Image imag = Image();
    void diagonalQuadPattern(is, os, imag);
    void drawAsciiImage(is, os, imag);
    return 0;
}