#include "Channel.h"
#include <string>

using namespace std;

Channel::Channel(string name){
	Channel::name = name;
}
string Channel::getName() const{
	return name;
}
void Channel::setName(string name){
	this->name = name;
}
void Channel::addProgram(Program program){
	programs.push_back(program);
}

Program Channel::getProgram(int i) const
{
	return programs[i];
}
unsigned int Channel::getNumberPrograms() const
{
	return programs.size();
}
vector<Program> Channel::getPrograms() const
{
	return programs;
}
void Channel::removeProgram(int i){
	programs.erase(programs.begin() + i);
}
void Channel::setNameProg(string name, int i){
	programs[i].setName(name);
}
void Channel::setTypeProg(string name, int i){
	programs[i].setType(name);
}