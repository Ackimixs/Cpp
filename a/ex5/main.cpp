#include <iostream>

void sum(int n, int& s, int k = 0);

int main() {
    int s = 0;
    sum(10, s, 3);
    std::cout << s << std::endl;
}

void sum(int n, int& s, int k) {
    if (k < n) {
        s = 0;
        for (int i = k; i < n; i++) {
            s += i;
        }
    }
}