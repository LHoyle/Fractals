#include "image_menu.h"
#include <stdexcept>

void showMenu(MenuData &menu_data, ActionData &action_data)
{
    int current = 0;
    const std::vector<std::string> vecofnames = menu_data.getNames();
    while (vecofnames.at(current) != vecofnames.back())
    {
        action_data.getOS() << vecofnames.at(current) << ") " << menu_data.getDescription(vecofnames.at(current)) << std::endl;
        current = current + 1;
    }
    action_data.getOS() << vecofnames.back() << ") " << menu_data.getDescription(vecofnames.back()) << std::endl;
}
void takeAction(const std::string &choice, MenuData &menu_data, ActionData &action_data)
{
    if (choice == "menu")
    {
        showMenu(menu_data,action_data);
        return;
    }
    int vecsize= menu_data.getNames().size();
    for (int i = 0; i < vecsize; i++)
    {
        if (menu_data.getNames().at(i) == choice)
        {
            ActionFunctionType act = menu_data.getFunction(choice);
            if (act != 0)
            {

                act(action_data);
                return;
            }
        }
    }
    action_data.getOS() << "Unknown action " << choice << "." << std::endl;
}
void configureMenu(MenuData &menu_data)
{
    menu_data.addAction("draw-ascii",drawAsciiImage,"Write output image to terminal as ASCII art.");
    menu_data.addAction("write",writeUserImage,"Write output image to file.");
    menu_data.addAction("copy",copyImage,"Copy input image 1 to output image.");
    menu_data.addAction("read1",readUserImage1,"Read file into input image 1.");
    menu_data.addAction("#",commentLine,"Comment to end of line.");
    menu_data.addAction("size",setSize,"Set the size of input image 1.");
    menu_data.addAction("max-color-value",setMaxColorValue,"Set the max color value of input image 1.");
    menu_data.addAction("channel",setChannel,"Set a channel value in input image 1.");
    menu_data.addAction("pixel",setPixel,"Set a pixel's 3 values in input image 1.");
    menu_data.addAction("clear",clearAll,"Set all pixels to 0,0,0 in input image 1.");
    menu_data.addAction("quit",quit,"Quit.");
}
int imageMenu(std::istream &is, std::ostream &os)
{
    ActionData  ac = ActionData(is,os);
    MenuData menu= MenuData();
    configureMenu(menu);
    std::string choice;
    while (ac.getDone()==false){
choice = getChoice(ac);
takeAction(choice,menu,ac);
    }
    return 0;
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