#ifndef FILE_H
#define FILE_H

#include "fs_element.h"
#include <iostream>

class File : public FSElement {
private:
    int size;
public:
    File(string n, int s) : FSElement(n), size(s) {
        cout << "File " << name << " made" << endl;
    }

    virtual ~File() override {
        cout << "File " << name << " removed" << endl;
    }

    int getSize() const override {return size;}
};

#endif // FILE_H
