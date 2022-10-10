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
                // std::cout<<channel;
                byte = channel;
                // std::cout<<byte;
                // os << byte<<(char *)&byte;
                os.write((char *)&byte, sizeof(byte));
                // os.write((char *)&byte, 1);
            }
        }
        // os<< "\n";
    }
    // os<< "\n";
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
void PPM::readStream(std::istream &is)
{
    std::string instring;
    int widthw;
    int heighth;
    int mcvc;
    std::string garbage;
    is >> garbage >> widthw >> heighth >> mcvc;
    unsigned char byte; // char is a one byte int. this stores from 0 to 255
    is.read((char *)&byte, 1);
    setWidth(widthw);
    setHeight(heighth);
    setMaxColorValue(mcvc);
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
                // std::cout << "("<<rows <<", of a max of" <<maxR<<")" << "("<<cols <<", of a max of" <<maxC<<")" << "("<<chan <<", of a max of" <<chan<<")"<<std::endl;
                is.read((char *)&byte, 1);
                setChannel(rows, cols, chan, byte);
            }
        }
    }
    return;
}

bool PPM::operator==(const PPM &rhs) const
{
    int size = getHeight() * getWidth();
    int rsize = rhs.getHeight() * rhs.getWidth();
    if (size == rsize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool PPM::operator!=(const PPM &rhs) const
{
    int size = getHeight() * getWidth();
    int rsize = rhs.getHeight() * rhs.getWidth();
    if (size != rsize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool PPM::operator<(const PPM &rhs) const
{
    int size = getHeight() * getWidth();
    int rsize = rhs.getHeight() * rhs.getWidth();
    if (size < rsize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool PPM::operator<=(const PPM &rhs) const
{
    int size = getHeight() * getWidth();
    int rsize = rhs.getHeight() * rhs.getWidth();
    if (size <= rsize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool PPM::operator>(const PPM &rhs) const
{
    int size = getHeight() * getWidth();
    int rsize = rhs.getHeight() * rhs.getWidth();
    if (size > rsize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool PPM::operator>=(const PPM &rhs) const
{
    int size = getHeight() * getWidth();
    int rsize = rhs.getHeight() * rhs.getWidth();
    if (size >= rsize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
PPM &PPM::operator+=(const PPM &rhs)
{
    int row = 0;
    int col = 0;
    int chan = 0;
    int op1 = 0;
    int op2 = 0;
    int com = 0;
    for (row = 0; row <= getHeight(); row++)
    {
        for (col = 0; col <= getWidth(); col++)
        {
            for (chan = 0; chan <= 2; chan++)
            {
                op1 = getChannel(row, col, chan);
                op2 = rhs.getChannel(row, col, chan);
                com = op1 + op2;
                if (com > getMaxColorValue())
                {
                    setChannel(row, col, chan, getMaxColorValue());
                }
                else
                {
                    setChannel(row, col, chan, com);
                }
            }
        }
    }
    return *this;
}
PPM &PPM::operator-=(const PPM &rhs)
{
    int row = 0;
    int col = 0;
    int chan = 0;
    int op1 = 0;
    int op2 = 0;
    int com = 0;
    for (row = 0; row <= getHeight(); row++)
    {
        for (col = 0; col <= getWidth(); col++)
        {
            for (chan = 0; chan <= 2; chan++)
            {
                op1 = getChannel(row, col, chan);
                op2 = rhs.getChannel(row, col, chan);
                com = op1 - op2;
                if (com < 0)
                {
                    setChannel(row, col, chan, 0);
                }
                else
                {
                    setChannel(row, col, chan, com);
                }
            }
        }
    }
    return *this;
}
PPM &PPM::operator*=(const double &rhs)
{
    int row = 0;
    int col = 0;
    int chan = 0;
    int op1 = 0;
    // int op2=0;
    int com = 0;
    for (row = 0; row <= getHeight(); row++)
    {
        for (col = 0; col <= getWidth(); col++)
        {
            for (chan = 0; chan <= 2; chan++)
            {
                op1 = getChannel(row, col, chan);

                com = op1 * rhs;
                if (com < 0)
                {
                    setChannel(row, col, chan, 0);
                }
                else if (com > getMaxColorValue())
                {
                    setChannel(row, col, chan, getMaxColorValue());
                }
                else
                {
                    setChannel(row, col, chan, com);
                }
            }
        }
    }
    return *this;
}
PPM &PPM::operator/=(const double &rhs)
{
    int row = 0;
    int col = 0;
    int chan = 0;
    int op1 = 0;
    // int op2=0;
    int com = 0;
    for (row = 0; row <= getHeight(); row++)
    {
        for (col = 0; col <= getWidth(); col++)
        {
            for (chan = 0; chan <= 2; chan++)
            {
                op1 = getChannel(row, col, chan);

                com = op1 / rhs;
                if (com < 0)
                {
                    setChannel(row, col, chan, 0);
                }
                else if (com > getMaxColorValue())
                {
                    setChannel(row, col, chan, getMaxColorValue());
                }
                else
                {
                    setChannel(row, col, chan, com);
                }
            }
        }
    }
    return *this;
}
PPM PPM::operator+(const PPM &rhs) const
{
    PPM newby = PPM(getHeight(), getWidth());
    newby.setMaxColorValue(getMaxColorValue());
    int row = 0;
    int col = 0;
    int chan = 0;
    int op1 = 0;
    int op2 = 0;
    int com = 0;
    for (row = 0; row < newby.getHeight(); row++)
    {
        for (col = 0; col < newby.getWidth(); col++)
        {
            for (chan = 0; chan <= 2; chan++)
            {
                op1 = getChannel(row, col, chan);
                op2 = rhs.getChannel(row, col, chan);
                com = op1 + op2;
                if (com > newby.getMaxColorValue())
                {
                    newby.setChannel(row, col, chan, newby.getMaxColorValue());
                }
                else
                {
                    newby.setChannel(row, col, chan, com);
                }
            }
        }
    }
    return newby;
}
PPM PPM::operator-(const PPM &rhs) const
{
    PPM newby = PPM(getHeight(), getWidth());
    newby.setMaxColorValue(getMaxColorValue());
    int row = 0;
    int col = 0;
    int chan = 0;
    int op1 = 0;
    int op2 = 0;
    int com = 0;
    for (row = 0; row < newby.getHeight(); row++)
    {
        for (col = 0; col < newby.getWidth(); col++)
        {
            for (chan = 0; chan <= 2; chan++)
            {
                op1 = getChannel(row, col, chan);
                op2 = rhs.getChannel(row, col, chan);
                com = op1 - op2;
                if (com < 0)
                {
                    newby.setChannel(row, col, chan, 0);
                }
                else
                {
                    newby.setChannel(row, col, chan, com);
                }
            }
        }
    }
    return newby;
}
PPM PPM::operator*(const double &rhs) const
{
    PPM newby = PPM(getHeight(), getWidth());
    newby.setMaxColorValue(getMaxColorValue());
    int row = 0;
    int col = 0;
    int chan = 0;
    int op1 = 0;
    // int op2=0;
    int com = 0;
    for (row = 0; row < newby.getHeight(); row++)
    {
        for (col = 0; col < newby.getWidth(); col++)
        {
            for (chan = 0; chan <= 2; chan++)
            {
                op1 = getChannel(row, col, chan);

                com = op1 * rhs;
                if (com < 0)
                {
                    newby.setChannel(row, col, chan, 0);
                }
                else if (com > newby.getMaxColorValue())
                {
                    newby.setChannel(row, col, chan, newby.getMaxColorValue());
                }
                else
                {
                    newby.setChannel(row, col, chan, com);
                }
            }
        }
    }
    return newby;
}
PPM PPM::operator/(const double &rhs) const
{
    PPM newby = PPM(getHeight(), getWidth());
    newby.setMaxColorValue(getMaxColorValue());
    int row = 0;
    int col = 0;
    int chan = 0;
    int op1 = 0;
    // int op2=0;
    int com = 0;
    for (row = 0; row < newby.getHeight(); row++)
    {
        for (col = 0; col < newby.getWidth(); col++)
        {
            for (chan = 0; chan <= 2; chan++)
            {
                op1 = getChannel(row, col, chan);
                com = op1 / rhs;
                if (com < 0)
                {
                    newby.setChannel(row, col, chan, 0);
                }
                else if (com > newby.getMaxColorValue())
                {
                    newby.setChannel(row, col, chan, newby.getMaxColorValue());
                }
                else
                {
                    newby.setChannel(row, col, chan, com);
                }
            }
        }
    }
    return newby;
}

void PPM::grayFromChannel(PPM &dst, const int &src_channel) const
{
    dst.setHeight(getHeight());
    dst.setWidth(getWidth());
    dst.setMaxColorValue(getMaxColorValue());
    for (int row = 0; row <= dst.getHeight(); row++)
    {
        for (int col = 0; col <= dst.getWidth(); col++)
        {
            int valued = getChannel(row, col, src_channel);
            dst.setPixel(row, col, valued, valued, valued);
        }
    }
}
void PPM::grayFromRed(PPM &dst) const
{
    grayFromChannel(dst, 0);
}
void PPM::grayFromGreen(PPM &dst) const
{

    grayFromChannel(dst, 1);
}
void PPM::grayFromBlue(PPM &dst) const
{

    grayFromChannel(dst, 2);
}
double PPM::linearColorimetricPixelValue(const int &row, const int &column) const
{
    double brightness;
    int red = getChannel(row, column, 0);
    int green = getChannel(row, column, 1);
    int blue = getChannel(row, column, 2);
    brightness = 0.2126 * red + 0.7152 * green + 0.0722 * blue;
    return brightness;
}
void PPM::grayFromLinearColorimetric(PPM &dst) const
{
    dst.setHeight(getHeight());
    dst.setWidth(getWidth());
    dst.setMaxColorValue(getMaxColorValue());
    double brightness;
    for (int row = 0; row <= dst.getHeight(); row++)
    {
        for (int col = 0; col <= dst.getWidth(); col++)
        {
            brightness = linearColorimetricPixelValue(row, col);
            dst.setPixel(row, col, brightness, brightness, brightness);
        }
    }
}
void PPM::orangeFilter(PPM &dst) const
{
    dst.setHeight(getHeight());
    dst.setWidth(getWidth());
    dst.setMaxColorValue(getMaxColorValue());

    for (int row = 0; row <= dst.getHeight(); row++)
    {
        for (int col = 0; col <= dst.getWidth(); col++)
        {
            int old_red = getChannel(row, col, 0);
            int old_green = getChannel(row, col, 1);
            int old_blue = getChannel(row, col, 2);
            int new_red = int(2 * (2 * old_red + old_green) / 3);
            if (new_red > dst.getMaxColorValue())
            {
                new_red = dst.getMaxColorValue();
            }
            int new_green = int(2 * (2 * old_red + old_green) / 6);
            if (new_green > dst.getMaxColorValue())
            {
                new_green = dst.getMaxColorValue();
            }
            int new_blue = int(old_blue / 2);
            if (new_blue > dst.getMaxColorValue())
            {
                new_blue = dst.getMaxColorValue();
            }
            dst.setPixel(row, col, new_red, new_green, new_blue);
        }
    }
}
