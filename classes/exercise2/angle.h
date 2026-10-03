#ifndef ANGLE_H
#define ANGLE_H

#include <iostream>

const double FACTOR = 3.14159265358979323846 / 180.0;

class Angle {
    double radians;
public:
    Angle(double radians = 0.0) : radians(radians) {}
    Angle(int deg, int min = 0, int sec = 0) {
        radians = (deg + min / 60.0 + sec / 3600.0) * FACTOR;
    }

    double get() const {return radians;}
    int deg() const {return static_cast<int>(radians / FACTOR);}
    int min() const {return static_cast<int>((radians / FACTOR - deg()) * 60);}
    int sec() const {return static_cast<int>(((radians / FACTOR - deg()) * 60 - min()) * 60);}
    void divide(int &d, int &m, int &s) const {
        d = deg(); m = min(); s = sec();
    }

    Angle &add(const Angle &a) {radians += a.radians; return *this;}
    Angle &multiply(double factor) {radians *= factor; return *this;}

    void read() {std::cin >> radians;}
    void readDeg() {
        int d, m, s;
        std::cin >> d >> m >> s;
        *this = Angle(d, m, s);
    }

    void print() const {std::cout << radians << std::endl;}
    void printDeg() const {
        int d, m, s;
        divide(d, m , s);
        std::cout << "(" << d << ", " << m << ", " << s << ")" << std::endl;
    }
};

#endif // ANGLE_H
