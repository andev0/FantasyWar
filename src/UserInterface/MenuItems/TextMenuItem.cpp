#include "TextMenuItem.h"

namespace fw
{

TextMenuItem::TextMenuItem(const std::string& text)
    : m_text(text)
{ }

const std::string& TextMenuItem::getText() const
{
    return m_text;
}

} // namespace fw
