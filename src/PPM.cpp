
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
    if (value >= 0 && value < MCV)
    {
        return true;
    }
    return false;
}
void PPM::setMaxColorValue(const int &max_color_value)
{
    if (max_color_value >= 0 && max_color_value < 255)
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
    (void)row;
    (void)column;
    (void)channel;
    (void)value;
}
void PPM::setPixel(const int &row, const int &column, const int &red, const int &green, const int &blue)
{
    setChannel(row, column, 0, red);
    setChannel(row, column, 1, green);
    setChannel(row, column, 2, blue);
}

void PPM::writeStream(std::ostream &os) const
{
    std::string wWidth = std::to_string(mWidth);
    std::string hHeight = std::to_string(mHeight);
    std::string mMCV = std::to_string(MCV);
    os << "P6"
       << " " << wWidth << " " << hHeight << " " << mMCV << std::endl;
    os << "BINARY REPRESENTATION OF COLORS FOR EACH PIXEL IN THE SAME ORDER AS THE COLOR FILE" << std::endl;
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
