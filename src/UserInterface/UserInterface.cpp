#include "precompiled.h"

#include "UserInterface.h"

namespace fw
{
    UserInterface::UserInterface(TextFormatter* textFormatter) 
        : _textFormatter(textFormatter)
    {
        
    }
    
    void UserInterface::addTextToQueue(const std::string& text) 
    {
        _textQueue.push_back(text);
    }
    
    void UserInterface::displayQueuedText() 
    {
        for (std::string& text : _textQueue)
        {
            displayText(text);
        }

        _textQueue.clear();
    }

    UserInterface::~UserInterface()
    {
        delete _textFormatter;
    }
}
