#ifndef FW_INPUTMENUITEM_H
#define FW_INPUTMENUITEM_H

#include "MenuItem.h"

#include <functional>

namespace fw
{

class InputMenuItem : public MenuItem
{
public:
    const std::string& getText() const override;

    void setResult(const std::string& result);
    const std::string& getResult() const;

    void invokeOnResultSet(const std::function<void(const std::string&)>& action);

private:
    std::string m_result;
    std::function<void(const std::string&)> m_onResultSet {[](const std::string&) {}};

    inline static const std::string s_inputPrefix = "> ";
};

} // namespace fw

#endif // FW_INPUTMENUITEM_H
