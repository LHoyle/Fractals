#include "image_menu.h"

void stripedDiagonalPattern(std::istream &is, std::ostream &os, PPM &p)
{
    std::string imagestringpromptone = "Image height? ";
    int height = getInteger(is, os, imagestringpromptone);

    std::string imagestringprompttwo = "Image width? ";
    int width = getInteger(is, os, imagestringprompttwo);
    p.setHeight(height);
    p.setWidth(width);

    int rowhalf = (p.getHeight() / 2);
    // os << p.getHeight();
    // os << p.getWidth();
    int r;
    int g;
    int b;

    int maxCV = (height + width) / 3;
    os<<height<<width<<maxCV<<std::endl;
    if (maxCV >= 255)
    {
        p.setMaxColorValue(255);
        //os << p.getMaxColorValue();
    }
    else
    {
        p.setMaxColorValue(maxCV);
        //os << p.getMaxColorValue();
    }
    int row;
    for (row = 0; row <= p.getHeight(); row++)
    {

        int column;
        for (column = 0; column <= p.getWidth(); column++)
        {
            /*int greensleevesp1(row + p.getWidth() - column - 1);
            int greensleevesp2(p.getMaxColorValue()+1);
            int greensleeves = greensleevesp1 % greensleevesp2;
            p.setChannel(row, column, 1, greensleeves);
            // g = (row + width - column - 1) % (p.getMaxColorValue() + 1);
            if (row < rowhalf)
            {
                p.setChannel(row, column, 0, 0);
            }
            else if (row % 3 == 0)
            {
                p.setChannel(row, column, 0, 0);
            }
            else
            {
                p.setChannel(row, column, 0, p.getMaxColorValue());
            }
            if (column < row)
            {
                p.setChannel(row, column, 2, 0);
            }
            else
            {
                p.setChannel(row, column, 2, p.getMaxColorValue());
            }*/

            int greensleevesp1(row + p.getWidth() - column - 1);
            int greensleevesp2(p.getMaxColorValue()+1);
            int greensleeves = greensleevesp1 % greensleevesp2;
            g = greensleeves;
            //os<<greensleevesp1<<greensleevesp2<<g<<std::endl;
            if (row < rowhalf)
            {
                r = 0;
            }
            else
            {
                if (row % 3 == 0)
                {
                    r = 0;
                }
                else
                {
                    r = p.getMaxColorValue();
                }
            }
            if (column < row)
            {
                b = 0;
            }
            else
            {
                b = p.getMaxColorValue();
            }
            p.setPixel(row, column, r, g, b);
            //os<<r<<std::endl<<g<<std::endl<<b<<std::endl;
        }
    }
}

void diagonalQuadPattern(std::istream &is, std::ostream &os, Image &image)
{
    std::string imagestringpromptone = "Image height? ";
    int height = getInteger(is, os, imagestringpromptone);

    std::string imagestringprompttwo = "Image width? ";
    int width = getInteger(is, os, imagestringprompttwo);
    image.setHeight(height);
    image.setWidth(width);

    int rowhalf = (image.getHeight() / 2);
    int colhalf = (image.getWidth() / 2);

    int row;
    for (row = 0; row < image.getHeight(); row++)
    {

        int column;
        for (column = 0; column < image.getWidth(); column++)
        {

            if (row < rowhalf && column < colhalf)
            {
                // top left
                image.setChannel(row, column, 0, 0);
                // int red =0;
                image.setChannel(row, column, 2, 0);
                // int blue =0;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
                // int = green ( 2*row + 2*column ) % 256;
            }
            else if (row >= rowhalf && column < colhalf)
            {
                // top right
                // int red = 0;
                image.setChannel(row, column, 0, 255);
                // int blue =255;
                image.setChannel(row, column, 2, 0);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
            else if (row < rowhalf && column >= colhalf)
            {
                // bottom left
                // int red = 255;
                image.setChannel(row, column, 0, 0);
                // int blue =0;
                image.setChannel(row, column, 2, 255);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
            else if (row >= rowhalf && column >= colhalf)
            {
                // bottom right
                // int red = 255;
                image.setChannel(row, column, 0, 255);
                // int blue =255;
                image.setChannel(row, column, 2, 255);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
        }
    }
}