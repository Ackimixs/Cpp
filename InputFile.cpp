#include <iostream>
#include "InputFile.h"

InputFile::InputFile(std::string name) {
    std::cout << "InputFile(std::string name) " << name << std::endl;

    flue = std::ifstream(name);
}

InputFile::~InputFile() {
    std::cout << "~InputFile()" << std::endl;
}

bool InputFile::getLine(std::string &line) {
    return (bool) std::getline(flue, line);
}