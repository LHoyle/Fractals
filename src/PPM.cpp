#include <fstream>
#include "image_menu.h"
#include "PPM.h"
// Data! implementation of PPM.h
PPM::PPM() : Image()
{

    MCV = 1;
}
PPM::PPM(const int &height, const int &width) : Image()
{
    setHeight(height);
    setWidth(width);
    MCV = 1;
}
int PPM::getMaxColorValue() const
{
    return MCV;
}
bool PPM::valueValid(const int &value) const
{
    if (value >= 0 && value <= MCV)
    {
        return true;
    }
    return false;
}
void PPM::setMaxColorValue(const int &max_color_value)
{
    if (max_color_value > 0 && max_color_value <= 255)
    {
        MCV = max_color_value;
    }
}
void PPM::setChannel(const int &row, const int &column, const int &channel, const int &value)
{
    if (valueValid(value))
    {
        Image::setChannel(row, column, channel, value);
    }
    /*(void)row;
    (void)column;
    (void)channel;
    (void)value;*/
}
void PPM::setPixel(const int &row, const int &column, const int &red, const int &green, const int &blue)
{
    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
}

void PPM::writeStream(std::ostream &os) const
{
    os << "P6"
       << " " << getWidth() << " " << getHeight() << " " << getMaxColorValue() << "\n";
    // os << "BINARY REPRESENTATION OF COLORS FOR EACH PIXEL IN THE SAME ORDER AS THE COLOR FILE";
    // os << "BINARY REPRESENTATION OF COLORS FOR EACH PIXEL IN THE SAME ORDER AS THE COLOR FILE" << "\n";

    int rows; // an int is a 4 byte entity.
    int maxR = getHeight();
    int maxC = getWidth();
    int cols;
    int chan;
    for (rows = 0; rows < maxR; rows++)
    {
        for (cols = 0; cols < maxC; cols++)
        {
            for (chan = 0; chan < 3; chan++)
            {
                unsigned char byte; // char is a one byte int. this stores from 0 to 255
                int channel = getChannel(rows, cols, chan);
                //std::cout<<channel;
                byte = channel;
                //std::cout<<byte;
                //os << byte<<(char *)&byte;
                os.write((char *)&byte, sizeof(byte));
                //os.write((char *)&byte, 1);
            }
        }
        // os<< "\n";
    }
    //os<< "\n";
    /*int row;
    int col;
    int chan;
    for (row = 0, row < mHeight, row++)
    {
        for (col = 0, col < mWidth, col++)
        {
            for (chan = 0, chan < 3, chan++)
            {
                os.write()
            }
        }                                   
    }*/
}
void PPM::readStream(std::istream& is){
    
    is >> "P6"
       >> " " >> setWidth() >> " " >> setHeight() >> " " >> setMaxColorValue() >>"\n";
    int rows;
    int maxR = getHeight();
    int maxC = getWidth();
    int cols;
    int chan;
    for (rows = 0; rows < maxR; rows++)
    {
        for (cols = 0; cols < maxC; cols++)
        {
            for (chan = 0; chan < 3; chan++)
            {
                unsigned char byte; // char is a one byte int. this stores from 0 to 255
                int channel = setChannel(rows, cols, chan);
                byte = channel;

                is.read();
            }
        }
    }
}
