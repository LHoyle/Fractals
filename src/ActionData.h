// class definition
#ifndef _ActionData_H_
#define _ActionData_H_
#include "PPM.h"
#include "ColorTable.h"
#include "NumberGrid.h"

class ActionData
{
public:
    ActionData(std::istream& is, std::ostream& os);
    std::istream& getIS();
    std::ostream& getOS();
    PPM& getInputImage1();
    PPM& getInputImage2();
    PPM& getOutputImage();
    bool getDone() const;
    void setDone();
    ~ActionData();
    NumberGrid& getGrid();
    void setGrid(NumberGrid *grid);
    ColorTable& getTable();
protected:
    std::istream& AIS;
    std::ostream& AOS;
    PPM inim1;
    PPM inim2;
    PPM oim;
    bool check;
    NumberGrid *Numpoint;
    ColorTable CTable;
};

#endif
/*_ActionData_H_
Local Variables:
mode:c++
End: */