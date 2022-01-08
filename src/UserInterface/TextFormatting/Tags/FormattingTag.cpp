#include "precompiled.h"

#include "FormattingTag.h"

namespace fw
{
    FormattingTag::FormattingTag(const std::string& name, 
                                 const std::string& startingSequence) 
        : _name(name)
        , _startingSequence(startingSequence)
    {}
    
    std::string FormattingTag::getName() const
    {
        return _name;
    }
    
    std::string FormattingTag::getStartingSequence() const
    {
        return _startingSequence;
    }
}
