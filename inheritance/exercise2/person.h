#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person {
private:
    string name, date, address;
public:
    Person(string n = "", string d = "", string a = "") : name(n), date(d), address(a) {}

    virtual ~Person() = default;

    string getName() const {return name;}
    string getDate() const {return date;}
    string getAddress() const {return address;}

    Person &setName(const string &n) {name = n; return *this;}
    Person &setDate(const string &d) {date = d; return *this;}
    Person &setAddress(const string &a) {address = a; return *this;}

    virtual void read() {
        cin >> name >> date >> address;
    }

    virtual void print() const {
        cout << name << ' ' << date << ' ' << address;
    }
};

#endif // PERSON_H
