#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <map>

class IniReader {
    private:
    std::string fileName {};
    std::map<std::string, std::string> contents {};
    std::vector<std::string> iniContents {};
    std::ifstream iniFile {};
    bool parseIni();
    bool readIni();
    void printContents();
    public:
    IniReader(std::string fileName) noexcept(false);
    ~IniReader();
};