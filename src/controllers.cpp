#include "image_menu.h"

int assignment1(ActionData &action_data)
{
    int value = askQuestions3(action_data);
    return value;
}

int assignment2(ActionData &action_data)
{
    //Image imag = Image();
    diagonalQuadPattern(action_data);
    drawAsciiImage(action_data);
    return 0;
}

int assignment3(ActionData &action_data)
{
    //PPM ppm = PPM();
    stripedDiagonalPattern(action_data);
    writeUserImage(action_data);
    return 0;
}
int buck(ActionData &action_data){
    int value = askUncleBuckQuestions (action_data);
    return value;
}
int flag_columbia_ascii(ActionData& action_data){
    //Image Imp =Image();
    flagColumbiaPattern(action_data);
    drawAsciiImage(action_data);
    return 0;
}