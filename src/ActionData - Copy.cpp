#include "ActionData.h"
ActionData::ActionData(is, os)
{
    AIS = is;
    AOS = os;
    check = false;
}
ActionData::getIS()
{
    return AIS;
}
ActionData::getOS()
{
    return AOS;
}
ActionData::getInputImage1()
{
    return inim1;
}
ActionData::getInputImage2()
{
    return inim2;
}
ActionData::getOutputImage()
{
    return oim;
}
bool ActionData::getDone() const
{
    return check;
}
void ActionData::setDone()
{
    check = true;
}