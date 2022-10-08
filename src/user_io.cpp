#include "image_menu.h"
#include "ActionData.h"

std::string getString(ActionData &action_data, const std::string &prompt)
{
    // std::istream& is;
    // action_data.getIS() >> is;

    // std::ostream& os;
    // action_data.getOS() >> os;

    std::string value;
    action_data.getOS() << prompt;
    action_data.getIS() >> value;
    // os <<std::endl;
    return value;
}

int getInteger(ActionData &action_data, const std::string &prompt)
{
    int value;
    action_data.getOS() << prompt;
    action_data.getIS() >> value;

    return value;
}

double getDouble(ActionData &action_data, const std::string &prompt)
{
    double value;
    action_data.getOS() << prompt;
    action_data.getIS() >> value;
    // os <<std::endl;
    return value;
}

int askQuestions3(ActionData &action_data)
{
    std::string stringprompt = "What is your favorite color? ";
    std::string stringvalue = getString(action_data, stringprompt);
    std::string doubleprompt = "What is your favorite integer? ";
    int intvalue = getInteger(action_data, doubleprompt);
    std::string intprompt = "What is your favorite number? ";
    double doublevalue = getDouble(action_data, intprompt);
    // os <<std::endl;
    int i;
    std::string space = " ";
    if (intvalue <= 0)
    {
        return intvalue;
    }
    /*if (intvalue==1){
        std::cout << intvalue<< space << stringvalue << space << doublevalue << std::endl;
        return intvalue;
    }*/
    for (i = 1; i <= intvalue; i++)
    {
        action_data.getOS() << i << space << stringvalue << space << doublevalue;
        action_data.getOS() << std::endl;
    }
    // os <<std::endl;
    return intvalue;
}

int askUncleBuckQuestions(ActionData &action_data)
{

    std::string in1 = "Where do you live? ";
    std::string in2 = "Own or rent? ";
    std::string in3 = "What is your record for consecutive questions asked? ";
    std::string a1 = getString(action_data, in1);
    std::string a2 = getString(action_data, in2);
    int a3 = getInteger(action_data, in3);
    if (a3 >= 30)
    {
        action_data.getOS() << a3 << " is pretty good. Enjoy " << a2 << " in the " << a1 << '.';
    }
    else
    {
        action_data.getOS() << a3 << " is okay. Enjoy " << a2 << " in the " << a1 << '.';
    }
    return a3;
}

std::string getChoice(ActionData &action_data)
{
    return getString(action_data, "Choice? ");
}
void commentLine( ActionData& action_data ){

    unsigned char byte; // char is a one byte int. this stores from 0 to 255
    action_data.getIS().read((char * ) &byte,sizeof(byte));
    while (byte != '\n'){
    if (action_data.getIS().good())
    {
        action_data.getIS().read((char * ) &byte,sizeof(byte));
    }

    }
    
    
}
void quit(ActionData& action_data){
    action_data.setDone();
}