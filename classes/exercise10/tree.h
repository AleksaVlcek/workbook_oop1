#ifndef TREE_H
#define TREE_H

class Tree {
private:
    struct Node {
        int num;
        Node *left, *right;
        Node(int n, Node *l = nullptr, Node *r = nullptr) : num(n), left(l), right(r) {}
    };
    Node *root;

public:
    Tree() : root(nullptr) {}
    Tree(int n) : root(new Node(n)) {}
    Tree(const Tree &t) : root(copy(t.root)) {}
    Tree(Tree&& t) : root(t.root) {
        t.root = nullptr;
    }

    ~Tree() {
        freeTree(root);
    }

    bool isEmpty() const {return root == nullptr;}
    int size() const {return treeSize(root);}
    int sum() const {return treeSum(root);}

    void prefix() const {treePrefix(root);}
    void infix() const {treeInfix(root);}
    void postfix() const {treePostfix(root);}
    void print() const {printTree(root, 0);}

    int count(int n) const {return countInstances(root, n);}
    int min() const {return treeMin(root);}
    int max() const {return treeMax(root);}
    Node *search(int) const;

    void add(int n) {treeAdd(root, n);}
    void read(int);
    void freeTree() {freeTree(root);}
    bool remove(int n) {return treeRemove(root, n);}

    void balance() {treeBalance(root);}

private:
    static Node *copy(Node *);
    static void freeTree(Node *&);

    static int treeSize(Node *);
    static int treeSum(Node *);

    static void treePrefix(Node *);
    static void treeInfix(Node *);
    static void treePostfix(Node *);
    static void printTree(Node *, int);

    static int countInstances(Node *, int);
    static int treeMin(Node *);
    static int treeMax(Node *);

    static void treeAdd(Node *&, int);
    static bool treeRemove(Node *&, int);
    static void treeBalance(Node *&);
};

#endif // TREE_H
