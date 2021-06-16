#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <map>

class IniReader {
private:
    std::string globalName {};
    std::string fileName {};
    std::map<std::string, std::map<std::string, std::string>*> sectionContents {};
    std::vector<std::string> iniContents {};

    bool readIni();
    bool parseIni();
    void createSectionIfNotExist(std::string section);

    std::string trimString(std::string string);
public:
    IniReader(std::string fileName, std::string nameForGlobal = "__global__");
    ~IniReader();

    std::map<std::string, std::string>* getSection();
    std::map<std::string, std::string>* getSection(std::string section);

    std::string getContentData();
    std::string getSectionData();
};