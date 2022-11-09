#include "MandelbrotSet.h"
#include <cmath>
MandelbrotSet::MandelbrotSet()
    : ComplexFractal()
{
    NumberGrid::setMaxNumber(255);
}
MandelbrotSet::MandelbrotSet(const int &height, const int &width, const double &min_x, const double &max_x, const double &min_y, const double &max_y)
    : ComplexFractal(height, width, min_x, max_x, min_y, max_y)
{

    NumberGrid::setMaxNumber(255);
}
MandelbrotSet::~MandelbrotSet() {}

void MandelbrotSet::calculateNextPoint(const double x0, const double y0, const double &a, const double &b, double &x1, double &y1) const
{
    x1 = x0 * x0 - y0 * y0 + a;
    y1 = 2 * x0 * y0 + b;
}
int MandelbrotSet::calculatePlaneEscapeCount(const double &x0, const double &y0) const
{
    int timeloops = 0;
    double EscapeeX = x0;
    double EscapeeY = y0;
    double radius = 2;
    // if()
    while (radius >= std::sqrt(std::pow(EscapeeY, 2) + std::pow(EscapeeX, 2)) && timeloops < NumberGrid::getMaxNumber())
    {
        calculateNextPoint(EscapeeX, EscapeeY, x0, y0, EscapeeX, EscapeeY);
        timeloops = timeloops + 1;
    }
    return timeloops;
}
int MandelbrotSet::calculateNumber(const int &row, const int &column) const
{
    if (row >= 0 && row < Hheight && column >= 0 && column < Wwidth)
    {
        int result;
        double x = 0;
        double y = 0;
        calculatePlaneCoordinatesFromPixelCoordinates(row, column, x, y);
        result = calculatePlaneEscapeCount(x, y);

        return result;
    }
    return -1;
}

MandelbrotPower ::MandelbrotPower()
    : MandelbrotSet()
{
    UnlimitedPower = 2.0;
}
MandelbrotPower ::~MandelbrotPower()
{
}
double MandelbrotPower ::getPower() const
{
    return UnlimitedPower;
}
void MandelbrotPower ::setPower(const double &power)
{
    UnlimitedPower = power;
}
void MandelbrotPower ::calculateNextPoint(const double x0, const double y0, const double &a, const double &b, double &x1, double &y1) const
{
    double r = sqrt(x0 * x0 + y0 * y0);
    double theta = std::atan2(y0, x0);
    x1 = (std::pow(r, UnlimitedPower)) * cos(UnlimitedPower * theta) + a;
    y1 = (std::pow(r, UnlimitedPower)) * sin(UnlimitedPower * theta) + b;
}
