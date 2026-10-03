#include "angle.h"

int main() {
    Angle a(1.5);
    Angle b(45, 30, 15);

    a.print();
    a.printDeg();
    b.print();
    b.printDeg();

    int d, m, s;
    b.divide(d, m, s);
    std::cout << d << " " << m << " " << s << std::endl;

    Angle x(10, 20, 30);
    x.add(Angle(20, 10, 15)).multiply(2);
    x.printDeg();

    Angle c;
    c.readDeg();
    c.printDeg();

    return 0;
}
