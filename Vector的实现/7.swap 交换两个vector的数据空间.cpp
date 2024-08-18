#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    std::cout << "交换前，a = " << a << ", b = " << b << std::endl;

    std::swap(a, b);

    std::cout << "交换后，a = " << a << ", b = " << b << std::endl;

    return 0;
}

//交换前，a = 10, b = 20
//交换后，a = 20, b = 10