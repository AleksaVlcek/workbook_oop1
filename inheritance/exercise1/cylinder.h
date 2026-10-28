#ifndef CYLINDER_H
#define CYLINDER_H

#include <iostream>

const double PI = 3.1415926535897932;

class Cylinder {
public:
	explicit Cylinder(double rr = 1, double hh = 1) : r(rr), h(hh) {}

	double getR() const {return r;}
	double getH() const {return h;}
	double getV() const {return r * r * PI * h;}

	friend std::ostream& operator<<(std::ostream &it, const Cylinder &c) {return it << c.r << ' ' << c.h;}
private:
	double r, h;
};

#endif // CYLINDER_H

