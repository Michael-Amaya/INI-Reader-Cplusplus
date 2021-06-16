#include <string>
#include <fstream>
#include <vector>
#include <map> 

#include <IniReader/ini_reader.h>

IniReader::IniReader(std::string file, std::string nameForGlobal)
    : globalName{nameForGlobal}, fileName{file} {

    readIni();

    // Before parsing the INI, create the global section
    // for key,value pairs that don't have a section.
    // Named it __global__ because it's not common
    createSectionIfNotExist(globalName);

    // Parse the data to populate the contents map
    parseIni();
}

IniReader::~IniReader(){
    // Iterate through maps and delete every section. 
    for (auto sectionMap = sectionContents.begin();
        sectionMap != sectionContents.end();
        ++sectionMap) 
    {
        delete sectionMap->second;
    }
}

bool IniReader::readIni() {
    std::ifstream iniFile;
    
    // Check if the file exists, throw if it doesn't
    iniFile.open(fileName);
    if (!iniFile.is_open())
        throw std::runtime_error(fileName + " does not exist");

    std::string line {}; 
    while (std::getline(iniFile, line)) {
        iniContents.push_back(line);
    }

    iniFile.close();
    return true;
}

bool IniReader::parseIni() {
    // If there are no sections, everything goes in __global__
    std::string section {globalName};

    //for (std::string line : iniContents) {
    for (auto line = iniContents.begin(); line != iniContents.end(); ++line){
        // Ignore if blank line
        if (line->compare("") == 0)
            continue;
        
        std::string trimmedString = trimString(*line);

        // Ignore if it's a comment
        if (trimmedString.at(0) == '#' || trimmedString.at(0) == ';')
            continue;

        // Check if it's a section header
        if (trimmedString.at(0) == '[' ) {
            section = trimmedString.substr(1, trimmedString.length() - 2);
            continue;
        }

        size_t indexOfEqual = trimmedString.find('=');
        std::string keyValuePair[2];

        if (indexOfEqual == std::string::npos) {
            keyValuePair[0] = *line;
            keyValuePair[1] = "";
        } else {

            keyValuePair[0] = trimString(trimmedString.substr(0, indexOfEqual));
            keyValuePair[1] = trimString(trimmedString.substr(indexOfEqual + 1,
                                                    trimmedString.length() + 1));
        }

        createSectionIfNotExist(section);

        // Add to the section
        getSection(section)->insert({keyValuePair[0], keyValuePair[1]});
    }
    return true;
}

void IniReader::createSectionIfNotExist(std::string section) { 
    if (sectionContents.contains(section))
        return;

    std::map<std::string, std::string>* sectionMap = 
        new std::map<std::string, std::string> {};
    sectionContents.insert({section, sectionMap});
} 

std::map<std::string, std::string>* IniReader::getSection(std::string section) {
    return sectionContents.at(section);
}


std::string IniReader::getContents() {
    std::string sectionData {};

    for (auto i = iniContents.begin(); i != iniContents.end(); ++i) {
        sectionData += *i + '\n';
    }

    return sectionData;
}

std::string IniReader::getSections() {
    std::string sectionData {};

    for (auto sectionMap = sectionContents.begin();
        sectionMap != sectionContents.end();
        ++sectionMap)
    {
        sectionData += "Section: " + sectionMap->first + '\n';
        for (auto keyValueMap = sectionMap->second->begin();
            keyValueMap != sectionMap->second->end();
            keyValueMap++)
            sectionData += "- " 
                + keyValueMap->first + ":" 
                + keyValueMap->second + '\n';
        sectionData += '\n';
    }

    return sectionData;
}

std::string IniReader::trimString(std::string string) {
    std::string trimmedString {};
    
    size_t leftIndex {0};
    size_t rightIndex {0};

    // Check left
    for (size_t i = 0; i < string.length(); ++i) {
        if (string.at(i) != ' ') {
            leftIndex = i;
            break;
        }
    }

    // Check right
    for (size_t i = string.length() - 1; i != 0; --i) {
        if (string.at(i) != ' ') {
            rightIndex = i;
            break;
        }
    }

    trimmedString = string.substr(leftIndex, rightIndex + 1);
    return trimmedString;
}