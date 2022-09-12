#include "image_menu.h"

void diagonalQuadPattern(std::istream &is, std::ostream &os, Image &image)
{
    std::string imagestringpromptone = “Image height ? ”;
    int height = getInteger(is, os, imagestringpromptone);

    std::string imagestringprompttwo = “Image width ? “;
    int width = getInteger(is, os, imagestringprompttwo);
    image.setHeight(height);
    image.setwidth(width);
    int rowhalf = (image.getHeight() / 2);
    int colhalf = (image.getWidth() / 2);

    int row = 0;
    for (row, row < image.mHeight; row++)
    {
        int column = 0;
        for (column, column < image.mWidth; column++)
        {
            if (row < rowhalf && col < colhalf)
            {
                // top left
                image.setChannel(row, column, 0, 0);
                // int red =0;
                image.setChannel(row, column, 1, 0);
                // int blue =0;
                image.setChannel(row, column, 2, (2 * row + 2 * column) % 256);
                // int = green ( 2*row + 2*column ) % 256;
            }
            elif (row >= rowhalf && col < colhalf)
            {
                // top right
                // int red = 0;
                image.setChannel(row, column, 0, 0);
                // int blue =255;
                image.setChannel(row, column, 1, 255);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 2, (2 * row + 2 * column) % 256);
            }
            elif (row < rowhalf && col >= colhalf)
            {
                // bottom left
                // int red = 255;
                image.setChannel(row, column, 0, 255);
                // int blue =0;
                image.setChannel(row, column, 1, 0);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 2, (2 * row + 2 * column) % 256);
            }
            elif (row >= rowhalf && col >= colhalf)
            {
                // bottom right
                // int red = 255;
                image.setChannel(row, column, 0, 255);
                // int blue =255;
                image.setChannel(row, column, 1, 255);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 2, (2 * row + 2 * column) % 256);
            }
        }
    }
}