#include "image_menu.h"

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
    p.setHeight(height);
    p.setWidth(width);

    int rowhalf = (p.getHeight() / 2);
    // os << p.getHeight();
    // os << p.getWidth();
    int r;
    int g;
    int b;

    int maxCV = (height + width) / 3;
    // os<<height<<width<<maxCV<<std::endl;
    if (maxCV >= 255)
    {
        p.setMaxColorValue(255);
        // os << p.getMaxColorValue();
    }
    else
    {
        p.setMaxColorValue(maxCV);
        // os << p.getMaxColorValue();
    }
    int row;
    for (row = 0; row < p.getHeight(); row++)
    {

        int column;
        for (column = 0; column < p.getWidth(); column++)
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

            int greensleevesp1(row + p.getWidth() - column - 1);
            int greensleevesp2(p.getMaxColorValue() + 1);
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
                    r = p.getMaxColorValue();
                }
            }
            if (column < row)
            {
                b = 0;
            }
            else
            {
                b = p.getMaxColorValue();
            }
            p.setPixel(row, column, r, g, b);
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
    image.setHeight(height);
    image.setWidth(width);

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
                image.setChannel(row, column, 0, 0);
                // int red =0;
                image.setChannel(row, column, 2, 0);
                // int blue =0;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
                // int = green ( 2*row + 2*column ) % 256;
            }
            else if (row >= rowhalf && column < colhalf)
            {
                // top right
                // int red = 0;
                image.setChannel(row, column, 0, 255);
                // int blue =255;
                image.setChannel(row, column, 2, 0);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
            else if (row < rowhalf && column >= colhalf)
            {
                // bottom left
                // int red = 255;
                image.setChannel(row, column, 0, 0);
                // int blue =0;
                image.setChannel(row, column, 2, 255);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
            else if (row >= rowhalf && column >= colhalf)
            {
                // bottom right
                // int red = 255;
                image.setChannel(row, column, 0, 255);
                // int blue =255;
                image.setChannel(row, column, 2, 255);
                // int = green ( 2*row + 2*column ) % 256;
                image.setChannel(row, column, 1, (2 * row + 2 * column) % 256);
            }
        }
    }
}