#include "tree.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Tree::Node *Tree::copy(Node *p) {
    if (!p) return nullptr;
    Node *np = new Node(p->num);
    np->left = copy(p->left);
    np->right = copy(p->right);
    return np;
}


void Tree::freeTree(Node *&r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    delete r;
    r = nullptr;
}

int Tree::treeSize(Node *r) {
    if (!r) return 0;
    int n = 1;
    n += treeSize(r->left);
    n += treeSize(r->right);
    return n;
}

int Tree::treeSum(Node *r) {
    if (!r) return 0;
    int s = r->num;
    s += treeSum(r->left);
    s += treeSum(r->right);
    return s;
}

void Tree::treePrefix(Node *r) {
    if (r) {
        std:: cout << r->num << ' ';
        treePrefix(r->left);
        treePrefix(r->right);
    }
    return;
}

void Tree::treeInfix(Node *r) {
    if (r) {
        treeInfix(r->left);
        std:: cout << r->num << ' ';
        treeInfix(r->right);
    }
    return;
}

void Tree::treePostfix(Node *r) {
    if (r) {
        treePostfix(r->left);
        treePostfix(r->right);
        std:: cout << r->num << ' ';
    }
    return;
}

void Tree::printTree(Node *r, int l) {
    if (r) {
        printTree(r->right, l + 1);
        std::cout << std::setw(4 * l) << "" << r->num << std::endl;
        printTree(r->left, l + 1);
    }
    return;
}

int Tree::countInstances(Node *r, int n) {
    if (!r) return 0;
    int c = r->num == n ? 1 : 0;
    c += countInstances(r->left, n);
    c += countInstances(r->right, n);
    return c;
}

int Tree::treeMin(Node *r) {
    Node *p = r;
    if (!p) return 0;
    while (p->left) p = p->left;
    return p->num;
}

int Tree::treeMax(Node *r) {
    Node *p = r;
    if (!p) return 0;
    while (p->right) p = p->right;
    return p->num;
}

Tree::Node *Tree::search(int n) const {
    Node *p = root;
    while (p) {
        if (n == p->num) return p;
        else if (n < p->num) p = p->left;
        else p = p->right;
    }
    return 0;
}

void Tree::treeAdd(Node *&r, int n) {
    if (!r) r = new Node(n);
    else if (n < r->num) treeAdd(r->left, n);
    else if (n > r->num) treeAdd(r->right, n);
    else if (rand() / (RAND_MAX + 1.) < 0.5) treeAdd(r->left, n);
    else treeAdd(r->right, n);
}

void Tree::read(int n) {
    int number;
    freeTree(root);
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        treeAdd(root, number);
    }
}

bool Tree::treeRemove(Node *&r, int n) {
    Node *q = nullptr, *p = r;

    while (p && n != p->num) {
        q = p;
        if (n < p->num) p = p->left;
        else p = p->right;
    }
    if (!p) return 0;

    Node *rp;
    if (!p->left) rp = p->right;
    else if (!p->right) rp = p->left;
    else {
        Node *f = p;
        rp = p->right;
        Node *s = rp->left;

        while (s) {
            f = rp;
            rp = rp->left;
            s = rp->left;
        }

        if (f != p) {
            f->left = rp->right;
            rp->right = p->right;
        }
        rp->left = p->left;
    }

    if (!q) r = rp;
    else if (p == q->left) q->left = rp;
    else q->right = rp;

    delete p;
    return 1;
}

void Tree::treeBalance(Node *&r) {
    if (r) {
        int k = treeSize(r->left) - treeSize(r->right);
        for (; k > 1; k -= 2) {
            treeAdd(r->right, r->num);
            r->num = treeMax(r->left);
            treeRemove(r->left, r->num);
        }
        for (; k < -1; k += 2) {
            treeAdd(r->left, r->num);
            r->num = treeMin(r->right);
            treeRemove(r->right, r->num);
        }
        treeBalance(r->left);
        treeBalance(r->right);
    }
    return;
}
