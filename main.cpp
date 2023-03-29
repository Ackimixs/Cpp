#include "NegativeDimensionException.h"
#include "InputFile.h"

void illegalArgumentExceptionTest(){
    try{
        Point p(-1, 42);
    }
    catch(IllegalArgumentException& iae){
        iae.print();
    }
}

/*void printContent(const std::string& fileName){
    InputFile file(fileName);
    std::string line;
    while( file.getLine(line) ){
        std::cout << line << std::endl;
    }
}*/

void printContent(const std::string& fileName){
    InputFile file(fileName);
    std::string line;
    throw 42;
    while( file.getLine(line) ){
        std::cout << line << std::endl;
    }
}

void printContentTest(){
    try{
        printContent("test.txt");
    }
    catch(...){
        std::cout << "Exception thrown" << std::endl;
    }
}



int main() {

    illegalArgumentExceptionTest();

    // printContentTest();

    return 0;
}
