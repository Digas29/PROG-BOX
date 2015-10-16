#ifndef _DATE
#define _DATE

#include <iostream>

using namespace std;


class Date{
	string weekDay;
	unsigned hour;
	unsigned minutes;
public:
	Date(string day, unsigned hour, unsigned minutes);
	string getDay() const;
	unsigned getHour() const;
	unsigned getMinutes() const;
	void displayDate() const;
	int weekDayInt(string weekDay) const;
	bool operator< (const Date& d1) const;
	bool operator== (const Date& d1) const;
	Date operator+ (const unsigned int duration) const;
};
#endif
