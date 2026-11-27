#ifndef CARD_H
#define CARD_H

#include "payment.h"

class Card : public Payment {
private:
    double fee;
public:
    Card(int a, int f) : Payment(a), fee(f) {}

    double getAmount() const override {return (1 + fee / 100) * Payment::getAmount();}

    const char *getType() const override {return "Card";}

    ~Card() override {};
};

#endif // CARD_H
