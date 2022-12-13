#include <iostream>
int main() {

    int val1, val2;
    std::cout << "val1" << std::endl;
    std::cin >> val1;

    std::cout << "val2" << std::endl;
    std::cin >> val2;

    std::cout << "Positif ? " << std::boolalpha << (val1 > val2) << std::endl;
}