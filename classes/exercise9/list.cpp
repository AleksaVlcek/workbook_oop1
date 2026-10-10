#include "list.h"
#include <iostream>

void List::append(int n) {
    Node *p = endOfList();
    if (!p) {
        head = new Node(n);
    }
    else {
        p->next = new Node(n);
    }
}

List::List(const List &lst) : head(nullptr) {
    for (Node *p = lst.head; p; p = p->next) {
        append(p->num);
    }
}

void List::clear() {
    Node *p;
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }
}

List::~List() {
    clear();
}

int List::len() const {
    int cnt = 0;
    Node *p = head;
    while (p) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

void List::print() const {
    Node *p = head;
    while (p) {
        std::cout << p->num << ' ';
        p = p->next;
    }
    std::cout << std::endl;
}

void List::add(int n) {
    Node *p = new Node(n, head);
    head = p;
}

void List::insert(int n) {
    Node *p = head, *q = nullptr;

    while (p && n > p->num) {
        q = p;
        p = p->next;
    }

    Node *r = new Node(n, p);
    if (q) q->next = r;
    else head = r;
}

void List::readRight(int size) {
    clear();
    int num;
    for (int i = 0; i < size; i++) {
        std::cin >> num;
        add(num);
    }
}

void List::readLeft(int size) {
    clear();
    int num;
    for (int i = 0; i < size; i++) {
        std::cin >> num;
        append(num);
    }
}

void List::clean(int n) {
    Node *p = head, *q = nullptr, *temp;

    while (p) {
        if (p->num == n) {
            temp = p;
            p = p->next;
            if (q) q->next = p;
            else head = p;
            delete temp;
        }
        else {
            q = p;
            p = p->next;
        }
    }
}
