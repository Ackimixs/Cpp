#ifndef TP10_INPUTFILE_H
#define TP10_INPUTFILE_H

#include <fstream>
#include <string>

class InputFile {
private:
    std::ifstream flue;

public:

    InputFile(std::string name);

    ~InputFile();

    bool getLine(std::string& line);
};


#endif //TP10_INPUTFILE_H
