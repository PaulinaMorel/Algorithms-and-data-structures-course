#include <iostream>
#include <vector>

double oblicz(std::vector<double> a, double x) {
    double wynik = a.back();
    for (int i = a.size() - 2; i >= 0; i--) {
        wynik = wynik * x + a[i];
    }
    return wynik;
}

int main() {
    std::cout << oblicz({ 4, 5, 3, 0, 0, 18 }, 10) << std::endl; // 185004
    return 0;
}