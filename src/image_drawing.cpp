#include "image_menu.h"

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