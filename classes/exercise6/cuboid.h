#ifndef CUBOID_H
#define CUBOID_H

#include <iostream>

class Cuboid {
    double a, b, c;
    static inline double total_vol;
    static inline double max_vol;

    Cuboid(double x, double y, double z) : a(x), b(y), c(z) {}

public:
    Cuboid(const Cuboid&) = delete;

    static double get_vmax() {return max_vol;}
    static bool set_vmax(double vol) {
        if (vol < total_vol) return false;
        max_vol = vol;
        return true;
    }
    static double get_tvol() {return total_vol;}

    static Cuboid *create(double x, double y, double z) {
        double vol = x * y * z;
        if (x <= 0 || y <= 0 || z <= 0 || total_vol + vol > max_vol) return nullptr;
        total_vol += vol;
        return new Cuboid(x, y, z);
    }

    static Cuboid *read() {
        double x, y, z;
        std::cin >> x >> y >> z;
        return create(x, y, z);
    }

    ~Cuboid() {total_vol -= a * b * c;};

    double get_a() const {return a;}
    double get_b() const {return b;}
    double get_c() const {return c;}

    double volume() const {return a * b * c;}

    void print() const {
        std::cout << a << ' ' << b << ' ' << c << std::endl;
    }
};

#endif // CUBOID_H
