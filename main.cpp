#include <iostream>
#include <IniReader/ini_reader.h>

int main (int argc, char **argv) {
    IniReader reader {"test.ini"};
    std::cout << "RSA-Directory:" << reader.getSection("Random")->at("Rsa-Directory") << std::endl;
    return 0;
}