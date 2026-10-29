#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
using namespace std;

class Student : public Person {
private:
    string school, year;
public:
    Student(string n = "", string d = "", string a = "", string s = "", string y = "") : Person(n, d, a), school(s), year(y) {}

    string getSchool() const {return school;}
    string getYear() const {return year;}

    Student &setSchool(const string &s) {school = s; return *this;}
    Student &setYear(const string &y) {year = y; return *this;}

    void read() override {
        Person::read();
        cin >> school >> year;
    }

    void print() const override {
        Person::print();
        cout  << ' ' << school << ' ' << year;
    }
};

#endif // STUDENT_H
