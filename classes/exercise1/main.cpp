#include "point.h"
#include <cmath>

int main() {
    Point p1, p2;

    p1.set(1, 2);
    p2.write();

    p1.read();
    double x2 = p2.get_x();
    double y2 = p2.get_y();
    std::cout << "Point(" << x2 << ", " << y2 << ")" << std::endl;

    double dist = p1.distance(p2);
    std::cout << dist << std::endl;
    dist = p2.distance(p1);
    std::cout << dist << std::endl;

    return 0;
}
