#include "triangle.h"
#include <cmath>
#include <iostream>

double Triangle::perimeter() const {return a + b + c;}

double Triangle::area() const {
    double s = perimeter() / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle::print() const {
    std::cout << a << ' ' << b << ' ' << c << std::endl;
}

bool Triangle::read() {
    double x, y, z;
    std::cin >> x >> y >> z;
    if (!is_valid(x, y, z)) return false;
    a = x; b = y; c = z;
    return true;
}
