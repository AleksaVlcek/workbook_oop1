#ifndef CASH_H
#define CASH_H

#include "payment.h"

class Cash : public Payment {
private:
    double discount;
public:
    Cash(int a, int d) : Payment(a), discount(d) {}

    double getAmount() const override {
        double r = Payment::getAmount() - discount;
        return r < 0 ? 0 : r;
    }

    const char *getType() const override {return "Cash";}

    ~Cash() override {}
};

#endif // CASH_H
