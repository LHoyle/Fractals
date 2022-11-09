#include "image_menu.h"

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
        showMenu(menu_data, action_data);
        return;
    }
    int vecsize = menu_data.getNames().size();
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
    action_data.getOS() << "Unknown action '" << choice << "'." << std::endl;
}
void configureMenu(MenuData &menu_data)
{
    menu_data.addAction("draw-ascii", drawAsciiImage, "Write output image to terminal as ASCII art.");
    menu_data.addAction("write", writeUserImage, "Write output image to file.");
    menu_data.addAction("copy", copyImage, "Copy input image 1 to output image.");
    menu_data.addAction("read1", readUserImage1, "Read file into input image 1.");
    menu_data.addAction("#", commentLine, "Comment to end of line.");
    menu_data.addAction("size", setSize, "Set the size of input image 1.");
    menu_data.addAction("max-color-value", setMaxColorValue, "Set the max color value of input image 1.");
    menu_data.addAction("channel", setChannel, "Set a channel value in input image 1.");
    menu_data.addAction("pixel", setPixel, "Set a pixel's 3 values in input image 1.");
    menu_data.addAction("clear", clearAll, "Set all pixels to 0,0,0 in input image 1.");
    menu_data.addAction("quit", quit, "Quit.");
    menu_data.addAction("read2", readUserImage2, "Read file into input image 2.");
    menu_data.addAction("+", plus, "Set output image from sum of input image 1 and input image 2.");
    menu_data.addAction("+=", plusEquals, "Set input image 1 by adding in input image 2.");
    menu_data.addAction("-", minus, "Set output image from difference of input image 1 and input image 2.");
    menu_data.addAction("-=", minusEquals, "Set input image 1 by subtracting input image 2.");
    menu_data.addAction("*", times, "Set output image from input image 1 multiplied by a number.");
    menu_data.addAction("*=", timesEquals, "Set input image 1 by multiplying by a number.");
    menu_data.addAction("/", divide, "Set output image from input image 1 divided by a number.");
    menu_data.addAction("/=", divideEquals, "Set input image 1 by dividing by a number.");
    menu_data.addAction("red-gray", grayFromRed, "Set output image by grayscale from red on input image 1.");
    menu_data.addAction("green-gray", grayFromGreen, "Set output image by grayscale from green on input image 1.");
    menu_data.addAction("blue-gray", grayFromBlue, "Set output image by grayscale from blue on input image 1.");
    menu_data.addAction("linear-gray", grayFromLinearColorimetric, "Set output image by linear colorimetric grayscale on input image 1.");
    menu_data.addAction("circle", drawCircle, "Draw a circle shape in input image 1.");
    menu_data.addAction("box", drawBox, "Draw a box shape in input image 1.");
    menu_data.addAction("square", drawSquare, "Draw a square shape in input image 1.");
    menu_data.addAction("orange", orangeFilter, "Set output image from orange filter on input image 1.");
    menu_data.addAction("*=-ppm", timesEqualsPPM, "Set input image 1 by multiplying by input image 2.");
    menu_data.addAction("grid", configureGrid, "Configure the grid.");
    menu_data.addAction("grid-set", setGrid, "Set a single value in the grid.");
    menu_data.addAction("grid-apply", applyGrid, "Use the grid values to set colors in the output image.");
    menu_data.addAction("set-color-table-size", setColorTableSize, "Change the number of slots in the color table.");
    menu_data.addAction("set-color", setColor, "Set the RGB values for one slot in the color table.");
    menu_data.addAction("set-random-color", setRandomColor, "Randomly set the RGB values for one slot in the color table.");
    menu_data.addAction("set-color-gradient", setColorGradient, "Smoothly set the RGB values for a range of slots in the color table.");
    menu_data.addAction("grid-apply-color-table", applyGridColorTable, "Use the grid values to set colors in the output image using the color table.");
    menu_data.addAction("fractal-plane-size", setFractalPlaneSize, "Set the dimensions of the grid in the complex plane.");
    menu_data.addAction("fractal-calculate", calculateFractal, "Calculate the escape values for the fractal.");
    menu_data.addAction("julia-parameters", setJuliaParameters, "Set the parameters of the Julia Set function.");
    menu_data.addAction("complex-fractal", setComplexFractal, "Choose to make a complex plane.");
    menu_data.addAction("julia", setJuliaFractal, "Choose to make a Julia set.");
    menu_data.addAction("mandelbrot", setMandelbrotFractal, "Choose to make a Mandelbrot set.");
    // menu_data.addAction("q", q, "");
}
int imageMenu(std::istream &is, std::ostream &os)
{
    ActionData ac = ActionData(is, os);
    ac.setGrid(new ComplexFractal);
    MenuData menu = MenuData();
    configureMenu(menu);
    std::string choice;
    // showMenu(menu,ac);
    while (ac.getDone() == false && ac.getIS().good())
    {

        choice = getChoice(ac);
        takeAction(choice, menu, ac);
    }
    return 0;
}
void setComplexFractal(ActionData &action_data)
{
    action_data.setGrid(new ComplexFractal);
}
void setJuliaFractal(ActionData &action_data)
{
    action_data.setGrid(new JuliaSet);
}

int assignment1(std::istream &is, std::ostream &os)
{
    ActionData ac = ActionData(is, os);
    int value = askQuestions3(ac);

    return value;
}

int assignment2(std::istream &is, std::ostream &os)
{
    // Image imag = Image();
    ActionData ac = ActionData(is, os);
    diagonalQuadPattern(ac);
    ac.getOutputImage() = ac.getInputImage1();
    drawAsciiImage(ac);
    return 0;
}

int assignment3(std::istream &is, std::ostream &os)
{
    // PPM ppm = PPM();
    ActionData ac = ActionData(is, os);
    stripedDiagonalPattern(ac);
    ac.getOutputImage() = ac.getInputImage1();
    writeUserImage(ac);
    return 0;
}
int buck(std::istream &is, std::ostream &os)
{
    ActionData ac = ActionData(is, os);
    int value = askUncleBuckQuestions(ac);
    return value;
}
int flag_columbia_ascii(std::istream &is, std::ostream &os)
{
    // Image Imp =Image();
    ActionData ac = ActionData(is, os);
    flagColumbiaPattern(ac);
    ac.getOutputImage() = ac.getInputImage1();
    drawAsciiImage(ac);
    return 0;
}

void setMandelbrotFractal( ActionData& action_data ){
    action_data.setGrid(new MandelbrotSet);
}