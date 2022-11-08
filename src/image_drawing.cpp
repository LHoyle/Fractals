#include "image_menu.h"

void setFractalPlaneSize(ActionData &action_data)
{
    ComplexFractal *Mists = dynamic_cast<ComplexFractal *>(&action_data.getGrid());
    if (0 != Mists)
    {
        double MinX = getDouble(action_data, "Min X? ");
        double MaxX = getDouble(action_data, "Max X? ");
        double MinY = getDouble(action_data, "Min Y? ");
        double MaxY = getDouble(action_data, "Max Y? ");
        Mists->setPlaneSize(MinX, MaxX, MinY, MaxY);
        Mists->calculateAllNumbers();
        return;
    }
    action_data.getOS() << "Not a ComplexFractal object. Can't set plane size." << std::endl;
    return;
}
void calculateFractal(ActionData &action_data)
{
    action_data.getGrid().calculateAllNumbers();
}

void setColorTableSize(ActionData &action_data)
{
    int Size = getInteger(action_data, "Size? ");
    action_data.getTable().setNumberOfColors(Size);
}
void setColor(ActionData &action_data)
{
    Color MantisShrimp;
    int POS = getInteger(action_data, "Position? ");
    int FirstRed = getInteger(action_data, "Red? ");
    int FirstGreen = getInteger(action_data, "Green? ");
    int FirstBlue = getInteger(action_data, "Blue? ");
    MantisShrimp.setRed(FirstRed);
    MantisShrimp.setGreen(FirstGreen);
    MantisShrimp.setBlue(FirstBlue);
    action_data.getTable()[POS] = MantisShrimp;
}
void setRandomColor(ActionData &action_data)
{
    int POS = getInteger(action_data, "Position? ");
    action_data.getTable().setRandomColor(255, POS);
}
void setColorGradient(ActionData &action_data)
{
    Color MantisShrimp;
    Color BloodSoakedRainbows;
    int POS = getInteger(action_data, "First position? ");
    int FirstRed = getInteger(action_data, "First red? ");
    int FirstGreen = getInteger(action_data, "First green? ");
    int FirstBlue = getInteger(action_data, "First blue? ");
    int POS2 = getInteger(action_data, "Second position? ");
    int SecondRed = getInteger(action_data, "Second red? ");
    int SecondGreen = getInteger(action_data, "Second green? ");
    int SecondBlue = getInteger(action_data, "Second blue? ");
    MantisShrimp.setRed(FirstRed);
    MantisShrimp.setGreen(FirstGreen);
    MantisShrimp.setBlue(FirstBlue);
    BloodSoakedRainbows.setRed(SecondRed);
    BloodSoakedRainbows.setGreen(SecondGreen);
    BloodSoakedRainbows.setBlue(SecondBlue);
    action_data.getTable().insertGradient(MantisShrimp, BloodSoakedRainbows, POS, POS2);
}
void applyGridColorTable(ActionData &action_data)
{
    action_data.getGrid().setPPM(action_data.getOutputImage(), action_data.getTable());
}

void configureGrid(ActionData &action_data)
{

    int height = getInteger(action_data, "Grid Height? ");
    int width = getInteger(action_data, "Grid Width? ");
    int Val = getInteger(action_data, "Grid Max Value? ");
    action_data.getGrid().setGridSize(height, width);
    action_data.getGrid().setMaxNumber(Val);
}

void setGrid(ActionData &action_data)
{
    int rowing = getInteger(action_data, "Grid Row? ");
    int colups = getInteger(action_data, "Grid Column? ");
    int Val = getInteger(action_data, "Grid Value? ");
    action_data.getGrid().setNumber(rowing, colups, Val);
}

void applyGrid(ActionData &action_data)
{
    action_data.getGrid().setPPM(action_data.getOutputImage());
}

void drawSquare(ActionData &action_data)
{
    int rowing = getInteger(action_data, "Row? ");
    int colups = getInteger(action_data, "Column? ");
    int size = getInteger(action_data, "Size? ");
    int r = getInteger(action_data, "Red? ");
    int g = getInteger(action_data, "Green? ");
    int b = getInteger(action_data, "Blue? ");
    int halfsies = size / 2;
    for (int row = rowing - halfsies; row <= rowing + halfsies; row++)
    {
        for (int col = colups - halfsies; col <= colups + halfsies; col++)
        {
            action_data.getInputImage1().setPixel(row, col, r, g, b);
        }
    }
}

