#ifndef MATCH_H
#define MATCH_H

#include "player.h"

class Match {
private:
    Player *player1, *player2;
public:
    Match(Player *p1, Player *p2) : player1(p1), player2(p2) {}

    void write() {
        if (player1->getRank() > player2->getRank()) {
            player1->write();
            cout << endl;
            player2->write();
        }
        else {
            player2->write();
            cout << endl;
            player1->write();
        }
    }
};

#endif // MATCH_H
