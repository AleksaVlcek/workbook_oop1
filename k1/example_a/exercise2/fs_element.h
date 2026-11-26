#ifndef FS_ELEMENT_H
#define FS_ELEMENT_H

#include <string>
using namespace std;

class FSElement {
protected:
    string name;
public:
    FSElement(string n) : name(n) {}

    virtual ~FSElement() {}

    virtual int getSize() const = 0;
};

#endif // FS_ELEMENT_H
