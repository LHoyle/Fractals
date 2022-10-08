#include "image_menu.h"
#include <iostream>
int main()
{
    ActionData action_data=ActionData(std::cin,std::cout);
    int value = assignment3(action_data);
    return value;
}