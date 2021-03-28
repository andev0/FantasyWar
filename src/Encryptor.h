#ifndef FW_ENCRYPTOR_H
#define FW_ENCRYPTOR_H

#include <string>

namespace fw
{
    class Encryptor
    {
    public:
        static std::string encode(std::string text);
        static std::string encode(char text[]);

        static std::string decode(std::string text);
        static std::string decode(char text[]);

        static void generateKey(std::string text);
        static void generateKey(char text[]);
    private:
        static long long encryptingKey;
    };
}

#endif // !FW_ENCRYPTOR_H
