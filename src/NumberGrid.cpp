#include "NumberGrid.h"

NumberGrid::NumberGrid()
    : Wwidth(400), Hheight(300), MaxValue(255)
{
    gridnum.assign((Wwidth * Hheight), 0);
    gridnum.resize(Wwidth * Hheight);
    gridnum.assign((Wwidth * Hheight), 0);
    // pixelvector[index(row, column, channel)] = value
}
NumberGrid::NumberGrid(const int &height, const int &width)
    : Wwidth(width), Hheight(height), MaxValue(255)
{
    gridnum.assign((Wwidth * Hheight), 0);
    gridnum.resize(Wwidth * Hheight);
    gridnum.assign((Wwidth * Hheight), 0);
}
NumberGrid::~NumberGrid()
{
}
int NumberGrid::getHeight() const
{
    return Hheight;
}
int NumberGrid::getWidth() const
{
    return Wwidth;
}
int NumberGrid::getMaxNumber() const
{
    return MaxValue;
}
void NumberGrid::setGridSize(const int &height, const int &width)
{
    if (height < 2 || width < 2)
    {
        return;
    }
    Wwidth = (width);
    Hheight = (height);
    gridnum.resize(width * height);
    for (int i = 0; i > Wwidth; i++)
    {
        for (int j = 0; j > Hheight; j++)
        {
            setNumber(i, j, 0);
            // pixelvector[index(row, column, channel)] = value
        }
    }
}
void NumberGrid::setMaxNumber(const int &number)
{
    int GridVal;
    if (number < 0)
    {
        return;
    }
    else
    {
        MaxValue = number;
    }
    for (int i = 0; i <= getHeight(); i++)
    {
        for (int j = 0; j <= getWidth(); j++)
        {
            GridVal = getNumber(i, j);
            if (GridVal > MaxValue)
            {
                gridnum[index(i, j)] = MaxValue;
            }
        }
    }
}
const std::vector<int> &NumberGrid::getNumbers() const
{
    return gridnum;
}
int NumberGrid::index(const int &row, const int &column) const
{
    int result = (row * Wwidth) + column;
    return result;
}
bool NumberGrid::indexValid(const int &row, const int &column) const
{
    if (row < Hheight && row >= 0)
    {
        if (column < Wwidth && column >= 0)
        {
            return true;
        }
    }
    return false;
}
bool NumberGrid::numberValid(const int &number) const
{
    if (number >= 0 && number <= MaxValue)
    {
        return true;
    }
    return false;
}
int NumberGrid::getNumber(const int &row, const int &column) const
{
    if (indexValid(row, column))
    {
        return gridnum[index(row, column)];
    }
    else
    {
        return -1;
    }
}
void NumberGrid::setNumber(const int &row, const int &column, const int &number)
{
    if (numberValid(number) && indexValid(row, column))
    {
        gridnum[index(row, column)] = number;
    }
}
void NumberGrid::setPPM(PPM &ppm, const ColorTable &colors) const
{
    if (colors.getNumberOfColors() < 2)
    {
        return;
    }
    ppm.setMaxColorValue(colors.getMaxChannelValue());
    ppm.setWidth(Wwidth);
    ppm.setHeight(Hheight);
    int GridVal = 0;
    for (int i = 0; i <= ppm.getHeight(); i++)
    {
        for (int j = 0; j <= ppm.getWidth(); j++)
        {
            GridVal = getNumber(i, j);
            if (GridVal == MaxValue)
            {
                ppm.setPixel(i, j, colors[colors.getNumberOfColors() - 1].getRed(), colors[colors.getNumberOfColors() - 1].getGreen(), colors[colors.getNumberOfColors() - 1].getBlue());
            }
            else
            {
                int GridIndex = GridVal % colors.getNumberOfColors();
                ppm.setPixel(i, j, colors[GridIndex].getRed(), colors[GridIndex].getGreen(), colors[GridIndex].getBlue());
                /*'''if (GridVal == 0)
                {
                    ppm.setPixel(i, j, 0, 0, 0);
                }
                else
                {
                    '''


                        '''if (GridVal % 8 == 0)
                    {
                        ppm.setPixel(i, j, 63, 63, 63);
                    }
                    if (GridVal % 8 == 1)
                    {
                        ppm.setPixel(i, j, 63, 31, 31);
                    }
                    if (GridVal % 8 == 2)
                    {
                        ppm.setPixel(i, j, 63, 63, 31);
                    }
                    if (GridVal % 8 == 3)
                    {
                        ppm.setPixel(i, j, 31, 63, 31);
                    }
                    if (GridVal % 8 == 4)
                    {
                        ppm.setPixel(i, j, 0, 0, 0);
                    }
                    if (GridVal % 8 == 5)
                    {
                        ppm.setPixel(i, j, 31, 63, 63);
                    }
                    if (GridVal % 8 == 6)
                    {
                        ppm.setPixel(i, j, 31, 31, 63);
                    }
                    if (GridVal % 8 == 7)
                    {
                        ppm.setPixel(i, j, 63, 31, 63);
                    }
                }
                '''*/
            }
        }
    }
}

void NumberGrid::calculateAllNumbers()
{
    for (int row = 0; row < Hheight; row++)
    {
        for (int col = 0; col < Wwidth; col++)
        {
            int result = calculateNumber(row, col);
            setNumber(row, col, result);
        }
    }
}

void NumberGrid::setPPM(PPM &ppm) const
{
    ppm.setMaxColorValue(63);
    ppm.setWidth(Wwidth);
    ppm.setHeight(Hheight);
    int GridVal = 0;
    for (int i = 0; i <= ppm.getHeight(); i++)
    {
        for (int j = 0; j <= ppm.getWidth(); j++)
        {
            GridVal = getNumber(i, j);
            if (GridVal == MaxValue)
            {
                ppm.setPixel(i, j, 63, 31, 31);
            }
            else
            {
                if (GridVal == 0)
                {
                    ppm.setPixel(i, j, 0, 0, 0);
                }
                else
                {
                    if (GridVal % 8 == 0)
                    {
                        ppm.setPixel(i, j, 63, 63, 63);
                    }
                    if (GridVal % 8 == 1)
                    {
                        ppm.setPixel(i, j, 63, 31, 31);
                    }
                    if (GridVal % 8 == 2)
                    {
                        ppm.setPixel(i, j, 63, 63, 31);
                    }
                    if (GridVal % 8 == 3)
                    {
                        ppm.setPixel(i, j, 31, 63, 31);
                    }
                    if (GridVal % 8 == 4)
                    {
                        ppm.setPixel(i, j, 0, 0, 0);
                    }
                    if (GridVal % 8 == 5)
                    {
                        ppm.setPixel(i, j, 31, 63, 63);
                    }
                    if (GridVal % 8 == 6)
                    {
                        ppm.setPixel(i, j, 31, 31, 63);
                    }
                    if (GridVal % 8 == 7)
                    {
                        ppm.setPixel(i, j, 63, 31, 63);
                    }
                }
            }
        }
    }
}
