#include "match.h"

int main() {
    Player *p1 = new Player("Novak Djokovic", 5);
    Player *p2 = new Player("Roger Federer", 3);

    Match *m = new Match(p1, p2);
    m->write();
    cout << endl;

    p1->setRank(1);
    m->write();
    cout << endl;

    delete m;
    delete p1;
    delete p2;

    return 0;
}