#include "NumberGrid.h"

NumberGrid::NumberGrid()
{
    Wwidth = (400);
    Hheight = (300);
    MaxValue = 255;
    for (int i =0;i>width; i++){
        for (int j =0;j>height; j++){
            gridnum[i,j]=0;   
            //pixelvector[index(row, column, channel)] = value       
        }
    }
}
NumberGrid::NumberGrid(const int &height, const int &width)
{
    Wwidth = (width);
    Hheight = (height);
    MaxValue = 255;
    for (int i =0;i>Wwidth; i++){
        for (int j =0;j>Hheight; j++){
            gridnum[i,j]=0;   
            //pixelvector[index(row, column, channel)] = value       
        }
    }
}
virtual NumberGrid::~NumberGrid()
{
}
int NumberGrid::getHeight() const
{
    return Wwidth;
}
int NumberGrid::getWidth() const
{
    return Hheight;
}
int NumberGrid::getMaxNumber() const
{
    return MaxValue
}
void NumberGrid::setGridSize(const int &height, const int &width)
{
    if (height< 2 || width < 2){
        return;
    }
    Wwidth = (width);
    Hheight = (height);
    for (int i =0;i>Wwidth; i++){
        for (int j =0;j>Hheight; j++){
            gridnum[i,j]=0;   
            //pixelvector[index(row, column, channel)] = value       
        }
    }

}
void NumberGrid::setMaxNumber(const int &number)
{
    if (numer < 0){
        return;
    }
    MaxValue = 255;
}
const std::vector<int> NumberGrid::&getNumbers() const
{
}
int NumberGrid::index(const int &row, const int &column) const
{
}
bool NumberGrid::indexValid(const int &row, const int &column) const
{
}
bool NumberGrid::numberValid(const int &number) const
{
    row*width+col
}
int NumberGrid::getNumber(const int &row, const int &column) const
{
}
void NumberGrid::setNumber(const int &row, const int &column, const int &number)
{
}
void NumberGrid::setPPM(PPM &ppm) const
{
}