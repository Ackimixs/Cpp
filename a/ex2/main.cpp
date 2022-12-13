#include <iostream>

int main() {
    auto n;
    std::cin >> n;

    if (n > 0) {
        int* tab = new int[n];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> tab[i];
        std::cout << " ";
    }

    //moyenne : you can do an external function
    int average = 0;
    for (int i = 0; i < n; i++) {
        average += tab[i];
    }
    average /= n;
    std::cout << "Moyenne : " << average << std::endl;

    delete[] tab;
}