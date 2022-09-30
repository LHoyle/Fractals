// class definition
#ifndef _ActionData_H_
#define _ActionData_H_
#include "PPM.h"

class ActionData : public PPM
{
public:
    ActionData(std::istream &is, std::ostream &os);
    std::istream &getIS();
    std::ostream &getOS();
    PPM &getInputImage1();
    PPM &getInputImage2();
    PPM &getOutputImage();
    bool getDone() const;
    void setDone();

protected:
};