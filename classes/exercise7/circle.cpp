#include "circle.h"
#include "point.h"

bool Circle::isValid(double rr, double x, double y) {
    Circle cir;
    cir.r = rr; cir.c.set(x, y);
    Circle *cur = head;

    while (cur && distance(cir, *cur) >= 0) {
        cur = cur->next;
    }
    cir.r = -1;
    return cur == nullptr;
}

Circle::Circle(double rr, double x, double y) {
    if (!isValid(rr, x, y)) exit(1);
    r = rr; c.set(x, y);
    next = head;
    prev = nullptr;
    if (head) head->prev = this;
    head = this;
}

Circle::~Circle() {
    if (r > 0) {
        Circle *p = next;
        if (p) p->prev = this->prev;
        if (this == head) {
            head = p;
        }
        else {
            prev->next = p;
        }
    }
}

inline double distance(const Circle &c1, const Circle &c2) {
    double dist = c1.c.distance(c2.c);
    return dist - c1.r - c2.r;
}

bool Circle::move(double x, double y) {
    if (!isValid(r, x, y)) {return false;}
    c.set(x, y);
    return true;
}

bool Circle::trans(double dx, double dy) {
    if (!isValid(r, c.get_x() + dx, c.get_y() + dy)) return false;
    c.set(c.get_x() + dx, c.get_y() + dy);
    return true;
}

void Circle::print() const {
    std::cout << r << ' ' << c.get_x() << ' ' << c.get_y() << std::endl;
}

 void Circle::prinAll() {
    for (Circle *p = head; p; p = p->next) {
        p->print();
    }
 }
