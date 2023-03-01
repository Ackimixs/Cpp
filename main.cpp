#include <iostream>
#include <vector>
#include <map>
#include <cctype>

#include <algorithm>
#include <numeric>

#define boolToString(b) (b ? "true" : "false")

template<typename T> void printVector(std::vector<T> v) {
    std::cout << '[';
    for (auto i = v.begin(); i != v.end(); i++) {
        if (i == v.end()-1) {
            std::cout << *i;
        } else {
            std::cout << *i << ",";
        }
    }
    std::cout << ']' << std::endl;
}

void printNumber() {
    std::vector<int> v = {1, 2, 3, 4, 4 , 5, 6, 5, 1};
    printVector(v);
}

void printLetters() {
    std::vector<char> t = {'A', 'B', 'C'};
    printVector(t);
}

void printVectorTest() {
    printNumber();
    printLetters();
}

bool isNumber(std::string str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

void isNumberTests(){
    std::cout << boolToString( isNumber("1") )<< std::endl;
    std::cout << boolToString( isNumber("42") ) << std::endl;
    std::cout << boolToString( isNumber("6PO") ) << std::endl;
    std::cout << boolToString( isNumber("R2D2") ) << std::endl;
}

void keepNumbersOnly(std::vector<std::string>& s) {
    for (auto i = s.begin(); i != s.end(); i++) {
        if (isNumber(*i)) {
            s.erase(i);
            i--;
        }
    }
}

void filterVectorTest(){
    std::vector<std::string> values = {"Z", "1", "A", "42", "E", "G", "0"};
    keepNumbersOnly(values);
    printVector(values);
}

std::vector<std::string> splitString(std::string s, char c = ' ') {
/*
    // Test1
    char i = c[0];

    std::vector<std::string> res;

    std::string temp = "";
    for (auto ch: s) {
        if (ch == i) {
            res.push_back(temp);
            temp.clear();
        } else {
            temp.push_back(ch);
        }
    }

    return res;
*/
    std::vector<std::string> res;
    if (s.find(c) == std::string::npos) return {s};

    while (s.find(c) != std::string::npos) {
        res.push_back(s.substr(0, s.find(c)));
        s = s.substr(s.find(c) + 1);
    }
    return res;
}

void splitTests(){
    std::vector<std::string> operators = splitString("+ - / =");
    printVector(operators);
    std::vector<std::string> numbers = splitString("1,2,3,4,5", ',');
    printVector(numbers);
    std::vector<std::string> letters = splitString("A-B-C-D", '-');
    printVector(letters);
}

template<typename T, typename U> void printMap(std::map<T, U> map) {
    for (const auto& m : map) {
        std::cout << m.first << "->" << m.second << std::endl;
    }
}

void printAges(){
    std::map</*name*/std::string, /*age*/unsigned short> ages = {
        { "Emma", 30 },
        { "Manon", 19 },
        { "Sacha", 45 }
    };
    printMap(ages);
}

void printRights(){
    std::map</*userId*/int, /*rights*/int> userRights = {
        { 254756, 666 },
        { 4587, 644 },
        { 58714, 777 }
    };
    printMap(userRights);
}

void printMapTests(){
    printAges();
    std::cout << "---" << std::endl;
    printRights();
}

void keepMalesOnly(std::map<std::string, bool>& map) {
    for (auto m = map.begin(); m != map.end();) {
        if (!m->second) {
            m = map.erase(m);
        } else {
            m++;
        }
    }
}

void filterMapTest() {
    std::map</*name*/std::string, /*male*/bool> genders = {
            {"Emma",  false},
            {"Manon", false},
            {"Sacha", true},
            {"Ambre", false},
            {"Gabin", true},
            {"Paul",  true}
    };
     keepMalesOnly(genders);
     printMap(genders);
}

void splitOnGender(std::map<std::string, bool> map, std::vector<std::string> &males, std::vector<std::string> &females) {
    for (auto &m : map) {
        if (m.second) {
            males.push_back(m.first);
        } else {
            females.push_back(m.first);
        }
    }
}

void splitMapTest() {
    std::map</*name*/std::string, /*male*/bool> genders = {
            {"Emma",  false},
            {"Manon", false},
            {"Sacha", true},
            {"Ambre", false},
            {"Gabin", true},
            {"Paul",  true}
    };
    std::vector <std::string> males;
    std::vector <std::string> females;
    splitOnGender(genders, males, females);
    printMap(genders);
    std::cout << "---" << std::endl;
    printVector(males);
    printVector(females);
}

/*std::map<std::string, float> computeStatistics(std::vector<int>& values) {
    int max = values[0], min = values[0], avg = 0;

    for (auto value : values) {
        if (value > max) {
            max = value;
        } else if (value < min) {
            min = value;
        }
        avg += value;
    }

    return {{"average", avg / values.size()}, {"max", max}, {"min", min}};
}*/

std::map<std::string, float> computeStatistics(std::vector<int>& values) {
    return {
        {"average", std::accumulate(values.begin(), values.end(), 0) / values.size()},
        {"max", *std::max_element(values.begin(), values.end())},
        {"min", *std::min_element(values.begin(), values.end())}
    };
}

void statsTest() {
    std::vector<int> values = {1, 42, -3, 6, 12, 404};
    std::map<std::string, float> statistics = computeStatistics(values);
    printMap(statistics);
}

int main() {

    // printVectorTest();

    // isNumberTests();

    // filterVectorTest();

    splitTests();

    // printAges();

    // printMapTests();

    // filterMapTest();

    // splitMapTest();

    // statsTest();

    return 0;
}