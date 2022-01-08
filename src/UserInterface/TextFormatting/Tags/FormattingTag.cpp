#include "precompiled.h"

#include "FormattingTag.h"

namespace fw
{
    FormattingTag::FormattingTag(const std::string& name, 
                                 const std::string& startingSequence) 
        : m_name(name)
        , m_startingSequence(startingSequence)
    {}
    
    std::string FormattingTag::getName() const
    {
        return m_name;
    }
    
    std::string FormattingTag::getStartingSequence() const
    {
        return m_startingSequence;
    }
}
