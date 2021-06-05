#pragma once

#include <string>
#include <fstream>
#include <map>

class IniReader {
    private:
    std::string fileName;
    std::map<std::string, std::string> *contents;
    std::ifstream iniFile;
    public:
    IniReader(std::string fileName) noexcept(false);
    ~IniReader();
};

