#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    unsigned cap;
    unsigned len;
    unsigned *data;
    unsigned front;
    unsigned rear;

public:
    Queue(unsigned c = 10) : cap(c), len(0), data(new unsigned[c]), front(0), rear(0) {}
    Queue(const Queue &q) : cap(q.cap), len(q.len), data(new unsigned[q.cap]), front(q.front), rear(q.rear) {
        for (unsigned i = 0; i < len; i++) {
            data[(q.front + i) % cap] = q.data[(q.front + i) % cap];
        }
    }
    Queue(Queue &&q) : cap(q.cap), len(q.len), data(q.data), front(q.front), rear(q.rear) {
        q.cap = q.len = 0;
        q.data = nullptr;
    }

    ~Queue() {delete[] data;}

    Queue &insert(unsigned);
    long remove();

    bool isEmpty() const {return len == 0;}
    bool isFull() const {return len == cap;}

    void print() const;

    void clear() {len = front = rear = 0;}
};

#endif // QUEUE_H
