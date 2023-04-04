#include <iostream>


double pow_rec(double x, int n) {
    std::cout << "i" << std::endl;
    if (n == 0) {
        return 1.0;
        std::cout << "i" << std::endl;
    }
    double t = pow_rec(x, n / 2);
    if (n % 2 == 0) {
        return t * t;
    }
    else {
        return x * t * t;
    }
}
int pow_recursion(int x, int n) {
    std::cout << "i" << std::endl;
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return pow_recursion(x * x, n / 2);

    else
        return x * pow_recursion(x * x, (n - 1) / 2);

}
int main()
{
    int x = 2;
    int n = 4;
    std::cout << pow_rec(x, n) << std::endl;
    std::cout << pow_recursion(x, n) << std::endl;
}