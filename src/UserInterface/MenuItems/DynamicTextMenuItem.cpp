#include "DynamicTextMenuItem.h"

namespace fw
{

DynamicTextMenuItem::DynamicTextMenuItem(
    const std::function<std::string()>& textGenerator)
    : m_textGenerator(textGenerator)
{ }

const std::string& DynamicTextMenuItem::getText() const
{
    // Creating a static variable to make it possible to return a reference.
    static std::string text;

    text = m_textGenerator();

    return text;
}

} // namespace fw
