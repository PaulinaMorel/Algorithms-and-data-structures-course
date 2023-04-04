#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return sin(x); // przykładowa funkcja
}

double bisection(double a, double b) {
    if (f(a) * f(b) >= 0) {
        cout << "Nie można znaleźć miejsca zerowego na tym przedziale." << endl;
        return -1.0;
    }

    double c = a;
    while ((b - a) >= 1e-6) { // dokładność wyniku
        c = (a + b) / 2.0;

        if (f(c) == 0.0) {
            break;
        }
        else if (f(c) * f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    return c;
}

int main() {
    double a = 0.0; // początek przedziału
    double b = 1.0; // koniec przedziału
    double c = bisection(a, b);

    if (c != -1.0) {
        cout << "Miejsce zerowe wynosi: " << c << endl;
    }

    return 0;
}