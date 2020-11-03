#include "Encryptor.h"

long long Encryptor::encryptingKey = 256'128'303'404;

std::string Encryptor::encode(std::string text)
{
	for (char& symbol : text)
	{
		symbol += 11;
		symbol ^= encryptingKey;
	}

	return text;
}
std::string Encryptor::encode(char text[])
{
	encode(std::string(text));
}

std::string Encryptor::decode(std::string text)
{
	for (char& symbol : text)
	{
		symbol ^= encryptingKey;
		symbol -= 11;
	}

	return text;
}
std::string Encryptor::decode(char text[])
{
	encode(std::string(text));
}

void Encryptor::generateKey(std::string text)
{
	long long keyValue = 0;

	for (char& symbol : text)
	{
		keyValue += (int)symbol;
	}
	keyValue *= 111;
	keyValue -= 5;

	encryptingKey = keyValue;
}
void Encoder::generateKey(char text[])
{
	generateKey(std::string(text));
}
