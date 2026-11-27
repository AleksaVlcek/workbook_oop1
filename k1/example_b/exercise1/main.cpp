#include "reservation.h"

int main() {
    Room *r = new Room(4, 150);
    Reservation *res = new Reservation(r, 6);

    res->print();

    r->setPrice(200);
    res->setNights(10);

    res->print();

    delete res;
    delete r;

    return 0;
}