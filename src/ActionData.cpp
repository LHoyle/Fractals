#include "ActionData.h"

ActionData::ActionData(std::istream& is, std::ostream& os)
    :AIS(is), AOS(os), check(false), Numpoint(0),CTable(ColorTable(16))
{//ColorTable CTable = (ColorTable(16));
Color C1 = Color(0,255,0);
Color C2 = Color(255,0,255);
    CTable.insertGradient(C1,C2,0,15);
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
ActionData::~ActionData(){
    if (Numpoint!=0){
        delete Numpoint;
    }
}
NumberGrid& ActionData::getGrid(){
 return *Numpoint;
}
void ActionData::setGrid(NumberGrid *grid){
    
    if (grid != 0){
        delete Numpoint;
    }
    Numpoint = grid;
}
ColorTable& ActionData::getTable(){
    return CTable;
}