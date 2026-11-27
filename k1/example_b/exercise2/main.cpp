#include "system.h"

int main() {
    System *s = new System;

    s->add(new Card(100, 9));
    s->add(new Cash(200, 90));
    s->add(new Cash(58, 60));
    s->add(new Card(70, 5));
    s->add(new Cash(20, 15));

    s->print();

    delete s;

    return 0;
}
