#ifndef FW_FILE_H
#define FW_FILE_H

#include <string>
#include <vector>
#include <fstream>

namespace fw
{
	class File
	{
	public:
		enum class WriteMode
		{
			RewriteFile,
			WriteToEnd
		};

		static void write(std::string filePath, std::vector<std::string> strings, 
						  WriteMode writeMode = WriteMode::WriteToEnd);
		
		static std::vector<std::string> readLines(std::string filePath);
	};
}

#endif // !FW_FILE_H
