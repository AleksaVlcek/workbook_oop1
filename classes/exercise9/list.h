#ifndef LIST_H
#define LIST_H

class List {
    struct Node {
        int num;
        Node *next;
        Node(int n, Node *p = nullptr) : num(n), next(p) {}
    };
    Node *head;

    Node *endOfList() {
        if (!head) return nullptr;
        Node *p = head;
        while (p->next) {
            p = p->next;
        }
        return p;
    }

public:
    List() : head(nullptr) {}
    List(int n) : head(new Node(n)) {}
    List(const List&);
    List(List &&first) : head(first.head) {first.head = nullptr;}

    ~List();

    int len() const;
    void print() const;

    void add(int);
    void append(int);
    void insert(int);

    void readRight(int);
    void readLeft(int);

    void clear();
    void clean(int);
};

#endif // LIST_H
