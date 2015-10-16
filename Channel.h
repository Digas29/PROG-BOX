#ifndef _CHANNEL
 #define _CHANNEL

#include<iostream>
#include<vector>
#include<string>

#include "Program.h"

using namespace std;

class Channel{
  string name;
  vector<Program> programs;
 public:
  Channel(string name);
  string getName() const;
  vector<Program> getPrograms() const;
  void setName(string name);
  void setNameProg(string name, int i);
  void setTypeProg(string name, int i);
  void addProgram(Program program);
  void removeProgram(int i);
  void updateProgram(int i);
  Program getProgram(int i) const;
  unsigned int getNumberPrograms() const;
};

#endif
