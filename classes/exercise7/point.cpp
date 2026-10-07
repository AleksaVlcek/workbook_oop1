#include "point.h"
#include <cmath>

void Point::set(double a, double b) {
    this->x = a;
    this->y = b;
}

double Point::distance(const Point &p) const {
    double dx = x - p.get_x();
    double dy = y - p.get_y();
    return std::sqrt(dx * dx + dy * dy);
}

void Point::write() {
    std::cin >> x >> y;
}

void Point::read() const {
    std::cout << "Point(" << x << ", " << y << ")" << std::endl;
}
