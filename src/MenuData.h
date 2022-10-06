class MenuData
{
public:
    typedef void (*ActionFunctionType)(ActionData &action_data);
    MenuData();
    void addAction(const std::string &name, ActionFunctionType func, const std::string &description);
    const std::vector<std::string> &getNames() const;
    ActionFunctionType getFunction(const std::string &name);
    const std::string &getDescription(const std::string &name);

protected:
    std::vector<std::string> cmds;
    std::map<std::string, ActionFunctionType> AFT;
    std::map<std::string, std::string> mapstring;
}