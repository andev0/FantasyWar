#include "File.h"

void fw::File::write(std::string filePath, std::vector<std::string> strings, WriteMode writeMode)
{
    std::ios_base::openmode openmode = std::ios_base::app;
    if (writeMode == WriteMode::WriteToEnd)
    {
        openmode = std::ios_base::app;
    }
    else if (writeMode == WriteMode::RewriteFile)
    {
        openmode = std::ios_base::trunc;
    }

    std::ofstream fileOut(filePath, openmode);

    if (fileOut.is_open())
    {
        for (std::string& line : strings)
        {
            fileOut << line << "\n";
        }
    }

    fileOut.close();
}

std::vector<std::string> fw::File::readLines(std::string filePath)
{
    std::vector<std::string> fileContent;

    std::ifstream fileIn(filePath);

    if (fileIn.is_open())
    {
        std::string line;

        getline(fileIn, line);

        fileContent.push_back(line);
    }

    fileIn.close();

    return fileContent;
}
