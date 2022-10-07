#ifndef _MenuData_H_
#define _MenuData_H_
#include <string>
#include <vector>
#include <map>
#include "ActionData.h"


class MenuData
{
public:
    typedef void (*ActionFunctionType)(ActionData& action_data);
    MenuData();
    void addAction(const std::string &name, ActionFunctionType func, const std::string& description);
    const std::vector<std::string>& getNames() const;
    ActionFunctionType getFunction(const std::string& name);
    const std::string& getDescription(const std::string& name);

protected:
    std::vector<std::string> cmds;
    std::map<std::string, ActionFunctionType> AFT;
    std::map<std::string, std::string> mapstring;
};

#endif
/*_ActionData_H_
Local Variables:
mode:c++
End: */