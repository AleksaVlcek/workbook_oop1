#ifndef PAYMENT_H
#define PAYMENT_H

class Payment {
private:
    static inline int num = 0;
    int id;
    double amount;
public:
    Payment(int a) : id(num + 1), amount(a) {num++;}

    int getId() const {return id;}
    virtual double getAmount() const {return amount;}

    virtual const char *getType() const = 0;

    virtual ~Payment() {};
};

#endif // PAYMENT_H
