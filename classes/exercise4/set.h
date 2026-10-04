#ifndef SET_H
#define SET_H

#include <iostream>

class Set {
    int len;
    double *arr;

public:
    Set() : len(0), arr(nullptr) {}
    Set(double num) : len(1), arr(new double[len]) {
        arr[0] = num;
    }
    Set(const Set&);
    Set(Set&& s) : len(s.len), arr(s.arr) {s.len = 0; s.arr = nullptr;}

    ~Set() {delete [] arr; len = 0; arr = nullptr;}

    void uni(const Set&, const Set&);
    void intersection(const Set&, const Set&);
    void diff(const Set&, const Set&);

    void print() const {
        for (int i = 0; i < len; i++) {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;
    };

    void read() {
        int n;
        double num;

        delete [] arr;
        arr = nullptr;
        len = 0;

        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> num;
            this->uni(*this, num);
        }
    }

    int size() const {return len;}
};

#endif // SET_H
