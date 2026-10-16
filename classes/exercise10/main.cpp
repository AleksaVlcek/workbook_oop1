#include "tree.h"
#include <iostream>
using std::cin, std::cout, std::endl;

template <typename R>
void apply(Tree &tree, R (Tree::*pf)(int)) {
    int n;
    cout << "Numbers? ";
    do {
        cin >> n;
        (tree.*pf)(n);
    } while (cin.get() != '\n');
}

int main() {
    Tree tree;
    bool end = false;

    while (!end) {
        cout << "\na) Add numbers\n"
                "b) Remove numbers\n"
                "c) Read tree\n"
                "d) Smallest element\n"
                "e) Largest element\n"
                "f) Search\n"
                "g) Balance\n"
                "h) Clear tree\n"
                "i) Tree size\n"
                "j) Sum of elements\n"
                "k) Count occurrences\n"
                "1. Print root-left-right\n"
                "2. Print left-root-right (sorted)\n"
                "3. Print left-right-root\n"
                "4. Draw tree\n"
                "z) Exit\n\n"
                "Choice? ";
        char choice; cin >> choice;

        int num;
        switch (choice) {
            case 'a': case 'A':
                apply(tree, &Tree::add); break;
            case 'b': case 'B':
                apply(tree, &Tree::remove); break;
            case 'c': case 'C': {
                cout << "Length? ";
                int n; cin >> n;
                cout << "Numbers? ";
                tree.read(n);
                break;
            }
            case 'd': case 'D': case 'e': case 'E':
                if (!tree.isEmpty()) {
                    switch (choice) {
                        case 'd': case 'D':
                            cout << "min = " << tree.min() << endl; break;
                        case 'e': case 'E':
                            cout << "max = " << tree.max() << endl; break;
                    }
                }
                else cout << "*** Tree is empty! ***\n";
                break;
            case 'f': case 'F':
                cout << "Number? "; cin >> num;
                cout << "Number is" << (tree.search(num) ? "" : " NOT") << " in the tree.\n";
                break;
            case 'g': case 'G':
                tree.balance(); break;
            case 'h': case 'H':
                tree.freeTree(); break;
            case 'i': case 'I':
                cout << "Size = " << tree.size() << endl; break;
            case 'j': case 'J':
                cout << "Sum = " << tree.sum() << endl; break;
            case 'k': case 'K':
                cout << "Number? "; cin >> num;
                cout << "Number occurs " << tree.count(num) << " times.\n";
                break;
            case '1':
                cout << "Tree = "; tree.prefix(); cout << endl; break;
            case '2':
                cout << "Tree = "; tree.infix(); cout << endl; break;
            case '3':
                cout << "Tree = "; tree.postfix(); cout << endl; break;
            case '4':
                tree.print(); break;
            case 'z': case 'Z':
                end = true; break;
            default:
                cout << "*** Invalid choice! ***\n"; break;
        }
    }

    return 0;
}
