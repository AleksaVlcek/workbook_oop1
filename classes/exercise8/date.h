#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
    static const short len[][12];
    static const short pass[][12];
    static const std::string nameD[];
    static const std::string nameM[];
    short d, m, y;

public:
    static bool isLeap(short);
    static bool isValid(short, short, short);

    Date(short, short, short);

    short getD() const;
    short getM() const;
    short getY() const;

    static Date read();
    void print() const;

    int dayInYear() const;
    long dayFromStart() const;
    int dayInWeek() const;
    int lenMonth() const;

    void tomorrow();
    void yesterday();
    void add(unsigned);
    void sub(unsigned);

    friend long diff(const Date&, const Date&);

    std::string dayName() const;
    std::string monthName() const;

};

#endif // DATE_H
