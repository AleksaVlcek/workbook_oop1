#ifndef SHELF_H
#define SHELF_H

#include "books.h"

class Shelf {
private:
    int cap, num;
    const Book **books;
public:
    Shelf(int c = 10) : cap(c), num(0), books(new const Book*[cap]) {
        for (int i = 0; i < cap; i++) {
            books[i] = nullptr;
        }
    }
    Shelf(const Shelf &) = delete;

    ~Shelf() {
        for (int i = 0; i < num; i++) {
            delete books[i];
        }
        delete [] books;
    }

    Shelf &operator=(const Shelf&) = delete;
    bool operator+=(Book *b) {
        if (num == cap) return false;
        else {
            books[num++] = b;
            return true;
        }
    }
    const Book *operator-=(int pos) {
        if (pos < 0 || pos >= num) return nullptr;
        else {
            const Book *b = books[pos];
            if (!b) return nullptr;
            for (int i = pos + 1; i < num; i++) {
                books[i - 1] = books[i];
            }
            books[--num] = nullptr;
            return b;
        }
    }

    double totalValue() const {
        double val = 0;
        for (int i = 0; i < num; i++) {
            val += books[i]->value();
        }
        return val;
    }

    friend ostream &operator<<(ostream &out, const Shelf &s) {
        for (int i = 0; i < s.num; i++) {
            s.books[i]->write(out);
            out << endl;
        }
        return out;
    }
};

#endif // SHELF_H
