#include "image_menu.h"

void copyImage(ActionData &action_data)
{
    action_data.getOutputImage() = action_data.getInputImage1();
}

void readUserImage1(ActionData &action_data)
{
    std::string InName = getString(action_data, "“Input filename? ");
    std::ifstream intowrite(InName, std::ifstream::binary);
    action_data.getInputImage1().readStream(intowrite);
}

void writeUserImage(ActionData &action_data)
{
    std::string prompt = "Output filename? ";
    std::string outname = getString(action_data, prompt);
    /// std::string fout=outname;
    // os<< fout;
    std::ofstream outout(outname, std::ifstream::binary);
    // std::vector<int> pixels = {0,255}; // p somehow you need to get the image byte by byte. which I don't quite know how to do.
    // os << maxR;
    action_data.getInputImage1().writeStream(outout);

    outout.close();
}
/*//fout << p[i] << " ";
        unsigned char byte;           // char is a one byte int. this stores from 0 to 255
        byte = p[i];                     // this is saving the 4 bites to one, so only the least significant byte will be saved.
        fout.write((char *)&byte, 1);*/

void drawAsciiImage(ActionData &action_data)
{
    (void)action_data;
    int row;
    for (row = 0; row < action_data.getInputImage1().getHeight(); row++)
    {
        int column;
        for (column = 0; column < action_data.getInputImage1().getWidth(); column++)
        {
            int pixel = action_data.getInputImage1().getChannel(row, column, 0) + action_data.getInputImage1().getChannel(row, column, 1) + action_data.getInputImage1().getChannel(row, column, 2);
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
            action_data.getOS() << displayvalue;
        }
        action_data.getOS() << std::endl;
    }
}
