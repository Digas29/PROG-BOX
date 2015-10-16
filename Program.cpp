#include "Program.h"
#include "Date.h"

Program::Program(string name, string type, unsigned int duration, string day, unsigned int hour, unsigned int minutes):exhibitionDate(day, hour, minutes){
	this->name = name;
	this->type = type;
	this->duration = duration;
	this->recorded = false;
}

string Program::getName() const
{
	return name;
}
bool Program::getRecorded() const
{
	return recorded;
}
string Program::getType() const
{
	return type;
}
int Program::getDuration() const
{
	return duration;
}
Date Program::getDate() const
{
	return exhibitionDate;
}
void Program::setName(string name)
{
	this->name = name;
}
void Program::setRecorded(bool recorded){
	this->recorded = recorded;
}
void Program::setType(string type){
	this->type = type;
}
void Program::setDuration(int duration)
{
	this->duration = duration;
}
void Program::setDate(Date exhibitionDate)
{
	this->exhibitionDate = exhibitionDate;
}
bool Program::operator== (const Program &program2) const{
	if (name == program2.getName() && type == program2.getType() && duration == program2.getDuration() && exhibitionDate == program2.getDate())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Program::operator< (const Program &p2) const{
	if (exhibitionDate < p2.getDate()){
		return true;
	}
	else
	{
		return false;
	}
}
