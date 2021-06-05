#include <iostream>
#include <IniReader/ini_reader.h>

IniReader::IniReader(std::string file) : fileName{file} {
    iniFile.open(fileName);
    if (!iniFile.is_open())
        throw std::runtime_error(fileName + " does not exist");

    // Do operations 
    iniFile.close();
}

IniReader::~IniReader(){
    delete contents;
}