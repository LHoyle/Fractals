#include "MenuData.h"


typedef void (*ActionFunctionType)(ActionData &action_data);
MenuData::MenuData()
{
}
void MenuData::addAction(const std::string &name, ActionFunctionType func, const std::string &description)
{
    cmds.push_back(name);
    AFT[name] = func;
    mapstring[name] = description;
}
const std::vector<std::string> &MenuData::getNames() const
{
    return cmds;
}
ActionFunctionType MenuData::getFunction(const std::string &name)
{
    //  std::map<std::string, ActionFunctionType>::iterator AFTS= AFT.find(name) ;
    // if (AFTS!=AFT.end()){
    //     return AFT[name];
    // }
    // return 0;

    if (AFT.find(name) != AFT.end())
    {
        return AFT[name];
    }
    else
    {
        return 0;
    }
}
const std::string &MenuData::getDescription(const std::string &name)
{
    static std::string lolnope = "";
    std::map<std::string, std::string>::iterator found = mapstring.find(name);
    if (found != mapstring.end())
    {
        return mapstring[name];
    }
    return lolnope;
}