#ifndef FW_INPUTMENUITEM_H
#define FW_INPUTMENUITEM_H

#include "MenuItem.h"

namespace fw
{

class InputMenuItem : public MenuItem
{
public:
    const std::string& getText() const override;

    void setResult(const std::string& result);
    const std::string& getResult() const;

private:
    std::string m_result;
};

} // namespace fw

#endif // FW_INPUTMENUITEM_H
