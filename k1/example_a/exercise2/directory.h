#ifndef FOLDER_H
#define FOLDER_H

#include "fs_element.h"
#include <iostream>

class Directory : public FSElement {
private:
    int cap;
    int num;
    const FSElement **elems;
public:
    Directory(string n, int c) : FSElement(n), cap(c), num(0), elems(new const FSElement*[cap]) {
        for (int i = 0; i < cap; i++) {
            elems[i] = nullptr;
        }
    }

    bool add(const FSElement *fse) {
        if (num >= cap || !fse) return false;
        else {
            elems[num++] = fse;
            return true;
        }
    }

    int getSize() const override {
        int s = 0;
        for (int i = 0; i < num; i++) {
            s += elems[i]->getSize();
        }
        return s;
    }

    ~Directory() override {
        cout << "File " << name << " removed" << endl;
        for (int i = 0; i < num; i++) {
            delete elems[i];
        }
        delete elems;
    }
};

#endif // FOLDER_H
