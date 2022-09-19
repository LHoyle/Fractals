#include "image_menu.h"

void writeUserImage(std::istream &is, std::ostream &os, const PPM &p)
{
    std::string prompt = "Output filename? ";
    std::string outname = getString(is, os, prompt);
    std::ofstream fout(outname);
    // std::vector<int> pixels = {0,255}; // p somehow you need to get the image byte by byte. which I don't quite know how to do.
    int rows; // an int is a 4 byte entity.
    int maxR = p.getHeight();
    int maxC = p.getWidth();
    int cols;
    int chan;
    // os << maxR;
    p.writeStream(os);
    for (rows = 0; rows < maxR; rows++)
    {
        for (cols = 0; cols < maxC; cols++)
        {
            for (chan = 0; chan < 3; chan++)
            {
                unsigned char byte; // char is a one byte int. this stores from 0 to 255
                int channel = p.getChannel(rows, cols, chan);
                byte = channel;
                //os << byte<<(char *)&byte;
                os.write((char *)&byte, 1);
            }
        }
    }
    fout << std::endl;
    fout.close();
}
/*//fout << p[i] << " ";
        unsigned char byte;           // char is a one byte int. this stores from 0 to 255
        byte = p[i];                     // this is saving the 4 bites to one, so only the least significant byte will be saved.
        fout.write((char *)&byte, 1);*/

void drawAsciiImage(std::istream &is, std::ostream &os, const Image &image)
{
    (void)is;
    int row;
    for (row = 0; row < image.getHeight(); row++)
    {
        int column;
        for (column = 0; column < image.getWidth(); column++)
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
