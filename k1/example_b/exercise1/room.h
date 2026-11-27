#ifndef ROOM_H
#define ROOM_H

#include <iostream>
using namespace std;

class Room {
private:
    int num, price;
public:
    Room(int n, int p) : num(n), price(p) {}

    int getNum() const {return num;}
    int getPrice() const {return price;}

    void setPrice(int p) {price = p;}

    void print() const {
        cout << "Room " << num << " - " << price << " RSD" << endl;
    }
};

#endif // ROOM_H
