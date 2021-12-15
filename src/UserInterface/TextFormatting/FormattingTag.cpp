#include "FormattingTag.h"

namespace fw
{
    FormattingTag::FormattingTag(const std::string& name, 
                                 const std::string& startingSequence, 
                                 const std::string& endingSequence) 
        : _name(name)
        , _startingSequence(startingSequence)
        , _endingSequence(endingSequence)
    {}
    
    std::string FormattingTag::getName() const
    {
        return _name;
    }
    
    std::string FormattingTag::getStartingSequence() const
    {
        return _startingSequence;
    }
    
    std::string FormattingTag::getEndingSequence() const
    {
        return _endingSequence;
    }
}