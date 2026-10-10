#include "list.h"
#include <iostream>
using std::cin, std::cout, std::endl;

int main() {
    List lst;
    bool end = false;

    while (!end) {
        cout << "\n1. Add number to the beginning\n"
                "2. Add number to the end\n"
                "3. Insert number into sorted list\n"
                "4. Remove number from list\n"
                "5. Clear list\n"
                "6. Read list (reversed order)\n"
                "7. Read list (same order)\n"
                "8. List length\n"
                "9. Print list\n"
                "0. Exit\n\n"
                "Choice? ";
        int choice; cin >> choice;

        switch (choice) {
            case 1: case 2: case 3: case 4: {
                cout << "Number? ";
                int num; cin >> num;
                switch (choice) {
                    case 1:
                        lst.add(num); break;
                    case 2:
                        lst.append(num); break;
                    case 3:
                        lst.insert(num); break;
                    case 4:
                        lst.clean(num); break;
                }
                break;
            }
            case 5:
                lst.clear(); break;
            case 6: case 7: {
                cout << "Length? ";
                int n; cin >> n;
                cout << "Elements? ";
                switch (choice) {
                    case 6:
                        lst.readRight(n); break;
                    case 7:
                        lst.readLeft(n); break;
                }
                break;
            }
            case 8:
                cout << "Length = " << lst.len() << endl; break;
            case 9:
                cout << "List = "; lst.print(); break;
            case 0:
                end = true; break;
            default:
                cout << "*** Invalid choice! ***\n"; break;
        }
    }

    return 0;
}
