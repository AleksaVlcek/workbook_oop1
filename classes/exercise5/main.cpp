#include "triangle.h"
#include <iostream>
#include <vector>

int main() {
    int len;
    std::cin >> len;

    Triangle *arr = new Triangle[len];
    std::vector<double> a(len, 0.0);
    for (int i = 0; i < len; i++) {
        while (!arr[i].read()) {}
        a[i] = arr[i].area();
    }

    for (int i = 0; i < len; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;

    delete [] arr;

    return 0;
}
