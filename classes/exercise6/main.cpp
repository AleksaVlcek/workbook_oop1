#include "cuboid.h"
#include <iostream>

struct Node {
    Cuboid *cub;
    Node *next;
    Node(Cuboid *c) : cub(c), next(nullptr) {};
    ~Node() {delete cub;}
};

int main() {
    double vm;
    std::cin >> vm;

    Cuboid::set_vmax(vm);

    for (char still = 'y'; still == 'y' || still == 'Y'; std::cin >> still) {
        Node *head = nullptr, *tail = nullptr;

        while (true) {
            if (Cuboid *c = Cuboid::read()) {
                tail = (!head ? head : tail->next) = new Node(c);
            }
            else break;
        }

        for (Node *p = head; p; p = p->next) std::cout << p->cub->volume() << ' ';
        std::cout << std::endl << Cuboid::get_tvol() << std::endl;

        while (head) {
            Node *p = head;
            head = head->next;
            delete p;
        }
        std::cout << Cuboid::get_tvol() << std::endl;
    }    

    return 0;
}
