#include "image_menu.h"

void showMenu(MenuData &menu_data, ActionData &action_data)
{
    while (menu_data)
}
void takeAction(const std::string &choice, MenuData &menu_data, ActionData &action_data)
{
}
void configureMenu(MenuData &menu_data)
{
}
int imageMenu(std::istream &is, std::ostream &os)
{
}

int assignment1(ActionData &action_data)
{
    int value = askQuestions3(action_data);
    return value;
}

int assignment2(ActionData &action_data)
{
    // Image imag = Image();
    diagonalQuadPattern(action_data);
    drawAsciiImage(action_data);
    return 0;
}

int assignment3(ActionData &action_data)
{
    // PPM ppm = PPM();
    stripedDiagonalPattern(action_data);
    writeUserImage(action_data);
    return 0;
}
int buck(ActionData &action_data)
{
    int value = askUncleBuckQuestions(action_data);
    return value;
}
int flag_columbia_ascii(ActionData &action_data)
{
    // Image Imp =Image();
    flagColumbiaPattern(action_data);
    drawAsciiImage(action_data);
    return 0;
}