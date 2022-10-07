#include "MenuData.h"

typedef void (*ActionFunctionType)(ActionData &action_data){
    std::vector<std::string>;
    std::map<std::string,ActionFunctionType>;
    std::map<std::string,std::string>;

}
MenuData::MenuData()
{
}
void MenuData::addAction(const std::string &name, ActionFunctionType func, const std::string &description)
{
    if name in cmds{
        return false
    }
    else 
    cmds.append (name,func)
}
const std::vector<std::string> MenuData::getNames() const
{
}
ActionFunctionType MenuData::getFunction(const std::string &name)
{
}
const std::string MenuData::getDescription(const std::string &name)
{
}