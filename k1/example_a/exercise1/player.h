#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
using namespace std;

class Player {
private:
    string name;
    unsigned int rank;
public:
    Player(string n, int r) : name(n), rank(r) {}

    string getName() const {return name;}
    unsigned int getRank() const {return rank;}

    void setRank(unsigned int r) {
        rank = r;
    }

    void write() const {
        cout << rank << ". " << name;
    }
};

#endif // PLAYER_H
