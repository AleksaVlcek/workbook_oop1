#include "date.h"
#include <iostream>

int main() {
    Date d1 = Date::read();
    Date d2 = Date::read();

    d1.print();
    std::cout << d1.dayName() << ", " << d1.monthName() << std::endl;
    std::cout << d1.dayInYear() << ' ' << d1.lenMonth() << std::endl;

    std::cout << diff(d1, d2) << std::endl;

    d1.add(30);
    d1.print();
    d1.sub(60);
    d1.print();

    d2.tomorrow();
    d2.print();
    d2.yesterday();
    d2.yesterday();
    d2.print();

    return 0;
}
