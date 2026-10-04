#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
    double a, b, c;
public:
    static bool is_valid(double a, double b, double c) {
        return a > 0 && b > 0 && c > 0 && a < b + c && b < a + c && c < a + b;
    }

    Triangle(double x = 1, double y = 1, double z = 1) : a(x), b(y), c(z) {}

    double get_a() const {return a;}
    double get_b() const {return b;}
    double get_c() const {return c;}

    double perimeter() const;
    double area() const;

    void print() const;
    bool read();
};

#endif // TRIANGLE
