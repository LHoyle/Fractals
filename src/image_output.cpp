#include "image_menu.h"

void drawAsciiImage(std::istream &is, std::ostream &os, const Image &image)
{
    int row = 0;
    for (row, row < image.mHeight; row++)
    {
        int column = 0;
        for (column, column < image.mWidth; column++)
        {
            int channel = 0;
            for (channel, channel < 2, channel++)
            {
                int pixel = image.getChannel(row, column, channel) double pixelvalue = pixel / 765.0;
                if (pixelvalue >= 1.0)
                {
                    char displayvalue = '@'
                }
                if (pixelvalue >= 0.9)
                {
                    char displayvalue = '#'
                }
                if (pixelvalue >= 0.8)
                {
                    char displayvalue = '%'
                }
                if (pixelvalue >= 0.7)
                {
                    char displayvalue = '*'
                }
                if (pixelvalue >= 0.6)
                {
                    char displayvalue = '|'
                }
                if (pixelvalue >= 0.5)
                {
                    char displayvalue = '+'
                }
                if (pixelvalue >= 0.4)
                {
                    char displayvalue = ';'
                }
                if (pixelvalue >= 0.3)
                {
                    char displayvalue = '~'
                }
                if (pixelvalue >= 0.2)
                {
                    char displayvalue = '-'
                }
                if (pixelvalue >= 0.1)
                {
                    char displayvalue = '.'
                }
                if (pixelvalue >= 0.0)
                {
                    char displayvalue = ' '
                }
                os << displayvalue
            }
        }
        os << std::endl;
    }
}