void drawCircle(ActionData &action_data)
{
    int rowcent = getInteger(action_data, "Center Row? ");
    int colcent = getInteger(action_data, "Center Column? ");
    double radius = getDouble(action_data, "Radius? ");
    int r = getInteger(action_data, "Red? ");
    int g = getInteger(action_data, "Green? ");
    int b = getInteger(action_data, "Blue? ");

    for (int row = 0; row < action_data.getInputImage1().getHeight(); row++)
    {
        for (int col = 0; col < action_data.getInputImage1().getWidth(); col++)
        {

            if (radius >= std::sqrt(std::pow(row - rowcent, 2) + std::pow(col - colcent, 2)))
            {
                action_data.getInputImage1().setPixel(row, col, r, g, b);
            }
        }
    }
}
void drawBox(ActionData &action_data)
{
    int rowstart = getInteger(action_data, "Top Row? ");
    int colstart = getInteger(action_data, "Left Column? ");
    int rowend = getInteger(action_data, "Bottom Row? ");
    int colend = getInteger(action_data, "Right Column? ");
    int r = getInteger(action_data, "Red? ");
    int g = getInteger(action_data, "Green? ");
    int b = getInteger(action_data, "Blue? ");
    for (int row = rowstart; row <= rowend; row++)
    {
        for (int col = colstart; col <= colend; col++)
        {
            action_data.getInputImage1().setPixel(row, col, r, g, b);
        }
    }
}

void setSize(ActionData &action_data)
{
    int row = getInteger(action_data, "Height? ");
    int column = getInteger(action_data, "Width? ");
    action_data.getInputImage1().setHeight(row);
    action_data.getInputImage1().setWidth(column);
}

void setMaxColorValue(ActionData &action_data)
{
    int mcv = getInteger(action_data, "Max color value? ");
    action_data.getInputImage1().setMaxColorValue(mcv);
}
void setChannel(ActionData &action_data)
{
    int row = getInteger(action_data, "Row? ");
    int column = getInteger(action_data, "Column? ");
    int channel = getInteger(action_data, "Channel? ");
    int value = getInteger(action_data, "Value? ");
    action_data.getInputImage1().setChannel(row, column, channel, value);
}

void setPixel(ActionData &action_data)
{
    int row = getInteger(action_data, "Row? ");
    int column = getInteger(action_data, "Column? ");
    int Red = getInteger(action_data, "Red? ");
    int Green = getInteger(action_data, "Green? ");
    int Blue = getInteger(action_data, "Blue? ");
    action_data.getInputImage1().setChannel(row, column, 0, Red);
    action_data.getInputImage1().setChannel(row, column, 1, Green);
    action_data.getInputImage1().setChannel(row, column, 2, Blue);
}

void clearAll(ActionData &action_data)
{
    int row;
    for (row = 0; row <= action_data.getInputImage1().getHeight(); row++)
    {

        int column;
        for (column = 0; column <= action_data.getInputImage1().getWidth(); column++)
        {

            action_data.getInputImage1().setChannel(row, column, 0, 0);
            action_data.getInputImage1().setChannel(row, column, 1, 0);
            action_data.getInputImage1().setChannel(row, column, 2, 0);
        }
    }
}
void flagColumbiaPattern(ActionData &action_data)
{
    int Hheight = getInteger(action_data, "Image height? ");
    action_data.getInputImage1().setHeight(Hheight);
    int heightcon1 = Hheight * 3;
    int heightcon2 = heightcon1 / 2;
    action_data.getInputImage1().setWidth(heightcon2);

    int row;
    int rowhalf = (action_data.getInputImage1().getHeight() / 2);
    int rowthird = (rowhalf / 2);
    int rowthirdbottom = rowthird + rowhalf;
    for (row = 0; row <= action_data.getInputImage1().getHeight(); row++)
    {

        int column;
        for (column = 0; column <= action_data.getInputImage1().getWidth(); column++)
        {

            if (row >= rowthirdbottom && row >= rowhalf)

            {
                // RGB: Red 206-17-38), ~
                action_data.getInputImage1().setChannel(row, column, 0, 206);
                action_data.getInputImage1().setChannel(row, column, 1, 17);
                action_data.getInputImage1().setChannel(row, column, 2, 38);
            }
            else if (row >= rowhalf)
            {
                // os<<"got here";
                action_data.getInputImage1().setChannel(row, column, 0, 0);
                action_data.getInputImage1().setChannel(row, column, 1, 56);
                action_data.getInputImage1().setChannel(row, column, 2, 147);
                // RGB: Blue 0-56-147), -
            }
            else
            {
                // RGB: yellow 252-209-22 |
                action_data.getInputImage1().setChannel(row, column, 0, 252);
                action_data.getInputImage1().setChannel(row, column, 1, 209);
                action_data.getInputImage1().setChannel(row, column, 2, 22);
            }
        }
    }
}

