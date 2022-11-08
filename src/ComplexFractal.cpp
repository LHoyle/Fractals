#include "ComplexFractal.h"
#include <cmath>

ComplexFractal::ComplexFractal()
    : NumberGrid(200, 300), Minx(-1.5), MaxX(1.5), MinY(-1), MaxY(1), DeltX(0.01), DeltY(0.01)
{
}
ComplexFractal::ComplexFractal(const int &height, const int &width, const double &min_x, const double &max_x, const double &min_y, const double &max_y)
    : NumberGrid(height, width), Minx(min_x), MaxX(max_x), MinY(min_y), MaxY(max_y), DeltX(0.01), DeltY(0.01)
{
}
ComplexFractal::~ComplexFractal()
{
}
double ComplexFractal::getMinX() const
{
    return Minx;
}
double ComplexFractal::getMaxX() const
{
    return MaxX;
}
double ComplexFractal::getMinY() const
{
    return MinY;
}
double ComplexFractal::getMaxY() const
{
    return MaxY;
}
void ComplexFractal::setGridSize(const int &height, const int &width)
{
    if (height >= 2.0 && width >= 2.0)
    {
        NumberGrid::setGridSize(height, width);
        double deltx = calculateDeltaX();
        double delty = calculateDeltaY();
        setDeltas(deltx, delty);
    }
}
void ComplexFractal::setPlaneSize(const double &min_x, const double &max_x, const double &min_y, const double &max_y)
{
    if (min_x != max_x && min_y != max_y && min_x <= 2.0 && min_x >= -2.0 && min_y <= 2.0 && min_y >= -2.0 && max_x <= 2.0 && max_x >= -2.0 && max_y <= 2.0 && max_y >= -2.0)
    {
        // double change1 = 0.0;
        // double change2 = 0.0;
        if (min_x > max_x)
        {
            // change1 = max_x;
            // change2 = min_x;
            Minx = max_x;
            MaxX = min_x;
        }
        else
        {
            Minx = min_x;
            MaxX = max_x;
        }
        if (min_y > max_y)
        {
            MinY = max_y;
            MaxY = min_y;
        }
        else
        {
            MinY = min_y;
            MaxY = max_y;
        }
        double recalcx = calculateDeltaX();
        double recalcy = calculateDeltaY();
        setDeltas(recalcx, recalcy);
    }
}
double ComplexFractal::getDeltaX() const
{
    return DeltX;
}
double ComplexFractal::getDeltaY() const
{
    return DeltY;
}
void ComplexFractal::setDeltas(const double &delta_x, const double &delta_y)
{
    if (delta_x >= 0 && delta_y >= 0)
    {
        DeltX = delta_x;
        DeltY = delta_y;
    }
}
double ComplexFractal::calculateDeltaY() const
{
    double calcdelY;
    calcdelY = (MaxY - MinY) / (Hheight - 1);
    return calcdelY;
}
double ComplexFractal::calculateDeltaX() const
{
    double calcdelX;
    calcdelX = (MaxX - Minx) / (Wwidth - 1);
    return calcdelX;
}
double ComplexFractal::calculatePlaneXFromPixelColumn(const int &column) const
{
    if (column >= 0 && column < Wwidth)
    {
        double calcx;
        calcx = Minx + column * getDeltaX();
        return calcx;
    }
    return 0;
}
double ComplexFractal::calculatePlaneYFromPixelRow(const int &row) const
{
    if (row >= 0 && row < Hheight)
    {
        double calcY;
        calcY = MaxY - row * getDeltaY();
        return calcY;
    }
    return 0;
}
void ComplexFractal::calculatePlaneCoordinatesFromPixelCoordinates(const int &row, const int &column, double &x, double &y) const
{
    if (row >= 0 && row < Hheight && column >= 0 && column < Wwidth)
    {
        x = calculatePlaneXFromPixelColumn(column);
        y = calculatePlaneYFromPixelRow(row);
    }
    else
    {
        x = 0;
        y = 0;
    }
}
int ComplexFractal::calculateNumber(const int &row, const int &column) const
{
    double x=0;
    double y=0;
    if (NumberGrid::indexValid(row, column))
    {
        calculatePlaneCoordinatesFromPixelCoordinates(row,column,x,y);
        int CalcedNum = (std::abs(getMaxNumber() * std::sin(10 * x) * std::cos(10 * y)));
        return CalcedNum;
    }
    return -1;
}
