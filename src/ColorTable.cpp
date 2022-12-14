#include "ColorTable.h"
#include <cmath>

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
    for (int i = 0; i < (int)Colors.size(); i++)
    {
        if (Colors[i].getChannel(0) > max)
        {
            max = Colors[i].getChannel(0);
        }
        if (Colors[i].getChannel(1) > max)
        {
            max = Colors[i].getChannel(1);
        }
        if (Colors[i].getChannel(2) > max)
        {
            max = Colors[i].getChannel(2);
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

//
//
// final
//
//

void Color::setFromHSV(const double &hue, const double &saturation, const double &value)
{
    double red = Rred * 1.0;
    double green = Ggreen * 1.0;
    double blue = Bblue * 1.0;
    HSV_to_RGB(hue, saturation, value,red, green, blue);
    Rred=red;
    Ggreen=green;
    Bblue=blue;
}
void Color::getHSV(double &hue, double &saturation, double &value) const
{
    RGB_to_HSV(Rred, Ggreen, Bblue, hue, saturation, value);
    //setFromHSV(hue, saturation, value);
}

//////////////////////////////////////////////////////////////////////////
///
void HSV_to_RGB(const double &hue, const double &saturation, const double &value, double &red, double &green, double &blue)
{
    /* Convert Hue, Saturation, Value to Red, Green, Blue
     * Implementation of algorithm from:
     * https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
     *
     * Inputs and ranges:
     * 0.0 <= hue <= 360.0
     * 0.0 <= saturation <= 1.0
     * 0.0 <= value <= 1.0
     *
     * Outputs and ranges:
     * 0.0 <= red <= 255.0
     * 0.0 <= green <= 255.0
     * 0.0 <= blue <= 255.0
     */
    if (hue < 0.0 || hue > 360.0 || saturation < 0.0 || saturation > 1.0 || value < 0.0 || value > 1.0)
    {
        red = green = blue = 0.0;
        std::cerr << "HSV_to_RGB() input parameters out of range." << std::endl
                  << " hue: " << hue << std::endl
                  << " saturation: " << saturation << std::endl
                  << " value: " << value << std::endl;
        return;
    }

    // chroma selects the strength of the "primary" color of the current area of the wheel
    double chroma = value * saturation;
    // hue2 selects which 60-degree wedge of the color wheel we are in
    double hue2 = hue / 60.0;
    // x selects the strength of the "secondary" color of the current area of the wheel
    double x = chroma * (1 - std::abs(std::fmod(hue2, 2) - 1));
    if (hue2 >= 0 && hue2 < 1)
    {
        red = chroma;
        green = x;
        blue = 0.0;
    }
    else if (hue2 >= 1 && hue2 < 2)
    {
        red = x;
        green = chroma;
        blue = 0.0;
    }
    else if (hue2 >= 2 && hue2 < 3)
    {
        red = 0.0;
        green = chroma;
        blue = x;
    }
    else if (hue2 >= 3 && hue2 < 4)
    {
        red = 0.0;
        green = x;
        blue = chroma;
    }
    else if (hue2 >= 4 && hue2 < 5)
    {
        red = x;
        green = 0.0;
        blue = chroma;
    }
    else if (hue2 >= 5 && hue2 <= 6)
    {
        red = chroma;
        green = 0.0;
        blue = x;
    }
    else
    {
        red = 0;
        green = 0;
        blue = 0;
    }

    // m scales all color channels to obtain the overall brightness.
    double m = value - chroma;
    red = 255.0 * (red + m);
    green = 255.0 * (green + m);
    blue = 255.0 * (blue + m);
}

void RGB_to_HSV(const double &red0, const double &green0, const double &blue0, double &hue, double &saturation, double &value)
{
    /* Red, Green, Blue to Convert Hue, Saturation, Value
     * Implementation of algorithm from:
     * https://en.wikipedia.org/wiki/HSL_and_HSV#From_RGB
     *
     * Inputs and ranges:
     * 0.0 <= red <= 255.0
     * 0.0 <= green <= 255.0
     * 0.0 <= blue <= 255.0
     *
     * Outputs and ranges:
     * 0.0 <= hue <= 360.0
     * 0.0 <= saturation <= 1.0
     * 0.0 <= value <= 1.0
     */
    if (red0 < 0.0 || red0 > 255.0 || green0 < 0.0 || green0 > 255.0 || blue0 < 0.0 || blue0 > 255.0)
    {
        hue = saturation = value = 0.0;
        std::cerr << "RGB_to_HSV() input parameters out of range." << std::endl
                  << " red: " << red0 << std::endl
                  << " green: " << green0 << std::endl
                  << " blue: " << blue0 << std::endl;
        return;
    }

    double red = red0 / 255.0;
    double green = green0 / 255.0;
    double blue = blue0 / 255.0;

    // x_max helps identify the primary hue
    double x_max = red;
    if (green > x_max)
    {
        x_max = green;
    }
    if (blue > x_max)
    {
        x_max = blue;
    }
    value = x_max;

    double x_min = red;
    if (green < x_min)
    {
        x_min = green;
    }
    if (blue < x_min)
    {
        x_min = blue;
    }

    double chroma = x_max - x_min;

    if (chroma == 0)
    {
        hue = 0;
    }
    else if (value == red)
    {
        hue = 60.0 * (0 + (green - blue) / chroma);
    }
    else if (value == green)
    {
        hue = 60.0 * (2 + (blue - red) / chroma);
    }
    else if (value == blue)
    {
        hue = 60.0 * (4 + (red - green) / chroma);
    }
    else
    {
        hue = -720.0;
    }
    if (hue < 0.0)
    {
        hue += 360.0;
    }

    if (value == 0.0)
    {
        saturation = 0.0;
    }
    else
    {
        saturation = chroma / value;
    }
}
///
//////////////////////////////////////////////////////////////////////////


void ColorTable::insertHueSaturationValueGradient(const Color& color1, const Color& color2, const int& position1, const int& position2)
{
    if (position2 > position1 && position1 >= 0 && position2 < (int)Colors.size())
    {
        double hue1=0.0;
        double sat1=0.0;
        double value1=0.0;
        color1.getHSV(hue1,sat1,value1);
        double hue2=0.0;
        double sat2=0.0;
        double value2=0.0;
        color2.getHSV(hue2,sat2,value2);

        /*color1.setFromHSV(std::as_const(hue1),const_cast<const double(sat1)>sat1,const_cast<value1>);
        color2.setFromHSV(const_cast<hue2>,const_cast<sat2>,const_cast<value2>);
        */      
        /*color1.setFromHSV(hue1,sat1,value1);
        color2.setFromHSV(hue2,sat2,value2);
        */
        /*double Redstep = gradientSlope(color1.getRed(), color2.getRed(), position1, position2);
        double Greenstep = gradientSlope(color1.getGreen(), color2.getGreen(), position1, position2);
        double Bluestep = gradientSlope(color1.getBlue(), color2.getBlue(), position1, position2);
        for (int i = position1; i <= position2; i++)
        {
            Colors[i].setRed(gradientValue(color1.getRed(), position1, Redstep, i));
            Colors[i].setGreen(gradientValue(color1.getGreen(), position1, Greenstep, i));
            Colors[i].setBlue(gradientValue(color1.getBlue(), position1, Bluestep, i));
        }*/
        double hueflex = gradientSlope(hue1, hue2, position1, position2);
        double satflex = gradientSlope(sat1, sat2, position1, position2);
        double valflex = gradientSlope(value1, value2, position1, position2);
        for (int i = position1; i <= position2; i++)
        {
            //hueflex,satflex,valflex
            //gradientValue(hue1,position1,hueflex,i),gradientValue(sat1,position1,satflex,i),gradientValue(val1,position1,valflex,i)
            Colors[i].setFromHSV(gradientValue(hue1,position1,hueflex,i),gradientValue(sat1,position1,satflex,i),gradientValue(value1,position1,valflex,i));
        }
    }
}
