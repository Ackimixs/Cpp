#include <iostream>

void swap(int& a, int& b);
void swap(int* a, int* b);

int main() {
    int a = 1;
    int b = 2;
    swap(a, b);
    std::cout << a << " " << b << std::endl;
    swap(&a, &b);
    std::cout << a << " " << b << std::endl;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}