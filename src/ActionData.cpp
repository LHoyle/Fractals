#include "ActionData.h"

ActionData::ActionData(std::istream& is, std::ostream& os)
    :AIS(is), AOS(os), check(false)
{
}
std::istream& ActionData::getIS()
{
    return AIS;
}
std::ostream& ActionData::getOS()
{
    return AOS;
}
PPM& ActionData::getInputImage1()
{
    return inim1;
}
PPM& ActionData::getInputImage2()
{
    return inim2;
}
PPM& ActionData::getOutputImage()
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