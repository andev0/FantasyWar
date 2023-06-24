#ifndef FW_INPUTMENUITEM_H
#define FW_INPUTMENUITEM_H

#include "MenuItem.h"

#include <functional>

namespace fw
{

class InputMenuItem : public MenuItem
{
public:
    explicit InputMenuItem(const std::string& inputPrefix = "> ");

    const std::string& getText() const override;

    void setResult(const std::string& result);
    const std::string& getResult() const;

    void invokeOnResultSet(const std::function<void(const std::string&)>& action);

private:
    std::string m_result;
    std::string m_inputPrefix = "> ";
    std::function<void(const std::string&)> m_onResultSet {[](const std::string&) {}};
};

} // namespace fw

#endif // FW_INPUTMENUITEM_H
