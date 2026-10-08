#include "date.h"
#include <iostream>
#include <cstdlib>

const short Date::len[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

const short Date::pass[][12] = {
    {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
    {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
};

const std::string Date::nameD[] = {
    "", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

const std::string Date::nameM[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};


bool Date::isLeap(short year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool Date::isValid(short dd, short mm, short yy) {
    return (yy > 0 && mm > 0 && mm <= 12 && dd > 0 && dd <= len[isLeap(yy)][mm - 1]);
}

Date::Date(short dd, short mm, short yy) : d(dd), m(mm), y(yy) {
    if (!isValid(dd, mm, yy)) exit(1);
}

short Date::getD() const {return d;}
short Date::getM() const {return m;}
short Date::getY() const {return y;}

Date Date::read() {
    short dd, mm, yy;
    while (true) {
        std::cin >> dd >> mm >> yy;
        if (isValid(dd, mm, yy)) break;
    }
    return Date(dd, mm, yy);
}

void Date::print() const {
    std::cout << d << ' ' << m << ' ' << y << std::endl;
}

int Date::dayInYear() const {
    return pass[isLeap(y)][m - 1] + d;
}

long Date::dayFromStart() const {
    short yy = y - 1;
    return yy * 365L + yy / 4 - yy / 100 + yy / 400 + dayInYear();
}

int Date::dayInWeek() const {
    return (dayFromStart() + 6) % 7 + 1;
}

int Date::lenMonth() const {return len[isLeap(y)][m - 1];}

void Date::tomorrow() {
    if (d == len[isLeap(y)][m - 1]) {
        d = 1;
        if (m == 12) {
            m = 1;
            y++;
        }
        else {
            m++;
        }
    }
    else {
        d++;
    }
}

void Date::yesterday() {
    if (d == 1) {
        d = len[isLeap(y)][m - 1];
        if (m == 1) {
            m = 12;
            y--;
        }
        else {
            m--;
        }
    }
    else {
        d--;
    }
}

void Date::add(unsigned k) {
    for (unsigned i = 0; i < k; i++) {
        tomorrow();
    }
}

void Date::sub(unsigned k) {
    for (unsigned i = 0; i < k; i++) {
        yesterday();
    }
}

long diff(const Date &d1, const Date &d2) {
    return d1.dayFromStart() - d2.dayFromStart() > 0 ? d1.dayFromStart() - d2.dayFromStart() : d2.dayFromStart() - d1.dayFromStart();
}

std::string Date::dayName() const {return nameD[dayInWeek()];}
std::string Date::monthName() const {return nameM[m - 1];}
