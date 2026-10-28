#include "bucket.h"
#include <iostream>

Bucket &Bucket::operator+=(double v) {
	vol = vol + v <= getV() ? vol = v : getV();
	return *this;
}


Bucket &Bucket::operator-=(double v) {
	vol = vol - v >= 0 ? vol - v : 0;
	return *this;
}

Bucket &Bucket::operator=(Bucket &b) {
	if (this != &b) {
		double fs = freeSpace();
		if (fs >= b.vol) {vol += b.vol; b.vol = 0;}
		else {vol = getV(); b.vol -= fs;}
	}
	return *this;
}

std::ostream &operator<<(std::ostream &it, const Bucket &b) {
	return it << static_cast<const Cylinder&>(b) << ' ' << b.vol;
}

