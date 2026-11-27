#ifndef RESERVATION_H
#define RESERVATION_H

#include "room.h"

class Reservation {
private:
    Room *room;
    int nights;
public:
    Reservation(Room *r, int n) : room(r), nights(n) {}

    void setNights(int n) {nights = n;}
    int totalPrice() const {return nights * room->getPrice();}

    void print() const {
        cout << '(' << room->getNum() << ") " << nights << " - " << totalPrice() << " RSD" << endl;
    }
};

#endif // RESERVATION_H
