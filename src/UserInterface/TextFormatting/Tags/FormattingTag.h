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
        std::string m_name;

        std::string m_startingSequence;

    };
}

#endif //FW_FORMATTINGTAG_H
