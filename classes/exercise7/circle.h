#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"
#include <cstdlib>

class Circle {
    Point c;
    double r;
    Circle *next, *prev;
    static inline Circle *head = nullptr;

    Circle() : r(-1) {};
    Circle(const Circle&) = delete;

public:
    static bool isValid(double, double, double);

    Circle(double, double, double);
    ~Circle();

    friend double distance(const Circle&, const Circle&);
    bool move(double, double);
    bool trans(double, double);

    void print() const;
    static void prinAll();
};

#endif // CIRCLE_H