void stripedDiagonalPattern(ActionData &action_data)
{
    std::string imagestringpromptone = "Image height? ";
    int height = getInteger(action_data, imagestringpromptone);

    std::string imagestringprompttwo = "Image width? ";
    int width = getInteger(action_data, imagestringprompttwo);
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);

    int rowhalf = (action_data.getInputImage1().getHeight() / 2);
    // os << p.getHeight();
    // os << p.getWidth();
    int r;
    int g;
    int b;

    int maxCV = (height + width) / 3;
    // os<<height<<width<<maxCV<<std::endl;
    if (maxCV >= 255)
    {
        action_data.getInputImage1().setMaxColorValue(255);
        // os << p.getMaxColorValue();
    }
    else
    {
        action_data.getInputImage1().setMaxColorValue(maxCV);
        // os << p.getMaxColorValue();
    }
    int row;
    for (row = 0; row < action_data.getInputImage1().getHeight(); row++)
    {

        int column;
        for (column = 0; column < action_data.getInputImage1().getWidth(); column++)
        {
            /*int greensleevesp1(row + p.getWidth() - column - 1);
            int greensleevesp2(p.getMaxColorValue()+1);
            int greensleeves = greensleevesp1 % greensleevesp2;
            p.setChannel(row, column, 1, greensleeves);
            // g = (row + width - column - 1) % (p.getMaxColorValue() + 1);
            if (row < rowhalf)
            {
                p.setChannel(row, column, 0, 0);
            }
            else if (row % 3 == 0)
            {
                p.setChannel(row, column, 0, 0);
            }
            else
            {
                p.setChannel(row, column, 0, p.getMaxColorValue());
            }
            if (column < row)
            {
                p.setChannel(row, column, 2, 0);
            }
            else
            {
                p.setChannel(row, column, 2, p.getMaxColorValue());
            }*/

            int greensleevesp1(row + action_data.getInputImage1().getWidth() - column - 1);
            int greensleevesp2(action_data.getInputImage1().getMaxColorValue() + 1);
            int greensleeves = greensleevesp1 % greensleevesp2;
            g = greensleeves;
            // os<<greensleevesp1<<greensleevesp2<<g<<std::endl;
            if (row < rowhalf)
            {
                r = 0;
            }
            else
            {
                if (row % 3 == 0)
                {
                    r = 0;
                }
                else
                {
                    r = action_data.getInputImage1().getMaxColorValue();
                }
            }
            if (column < row)
            {
                b = 0;
            }
            else
            {
                b = action_data.getInputImage1().getMaxColorValue();
            }
            action_data.getInputImage1().setPixel(row, column, r, g, b);
            // os<<r<<std::endl<<g<<std::endl<<b<<std::endl;
        }
    }
}

void diagonalQuadPattern(ActionData &action_data)
{
    std::string imagestringpromptone = "Image height? ";
    int height = getInteger(action_data, imagestringpromptone);

    std::string imagestringprompttwo = "Image width? ";
    int width = getInteger(action_data, imagestringprompttwo);
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);
    action_data.getInputImage1().setMaxColorValue(255);

    int rowhalf = (action_data.getInputImage1().getHeight() / 2);
    int colhalf = (action_data.getInputImage1().getWidth() / 2);

    int row;
    for (row = 0; row < action_data.getInputImage1().getHeight(); row++)
    {

        int column;
        for (column = 0; column < action_data.getInputImage1().getWidth(); column++)
        {

            if (row < rowhalf && column < colhalf)
            {
                // top left
                action_data.getInputImage1().setChannel(row, column, 0, 0);
                // int red =0;
                action_data.getInputImage1().setChannel(row, column, 2, 0);
                // int blue =0;
                action_data.getInputImage1().setChannel(row, column, 1, (2 * row + 2 * column) % 256);
                // int = green ( 2*row + 2*column ) % 256;
            }
            else if (row >= rowhalf && column < colhalf)
            {
                // top right
                // int red = 0;
                action_data.getInputImage1().setChannel(row, column, 0, 255);
                // int blue =255;
                action_data.getInputImage1().setChannel(row, column, 2, 0);
                // int = green ( 2*row + 2*column ) % 256;
                action_data.getInputImage1().setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
            else if (row < rowhalf && column >= colhalf)
            {
                // bottom left
                // int red = 255;
                action_data.getInputImage1().setChannel(row, column, 0, 0);
                // int blue =0;
                action_data.getInputImage1().setChannel(row, column, 2, 255);
                // int = green ( 2*row + 2*column ) % 256;
                action_data.getInputImage1().setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
            else if (row >= rowhalf && column >= colhalf)
            {
                // bottom right
                // int red = 255;
                action_data.getInputImage1().setChannel(row, column, 0, 255);
                // int blue =255;
                action_data.getInputImage1().setChannel(row, column, 2, 255);
                // int = green ( 2*row + 2*column ) % 256;
                action_data.getInputImage1().setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
        }
    }
}