#include "ClosableFormattingTag.h"

namespace fw
{
    ClosableFormattingTag::ClosableFormattingTag(const std::string& name, 
                                                 const std::string& startingSequence, 
                                                 const std::string& endingSequence) 
        : FormattingTag(name, startingSequence)
        , _endingSequence(endingSequence)
    {
        
    }
    
    std::string ClosableFormattingTag::getEndingSequence() const
    {
        return _endingSequence;
    }
}