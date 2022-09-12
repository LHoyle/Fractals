#include "image_menu.h"

void writeUserImage( std::istream& is, std::ostream& os, const PPM& p ){
    std::string prompt = "Output filename? ";
    std::string outname = getString(is,os,prompt);
    std::ofstream fout(outname);
    std::vector<std::string> words = {"the","quick","brown","fox"};
    int i; //an int is a 4 byte entity. 
    for ( i = 0; i < 256; i++)
    { fout <<words[i]<< " ";
    }
}

void drawAsciiImage(std::istream &is, std::ostream &os, const Image &image)
{
    int row = 0;
    for (row; row < image.getHeight(); row++)
    {
        int column = 0;
        for (column; column < image.getWidth(); column++)
        {
            int pixel = image.getChannel(row, column, 0) + image.getChannel(row, column, 1) + image.getChannel(row, column, 2);
            double pixelvalue = pixel / 765.0;
            char displayvalue;
            if (pixelvalue >= 1.0)
            {
                displayvalue = '@';
            }
            else if (pixelvalue >= 0.9)
            {
                displayvalue = '#';
            }
            else if (pixelvalue >= 0.8)
            {
                displayvalue = '%';
            }
            else if (pixelvalue >= 0.7)
            {
                displayvalue = '*';
            }
            else if (pixelvalue >= 0.6)
            {
                displayvalue = '|';
            }
            else if (pixelvalue >= 0.5)
            {
                displayvalue = '+';
            }
            else if (pixelvalue >= 0.4)
            {
                displayvalue = ';';
            }
            else if (pixelvalue >= 0.3)
            {
                displayvalue = '~';
            }
            else if (pixelvalue >= 0.2)
            {
                displayvalue = '-';
            }
            else if (pixelvalue >= 0.1)
            {
                displayvalue = '.';
            }
            else
            {
                displayvalue = ' ';
            }
            os << displayvalue;
        }
        os << std::endl;
    }
}

