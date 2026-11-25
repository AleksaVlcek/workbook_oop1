#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <iostream>
using namespace std;

class Book {
private:
    string author, title;
    double cost;

public:
    Book(string a, string t, double c) : author(a), title(t), cost(c) {}
    virtual ~Book() = default;

    virtual double value() const {return cost;}
    virtual void write(ostream &out) const {out << author << ": \"" << title << "\" (" << value() << ")";}
};

class HardCover : public Book {
private:
    double coverCost;
public:
    HardCover(string a, string t, double c, double cc) : Book(a, t, c), coverCost(cc) {}
    double value() const override {return Book::value() + coverCost;}
    void write(ostream &out) const override {Book::write(out); out << "[hard cover]";}
};

class UsedBook : public Book {
private:
    double percent;
public:
    UsedBook(string a, string t, double c, double p) : Book(a, t, c), percent(p) {}
    double value() const override {return (1 - percent / 100) * Book::value();}
    void write(ostream &out) const override {Book::write(out); out << "[used]";}
};

#endif // BOOKS_H
