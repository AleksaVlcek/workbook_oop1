#include "set.h"
#include <iostream>

int main() {
    char still;

    do {
        Set s1, s2;
        s1.read(); s2.read();

        s1.print(); s2.print();

        Set s;
        s.uni(s1, s2); s.print();
        s.intersection(s1, s2); s.print();
        s.diff(s1, s2); s.print();

        std::cin >> still;

    } while (still == 'y' || still == 'Y');

    return 0;
}
