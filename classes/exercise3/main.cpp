#include "queue.h"
#include <iostream>

int main() {
    Queue q(3);

    q.insert(1).insert(2).insert(3);
    q.print();

    q.insert(4);
    std::cout << "full: " << q.isFull() << std::endl;

    std::cout << q.remove() << std::endl;
    q.insert(4);
    q.print();

    Queue copy(q);
    copy.remove();
    q.print();
    copy.print();

    while (!q.isEmpty()) {
        std::cout << q.remove() << ' ';
    }
    std::cout << std::endl;
    q.remove();

    copy.clear();
    std::cout << "empty: " << copy.isEmpty() << std::endl;

    return 0;
}
