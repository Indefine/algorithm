#pragma GCC diagnostic error "-std=c++11" 
#include <iostream>

int fibonacci(int);

int main() {
    int n;
    std::cout << " please enter as you want fibonacci " << std::endl;
    std::cin >> n;
    std::cout << std::endl;
    std::cout << fibonacci(n) << std::endl;
    return 0;
}

int fibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}
