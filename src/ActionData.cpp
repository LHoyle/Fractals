#include "ActionData.h"

ActionData::ActionData(std::istream& is, std::ostream& os)
    :AIS(is), AOS(os), check(false), Numpoint(0)
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
~ActionData(){
    if (Numpoint!=0){
        delete;
    }
}
NumberGrid& getGrid(){
 return *Numpoint;
}
void setGrid(NumberGrid *grid){
    
    if (*grid != 0){
        ~ActionData();
    }
    Numpoint = grid;
}