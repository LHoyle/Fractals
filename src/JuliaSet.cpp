#include "JuliaSet.h"
#include <cmath>

JuliaSet::JuliaSet()
    : ComplexFractal(), ParaA(-0.650492), ParaB(-0.478235)
{
    NumberGrid::setMaxNumber(255);
}
JuliaSet::JuliaSet(const int &height, const int &width, const double &min_x, const double &max_x, const double &min_y, const double &max_y, const double &a, const double &b)
    : ComplexFractal(height, width, min_x, max_x, min_y, max_y), ParaA(a), ParaB(b)
{
    NumberGrid::setMaxNumber(255);
}
JuliaSet::~JuliaSet() {}
double JuliaSet::getA() const
{
    return ParaA;
}
double JuliaSet::getB() const
{
    return ParaB;
}
void JuliaSet::setParameters(const double &a, const double &b)
{
    if (a <= 2.0 && b <= 2.0 && a >= -2.0 && b >= -2.0)
    {
        ParaA = a;
        ParaB = b;
    }
}
void JuliaSet::calculateNextPoint(const double x0, const double y0, double &x1, double &y1) const
{
    x1 = x0*x0 - y0*y0 + ParaA;
    y1 = 2*x0*y0 + ParaB;
}
int JuliaSet::calculatePlaneEscapeCount(const double &x0, const double &y0) const
{
    int timeloops;
    double EscapeeX = x0;
    double EscapeeY = y0;
    double radius = 2;
    //if (radius >= std::sqrt(std::pow(row - rowcent, 2) + std::pow(col - colcent, 2)))
            //{
              //  action_data.getInputImage1().setPixel(row, col, r, g, b);
            //} 

    /*if (x0 >2 || x0<-2 || y0 > 2 || y0 < -2 ){
        return 0;
    }*/
    calculateNextPoint(EscapeeX, EscapeeY, EscapeeX, EscapeeY);
    //double Repeatx =EscapeeX;
    //double Repeaty =EscapeeY;
    if (radius >std::sqrt(std::pow(EscapeeY - 0, 2) + std::pow(EscapeeX- 0, 2))){
        return 0;
    }
    for(timeloops=0;timeloops<=NumberGrid::getMaxNumber();timeloops++){
        calculateNextPoint(EscapeeX, EscapeeY, EscapeeX, EscapeeY);
        /*calculateNextPoint(Repeatx, Repeaty, EscapeeX, EscapeeY);
        Repeatx = EscapeeX;
        Repeaty = EscapeeY;*/
        if (radius >std::sqrt(std::pow(EscapeeY - 0, 2) + std::pow(EscapeeX - 0, 2))){
            return timeloops;
        }   
    }
    return NumberGrid::getMaxNumber();
    /*while (EscapeeX <= 2.0 && EscapeeX >= -2.0 && EscapeeY <= 2 && EscapeeY >= -2 && timeloops<=NumberGrid::getMaxNumber())
    {
        timeloops = timeloops + 1;
        calculateNextPoint(Repeatx, Repeaty, EscapeeX, EscapeeY);
        Repeatx = EscapeeX;
        Repeaty = EscapeeY;
    }*/
    return timeloops;
}
int JuliaSet::calculateNumber(const int &row, const int &column) const
{
    if (row >= 0 && row < Hheight && column >= 0 && column < Wwidth)
    {
        int result;
        result = calculatePlaneEscapeCount(row, column);
        if (result > NumberGrid::getMaxNumber()){
            result= NumberGrid::getMaxNumber();
        }
        return result;
    }
    return -1;
}