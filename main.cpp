#include <iostream>
#include <IniReader/ini_reader.h>

int main (int argc, char **argv) {
    IniReader reader {"test.ini"};
    std::cout << "Database Host: " << reader.getSection("Database")->at("Host") << std::endl;
    std::cout << "Database Username: " << reader.getSection("Database")->at("Username") << std::endl;
    std::cout << "Database Password: " << reader.getSection("Database")->at("Password") << std::endl;
    return 0;
}