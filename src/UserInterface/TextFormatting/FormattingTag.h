#ifndef FW_FORMATTINGTAG_H
#define FW_FORMATTINGTAG_H

#include <string>

namespace fw
{
    class FormattingTag
    {
    public:
        FormattingTag(const std::string& name, 
                      const std::string& startingSequence, 
                      const std::string& endingSequence);

        std::string getName() const;

        std::string getStartingSequence() const;
        std::string getEndingSequence() const;

    private:
        std::string _name;

        std::string _startingSequence;
        std::string _endingSequence;

    };
}

#endif //FW_FORMATTINGTAG_H