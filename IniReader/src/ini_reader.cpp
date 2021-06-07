#include <iostream>
#include <IniReader/ini_reader.h>

IniReader::IniReader(std::string file) : fileName{file} {
    // Check if the file exists, throw if it doesn't
    iniFile.open(fileName);
    if (!iniFile.is_open())
        throw std::runtime_error(fileName + " does not exist");

    // Read the contents and close the file
    readIni();
    iniFile.close();

    // Parse the data to populate the contents map
    parseIni();

    // Print the contents of the iniContents vector which
    // just contains each line
}

IniReader::~IniReader(){
    // delete contents;
}

void IniReader::printContents() {
    for (auto i = iniContents.begin(); i != iniContents.end(); ++i) {
        std::cout << *i << '\n';
    }
}

bool IniReader::parseIni() {

    return true;
}

bool IniReader::readIni() {
    std::string line {}; 
    while (std::getline(iniFile, line)) {
        iniContents.push_back(line);
    }

    return true;
}