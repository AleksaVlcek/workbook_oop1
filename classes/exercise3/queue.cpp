#include "queue.h"
#include <iostream>

Queue &Queue::insert(unsigned val) {
    if (len == cap) {
        std::cout << "Overflow" << std::endl;
        return *this;
    }

    data[rear] = val;
    rear = (rear + 1) % cap;
    len++;

    return *this;
}

long Queue::remove() {
    if (len == 0) {
        std::cout << "Empty" << std::endl;
        return -1;
    }

    long val = data[front];
    front = (front + 1) % cap;
    len--;
    if (!len) {front = rear = 0;}

    return val;
}

void Queue::print() const {
    for (unsigned i = 0; i < len; i++) {
        std::cout << data[(front + i) % cap] << ' ';
    }
    std::cout << std::endl;
}
