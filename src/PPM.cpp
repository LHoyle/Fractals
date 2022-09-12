
#include "image_menu.h"
// Data! implementation of PPM.h
PPM::PPM()
{
    base = Image::Image();
    MCV = 1;
}
PPM::PPM(const int &height, const int &width)
{
    base = Image::Image(height, width);
    MCV = 1;
}
int getMaxColorValue() const
{
    return MCV;
}
bool valueValid(const int &value) const
{
    if (value >= 0 && value < MCV)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void setMaxColorValue(const int &max_color_value)
{
    if (value >= 0 && value < 255)
    {
        MCV = value;
    }
}
void setChannel(const int &row, const int &column, const int &channel, const int &value)
{
    if (valueValid(value))
    {
        Image::setChannel(row, column, channel);
    }
}
void setPixel(const int &row, const int &column, const int &red, const int &green, const int &blue)
{
    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
}

void writeStream(std::ostream &os) const
{
    os << "P6 WIDTH HEIGHT MAX_COLOR_VALUE" << std::endl;
    os << "BINARY REPRESENTATION OF COLORS FOR EACH PIXEL IN THE SAME ORDER AS THE COLOR FILE
          "<<std::endl;

}