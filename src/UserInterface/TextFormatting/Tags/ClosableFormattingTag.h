#ifndef FW_CLOSABLEFORMATTINGTAG_H
#define FW_CLOSABLEFORMATTINGTAG_H

#include "precompiled.h"

#include "FormattingTag.h"

namespace fw
{
    class ClosableFormattingTag : public FormattingTag
    {
    public:
        ClosableFormattingTag(const std::string& name, 
                              const std::string& startingSequence, 
                              const std::string& endingSequence);

        std::string getEndingSequence() const;

    private:
        std::string _endingSequence;

    };
}

#endif //FW_CLOSABLEFORMATTINGTAG_H
