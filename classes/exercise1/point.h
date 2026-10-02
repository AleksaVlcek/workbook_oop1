#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
    double x, y;

public:
    void set(double, double);

    double get_x() const {
        return x;
    }
    double get_y() const {
        return y;
    }

    double distance(Point&) const;

    void write();
    void read() const;
};

#endif // POINT_H
