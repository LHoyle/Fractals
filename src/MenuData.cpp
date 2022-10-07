#include "MenuData.h"

typedef void (*ActionFunctionType)(ActionData& action_data);
MenuData::MenuData()
{
}
void MenuData::addAction(const std::string& name, ActionFunctionType func, const std::string &description)
{
   cmds.push_back(name);
   AFT[name]=func;
   mapstring[name]=description;
}
const std::vector<std::string>& MenuData::getNames() const
{
    return cmds;
}
ActionFunctionType MenuData::getFunction(const std::string& name)
{
    if (AFT.find(name) ){
        return AFT.find(name);
    }
    return 0;
}
const std::string& MenuData::getDescription(const std::string& name)
{
    static std::string lolnope = "";
    if (mapstring.find(name)){
        return mapstring.find(name);
    }
    return lolnope;
}