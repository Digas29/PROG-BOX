#ifndef _PROGRAM
 #define _PROGRAM

#include<iostream>
#include "Date.h"


using namespace std;


class Program{
  string name;
  string type;    // introduced in the final version of the work text
  bool recorded;  // introduced in the final version of the work text
  int duration;   // in minutes
  Date exhibitionDate;

 public:
  Program(string name, string type, unsigned int duration, string day, unsigned int hour, unsigned int minutes);
  string getName() const;
  bool getRecorded() const;
  string getType() const;
  int getDuration() const;
  Date getDate() const;
  void setName(string name);
  void setRecorded(bool recorded);
  void setType(string type);
  void setDuration(int duration);
  void setDate(Date exhibitionDate);
  bool operator== (const Program &program2) const;
  bool operator< (const Program &p2) const;
};

#endif
