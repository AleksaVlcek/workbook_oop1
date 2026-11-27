#ifndef SYSTEM_H
#define SYSTEM_H

#include "card.h"
#include "cash.h"
#include <iostream>

static constexpr int SIZE = 10;

class System {
private:
    Payment **s;
    int len;
public:
    System() : s(new Payment*[SIZE]), len(0) {}
    System(const System &) = delete;

    bool add(Payment *p) {
        if (len == SIZE) return false;
        else {
            s[len++] = p;
            return true;
        }
    }

    void print() const {
        for (int i = 0; i < len; i++) {
            std::cout << s[i]->getId() << ' ' << s[i]->getType() << ' ' << s[i]->getAmount() << std::endl;
        }
    }

    ~System() {
        for (int i = 0; i < len; i++) {
            delete s[i];
        }
        delete [] s;
    }
};

#endif // SYSTEM_H
