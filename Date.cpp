#include "Date.h"
#include <string>
#include <iomanip>
using namespace std;

Date::Date(string day, unsigned hour, unsigned minutes){
	weekDay = day;
	this->hour = hour;
	this->minutes = minutes;
}
string Date::getDay() const{
	return weekDay;
}
unsigned Date::getHour() const{
	return hour;
}
unsigned Date::getMinutes() const{
	return minutes;
}
void Date::displayDate() const {
	cout << weekDay << ", " << setfill('0') << setw(2) << hour;
	cout << ":";
	cout << setfill('0') << setw(2) << minutes;
}
int Date::weekDayInt(string weekDay) const{
	if (weekDay == "sunday")
	{
		return 1;
	}
	else if (weekDay == "monday")
	{
		return 2;
	}
	else if (weekDay == "tuesday")
	{
		return 3;
	}
	else if (weekDay == "wednesday")
	{
		return 4;
	}
	else if (weekDay == "thursday")
	{
		return 5;
	}
	else if (weekDay == "friday")
	{
		return 6;
	}
	else
	{
		return 7;
	}
}

bool Date::operator< (const Date &d1) const{
	if (weekDayInt(weekDay) < weekDayInt(d1.getDay()))
	{
		return true;
	}
	else if (weekDayInt(weekDay) == weekDayInt(d1.getDay()))
	{
		if (hour < d1.getHour()) 
		{
			return true;
		}
		else if (hour == d1.getHour())
		{
			if (minutes < d1.getMinutes()) 
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}
bool Date::operator== (const Date& d1) const
{
	if (weekDay == d1.getDay() && hour == d1.getHour() && minutes == d1.getMinutes())
	{
		return true;
	}
	else
	{
		return false;
	}
}
Date Date::operator+ (const unsigned int duration) const{
	unsigned int minutes1 = duration % 60;
	unsigned int hours1 = duration / 60;
	unsigned int weekDay1 = weekDayInt(weekDay);
	string weekDay2;
	minutes1 += minutes;
	hours1 += hour;
	if (minutes1 >= 60){
		hours1++;
		minutes1 -= 60;
	}
	while (hours1 >= 24)
	{
		weekDay1++;
		hours1 -= 24;
	}
	switch (weekDay1)
	{
	case 1:
		weekDay2 = "sunday";
		break;
	case 2:
		weekDay2 = "monday";
		break;
	case 3:
		weekDay2 = "tuesday";
		break;
	case 4:
		weekDay2 = "wednesday";
		break;
	case 5:
		weekDay2 = "thursday";
		break;
	case 6:
		weekDay2 = "friday";
		break;
	case 7:
		weekDay2 = "saturday";
		break;
	default:
		break;
	}
	Date d1(weekDay2, hours1, minutes1);
	return d1;
}