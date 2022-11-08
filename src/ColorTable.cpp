#include "ColorTable.h"

Color::Color()
{
    Rred = 0;
    Ggreen = 0;
    Bblue = 0;
}
Color::Color(const int &red, const int &green, const int &blue)
{
    Rred = red;
    Ggreen = green;
    Bblue = blue;
}
int Color::getRed() const
{
    return Rred;
}
int Color::getGreen() const
{
    return Ggreen;
}
int Color::getBlue() const
{
    return Bblue;
}
int Color::getChannel(const int &channel) const
{
    if (channel == 0)
    {
        return Rred;
    }
    if (channel == 1)
    {
        return Ggreen;
    }
    if (channel == 2)
    {
        return Bblue;
    }
    return -1;
}
void Color::setRed(const int &value)
{
    if (value >= 0)
    {
        Rred = value;
    }
}
void Color::setGreen(const int &value)
{
    if (value >= 0)
    {
        Ggreen = value;
    }
}
void Color::setBlue(const int &value)
{
    if (value >= 0)
    {
        Bblue = value;
    }
}
void Color::setChannel(const int &channel, const int &value)
{
    if (value >= 0)
    {
        if (channel == 0)
        {
            Rred = value;
        }
        if (channel == 1)
        {
            Ggreen = value;
        }
        if (channel == 2)
        {
            Bblue = value;
        }
    }
}
void Color::invert(const int &max_color_value)
{
    if (Rred <= max_color_value && Ggreen <= max_color_value && Bblue <= max_color_value)
    {
        Rred = max_color_value - Rred;
        Ggreen = max_color_value - Ggreen;
        Bblue = max_color_value - Bblue;
    }
}
bool Color::operator==(const Color &rhs) const
{
    if (Rred == rhs.getRed() && Ggreen == rhs.getGreen() && Bblue == rhs.getBlue())
    {
        return true;
    }
    return false;
}
std::ostream &operator<<(std::ostream &os, const Color &color)
{
    os << color.getRed() << ':' << color.getGreen() << ':' << color.getBlue();
    return os;
}

//
//
//
//
//
// color table attributes
//
//
//
//
//

ColorTable::ColorTable(const int &num_color)
{
    Colors.resize(num_color);
}
int ColorTable::getNumberOfColors() const
{
    return Colors.size();
}
void ColorTable::setNumberOfColors(const int &num_color)
{
    Colors.resize(num_color);
}
const Color &ColorTable::operator[](const int &i) const
{
    if (i < (int)Colors.size() && i >= 0)
    {
        return Colors[i];
    }
    else
    {
        static Color ec(-1, -1, -1);
        static Color c(-1, -1, -1);
        c = ec;
        return c;
    }
}
Color &ColorTable::operator[](const int &i)
{
    if (i < (int)Colors.size() && i >= 0)
    {
        return Colors[i];
    }
    else
    {
        static Color ec(-1, -1, -1);
        static Color c(-1, -1, -1);
        c = ec;
        return c;
    }
}
void ColorTable::setRandomColor(const int &max_color_value, const int &position)
{
    if (position < (int)Colors.size() && position >= 0 && max_color_value >= 0)
    {
        int r = (std::rand() % (max_color_value + 1));
        int g = (std::rand() % (max_color_value + 1));
        int b = (std::rand() % (max_color_value + 1));
        Color Rando = Color(r, g, b);
        Colors[position] = Rando;
    }
}
double ColorTable::gradientSlope(const double y1, const double y2, const double x1, const double x2) const
{
    double slope = ((y2 - y1) / (x2 - x1));
    return slope;
}
double ColorTable::gradientValue(const double y1, const double x1, const double slope, const double x) const
{
    // m=(y-y1)/(x-x1)
    // changing that to get y we get...
    // m*(x-x1)=(y-y1) -> (m*(x-x1))+y1)=y
    /*So y1 is your color1 channel value.
     x1 is your position.
     Slope is what it says.
      X is your index of your color table vector. */
    double change = x - x1;
    double y2 = y1 + (slope * (change));

    return y2;
    /*double ymax = y1;
     for (int i = 0; i > change; i++)
    {
        ymax = ymax + slope;
    }
    double ymin1 = ymax - slope;
    double step = (ymax - y1) / (ymin1);
    double new_i;
    for (int i = x1; i >= x; i++)
    {
        new_i = y1 + i * step;
    }
    return new_i;*/
    // red_i = Colors[i].getRed() + i * step;
    // Colors[i].setRed(ymove)
}
void ColorTable::insertGradient(const Color &color1, const Color &color2, const int &position1, const int &position2)
{
    // insert gradient relies upon the other two. the equasions from the calculating gradient colors should be used within the other 2, how is not quite yet apparent.

    if (position2 > position1 && position1 >= 0 && position2 < (int)Colors.size())
    {

        double Redstep = gradientSlope(color1.getRed(), color2.getRed(), position1, position2);
        double Greenstep = gradientSlope(color1.getGreen(), color2.getGreen(), position1, position2);
        double Bluestep = gradientSlope(color1.getBlue(), color2.getBlue(), position1, position2);
        /*gradientValue(color1.getRed(), position1, Redstep, position2); gradientValue(color1.getGreen(), position1, Greenstep, position2); gradientValue(color1.getBlue(), position1, Bluestep, position2);*/
        for (int i = position1; i <= position2; i++)
        {
            Colors[i].setRed(gradientValue(color1.getRed(), position1, Redstep, i));
            Colors[i].setGreen(gradientValue(color1.getGreen(), position1, Greenstep, i));
            Colors[i].setBlue(gradientValue(color1.getBlue(), position1, Bluestep, i));
        }
        /*    int i = position1;
        int nm1 = position2 - 1;
        double step = ((double)color2.getRed() - color1.getRed()) / ((double)color2.getRed());
        for (i = x1; i > position2; i++)
        {
            red_i = color1.getRed() + i * step;
        }

        i = position1;
        double step = ((double)color2.getGreen() - color1.getGreen()) / ((double)color2.getGreen());
        for (i = x1; i > position2; i++)
        {
            green_i = color1.getGreen() + i * step;
        }

        i = position1;
        double step = ((double)color2.getBlue() - color1.getBlue()) / ((double)color2.getBlue());
        for (i = x1; i > position2; i++)
        {
            blue_i = color1.getBlue() + i * step;
        }*/
    }
}
int ColorTable::getMaxChannelValue() const
{
    int max = -1; 
    for (int i =0; i<(int)Colors.size();i++){
        if (Colors[i].getChannel(0) > max){
            max=Colors[i].getChannel(0);
        }
        if (Colors[i].getChannel(1) > max){
            max=Colors[i].getChannel(1);
        }
        if (Colors[i].getChannel(2) > max){
            max=Colors[i].getChannel(2);
        }
    }
    return max;
    /*int maxred = Colors[0].getRed();
    int maxgreen = Colors[0].getGreen();
    int maxblue = Colors[0].getBlue();

    for (int i = 0; i <= (int)Colors.size(); i++)
    {
        if (Colors[i].getRed() >= maxred)
        {
            maxred = Colors[i].getRed();
        }
        if (Colors[i].getGreen() >= maxgreen)
        {
            maxgreen = Colors[i].getGreen();
        }
        if (Colors[i].getBlue() >= maxblue)
        {
            maxblue = Colors[i].getBlue();
        }
    }
    if (maxred > maxgreen && maxred > maxblue)
    {
        return maxred;
    }
    else
    {
        if (maxgreen > maxblue)
        {
            return maxgreen;
        }
        else
        {
            return maxblue;
        }
    }*/
}
