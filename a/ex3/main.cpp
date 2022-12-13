#include <iostream>

int max(int a, int b = 0, int c = 0);

int main() {
    std::cout << max(1, 2, 3) << std::endl;
    std::cout << max(1, 2) << std::endl;
    std::cout << max(1) << std::endl;
}

int max(int a, int b, int c) {
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}