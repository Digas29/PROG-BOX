#include "Movie.h"
#include <string>

using namespace std;

Movie::Movie(string title, float cost){
	this->title = title;
	this->cost = cost;
	timesRented = 0;
}
string Movie::getTitle() const{
	return title;
}
float Movie::getCost() const{
	return cost;
}
unsigned Movie::get_timesRented() const{
	return timesRented;
}
void Movie::set_timesRented(unsigned int a) {
	timesRented = a;
}
void Movie::setName(string name){
	title = name;
}
void Movie::setCost(float price)
{
	cost = price;
}