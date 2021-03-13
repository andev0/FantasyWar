#include "Encryptor.h"

long long fw::Encryptor::encryptingKey = 256'128'303'404;

std::string fw::Encryptor::encode(std::string text)
{
	for (char& symbol : text)
	{
		symbol += 11;
		symbol ^= encryptingKey;
	}

	return text;
}
std::string fw::Encryptor::encode(char text[])
{
	return encode(std::string(text));
}

std::string fw::Encryptor::decode(std::string text)
{
	for (char& symbol : text)
	{
		symbol ^= encryptingKey;
		symbol -= 11;
	}

	return text;
}
std::string fw::Encryptor::decode(char text[])
{
	return encode(std::string(text));
}

void fw::Encryptor::generateKey(std::string text)
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
void fw::Encryptor::generateKey(char text[])
{
	generateKey(std::string(text));
}
