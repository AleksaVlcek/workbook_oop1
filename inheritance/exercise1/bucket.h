#ifndef BUCKET_H
#define BUCKET_H

#include "cylinder.h"
#include <iostream>

class Bucket : public Cylinder {
public:
	explicit Bucket(double rr = 1, double hh = 1, double v = 0) : Cylinder(rr, hh), vol(v <= getV() ? v : getV()) {}

	double getVol() const {return vol;}
	double freeSpace() const {return getV() - vol;}

	bool isFull() const {return getV() == vol;}
	bool isEmpty() const {return vol == 0;}

	Bucket &operator+=(double);
	Bucket &operator-=(double);
	Bucket &operator=(Bucket &);

	friend std::ostream &operator<<(std::ostream &, const Bucket &);
private:
	double vol;
};

#endif // BUCKET_H

