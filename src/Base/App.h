#ifndef FW_APP_H
#define FW_APP_H

namespace fw
{
    class App
    {
    public:
        virtual ~App();

        virtual void start() = 0;
        
    };
}

#endif //FW_APP_H
