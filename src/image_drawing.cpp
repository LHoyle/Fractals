#include "image_menu.h"

void stripedDiagonalPattern( std::istream& is, std::ostream& os, PPM& p ){
    std::string imagestringpromptone = "Image height? "  ;
    int height = getInteger(is, os, imagestringpromptone);

    std::string imagestringprompttwo = "Image width? ";
    int width = getInteger(is, os, imagestringprompttwo);
}






void diagonalQuadPattern(std::istream &is, std::ostream &os, Image &image)
{
    std::string imagestringpromptone = "Image height? "  ;
    int height = getInteger(is, os, imagestringpromptone);

    std::string imagestringprompttwo = "Image width? ";
    int width = getInteger(is, os, imagestringprompttwo);
    image.setHeight(height);
    image.setWidth(width);
    int rowhalf = (image.getHeight() / 2);
    int colhalf = (image.getWidth() / 2);

    int row = 0;
    for (row; row < image.getHeight(); row++)
    {
        int column = 0;
        for (column; column < image.getWidth(); column++)
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
                image.setChannel(row, column, 0, 0);
                // int blue =255;
                image.setChannel(row, column, 2, 255);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
            else if (row < rowhalf && column >= colhalf)
            {
                // bottom left
                // int red = 255;
                image.setChannel(row, column, 0, 255);
                // int blue =0;
                image.setChannel(row, column, 2, 0);
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