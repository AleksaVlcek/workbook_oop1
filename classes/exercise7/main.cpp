#include "circle.h"
#include <iostream>

int main() {
    char more;

    do {
        Circle *circles[100];
        int n = 0;

        while (true) {
            double r;
            std::cin >> r;
            if (r <= 0) break;

            double x, y;
            std::cin >> x >> y;

            if (Circle::isValid(r, x, y)) {
                circles[n++] = new Circle(r, x, y);
            } else {
                std::cout << "*** Cannot be placed! ***\n";
            }
        }

        Circle::prinAll();

        for (int i = 0; i < n; delete circles[i++]);

        std::cin >> more;
    } while (more != 'N' && more != 'n');

    return 0;
}
