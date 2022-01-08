#ifndef FW_FORMATTINGTAG_H
#define FW_FORMATTINGTAG_H

namespace fw
{
    class FormattingTag
    {
    public:
        FormattingTag(const std::string& name, 
                      const std::string& startingSequence);

        std::string getName() const;

        std::string getStartingSequence() const;

    private:
        std::string _name;

        std::string _startingSequence;

    };
}

#endif //FW_FORMATTINGTAG_H
