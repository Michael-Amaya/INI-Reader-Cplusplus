#include <iostream>
#include <IniReader/ini_reader.h>

int main (int argc, char **argv) {
    std::cout << "Hello World!" << std::endl;
    IniReader reader {"Hello.txt"};
    return 0;
}