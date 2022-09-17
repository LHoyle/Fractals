#include "image_menu.h"

void stripedDiagonalPattern(std::istream &is, std::ostream &os, PPM &p)
{
    std::string imagestringpromptone = "Image height? ";
    int height =getInteger(is, os, imagestringpromptone);

    std::string imagestringprompttwo = "Image width? ";
    int width = getInteger(is, os, imagestringprompttwo);
    p = PPM(height, width);

    int rowhalf = (p.getHeight() / 2);
    os << p.getHeight();
    int colhalf = (p.getWidth() / 2);
    os << p.getWidth();

    int maxCV = height * width;
    if (maxCV > 255)
    {
        maxCV = 255;
    }
    int row;
    for (row = 0; row < p.getHeight(); row++)
    {

        int column;
        for (column = 0; column < p.getWidth(); column++)
        {

            if (row < rowhalf && column < colhalf)
            {
                /* // top left
                 p.setChannel(row, column, 0, 0);
                 // int red =0;
                 if (column < row){
                     p.setChannel(row, column, 2, 0);
                 }
                 else{
                     p.setChannel(row, column, 2, 255);
                 }
                 // int blue =0;
                 p.setChannel(row, column, 1, (row + width - column - 1) % (p.getMaxColorValue()+1));
                 // int = green ( 2*row + 2*column ) % 256;*/
                if (column < row)
                {
                    p.setPixel(row, column, 0, 0, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                }
                else
                {
                    p.setPixel(row, column, 0, 255, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                }
            }
            else if (row >= rowhalf && column < colhalf)
            {
                /*// top right
                // int red = 0;
                p.setChannel(row, column, 0, 0);
                // int blue =255;
                if (column < row){
                    p.setChannel(row, column, 2, 0);
                }
                else{
                    p.setChannel(row, column, 2, 255);
                }
                // int = green ( 2*row + 2*column ) % 256;
                p.setChannel(row, column, 1, (row + width - column - 1) % (p.getMaxColorValue()+1));
                */
                if (column < row)
                {
                    p.setPixel(row, column, 0, 0, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                }
                else
                {
                    p.setPixel(row, column, 0, 255, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                }
            }
            else if (row < rowhalf && column >= colhalf)
            {

                /*// bottom left
                // int red = 255;
                if (row / 3  == 0){
                    p.setChannel(row, column, 0, 0);
                }
                else{
                    p.setChannel(row, column, 0, 255);
                }
                // int blue =0;
                if (column < row){
                    p.setChannel(row, column, 2, 0);
                }
                else{
                    p.setChannel(row, column, 2, 255);
                }

                // int = green ( 2*row + 2*column ) % 256;
                p.setChannel(row, column, 1, (row + width - column - 1) % (p.getMaxColorValue()+1));*/
                if (row / 3 == 0)
                {
                    if (column < row)
                    {
                        p.setPixel(row, column, 255, 0, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                    }
                    else
                    {
                        p.setPixel(row, column, 255, 255, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                    }
                }
                else
                {
                    if (column < row)
                    {
                        p.setPixel(row, column, 0, 0, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                    }
                    else
                    {
                        p.setPixel(row, column, 0, 255, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                    }
                }
            }
            else if (row >= rowhalf && column >= colhalf)
            {
                /*// bottom right
                // int red = 255;
                if (row/3 ==0 ){
                    p.setChannel(row, column, 0, 0);
                }
                else{
                    p.setChannel(row, column, 0, 255);
                }
                // int blue =255;
                if (column < row){
                    p.setChannel(row, column, 2, 0);
                }
                else{
                    p.setChannel(row, column, 2, 255);
                }
                // int = green ( 2*row + 2*column ) % 256;
                p.setChannel(row, column, 1, (row + width - column - 1) % (p.getMaxColorValue()+1));*/
                if (row / 3 == 0)
                {
                    if (column < row)
                    {
                        p.setPixel(row, column, 255, 0, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                    }
                    else
                    {
                        p.setPixel(row, column, 255, 255, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                    }
                }
                else
                {
                    if (column < row)
                    {
                        p.setPixel(row, column, 0, 0, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                    }
                    else
                    {
                        p.setPixel(row, column, 0, 255, (row + width - column - 1) % (p.getMaxColorValue() + 1));
                    }
                }
            }
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
                image.setChannel(row, column, 2, 255);
                // int blue =0;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
                // int = green ( 2*row + 2*column ) % 256;
            }
            else if (row >= rowhalf && column < colhalf)
            {
                // top right
                // int red = 0;
                image.setChannel(row, column, 0, 0);
                // int blue =255;
                image.setChannel(row, column, 2, 0);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
            else if (row < rowhalf && column >= colhalf)
            {
                // bottom left
                // int red = 255;
                image.setChannel(row, column, 0, 255);
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
                image.setChannel(row, column, 2, 0);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
        }
    }
}