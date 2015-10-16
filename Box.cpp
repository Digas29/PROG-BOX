#include "Box.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <algorithm>

using namespace std;

Box::Box(string passwd, Date date) :currentDate(date){
	password = passwd;
}

// GET'S

Date Box::getDate() const{
	return currentDate;
}
string Box::getPassword() const{
	return password;
}
Channel Box::getChannel(int i) const{
	return channels[i];
}
Movie Box::getMovieClub(int i) const
{
	return movieClub[i];
}
Movie Box::getSeenMovie(int i) const
{
	return seenMovies[i];
}

//LOAD Files

void Box::loadChannels(){
	string filename = "channels.txt";
	string channelName;
	string name, weekday, type, date, numberOfPrograms;
	unsigned int hour, minutes, duration, numberOfProgramsInt;
	ifstream channelsFile;
	channelsFile.open(filename.c_str());
	while (getline(channelsFile, channelName))
	{
		Channel channel(channelName);
		getline(channelsFile, numberOfPrograms);
		numberOfProgramsInt = stoi(numberOfPrograms);
		for (size_t i = 0; i < numberOfProgramsInt; i++)
		{
			getline(channelsFile, name);
			getline(channelsFile, type);
			getline(channelsFile, weekday);
			getline(channelsFile, date);
			hour = stoi(date);
			getline(channelsFile, date);
			minutes = stoi(date);
			getline(channelsFile, date);
			duration = stoi(date);
			Program program(name, type, duration, weekday, hour, minutes);
			channel.addProgram(program);
		}
		channels.push_back(channel);
	}
	channelsFile.close();
}
void Box::loadMovies()
{
	string filename = "movies.txt";
	string movieName;
	string price;
	float moviePrice;
	ifstream moviesFile;
	moviesFile.open(filename.c_str());
	while (getline(moviesFile, movieName))
	{
		getline(moviesFile, price);
		moviePrice = stof(price);
		Movie movie(movieName, moviePrice);
		movieClub.push_back(movie);
	}
	moviesFile.close();
}
void Box::loadMoviesSeen()
{
	string filename = "moviesSeen.txt";
	string movieName;
	string price;
	float moviePrice;
	string numberSeen;
	unsigned int timesSeen;
	ifstream moviesFile;
	moviesFile.open(filename.c_str());
	while (getline(moviesFile, movieName))
	{
		getline(moviesFile, price);
		moviePrice = stof(price);
		getline(moviesFile, numberSeen);
		timesSeen = stoi(numberSeen);
		Movie movie(movieName, moviePrice);
		movie.set_timesRented(timesSeen);
		seenMovies.push_back(movie);
	}
	moviesFile.close();
}
void Box::loadDefinitions(unsigned int &ClubMovies, unsigned int &seenMovies, unsigned int &channels, unsigned int &programsRecorded){
	string filename = "general_information.txt";
	string line;
	ifstream defFile;
	defFile.open(filename.c_str());
	getline(defFile, line);
	password = line;
	getline(defFile, line);
	channels = stoi(line);
	getline(defFile, line);
	ClubMovies = stoi(line);
	getline(defFile, line);
	seenMovies = stoi(line);
	getline(defFile, line);
	programsRecorded = stoi(line);
	defFile.close();
}
void Box::loadRecordings(){
	ifstream programsFile;
	string filename = "recorded_programs.txt";
	string name, weekday, date;
	unsigned int hour, minutes, duration;
	string type;

	programsFile.open(filename.c_str());
	while (getline(programsFile, name))
	{
		getline(programsFile, type);
		getline(programsFile, weekday);
		getline(programsFile, date);
		hour = stoi(date);
		getline(programsFile, date);
		minutes = stoi(date);
		getline(programsFile, date);
		duration = stoi(date);
		Program program(name, type, duration, weekday, hour, minutes);
		if (program.getDate() < currentDate)
		{
			program.setRecorded(true);
			recordedPrograms.push_back(program);
		}
		else
		{
			toBeRecorded.push_back(program);
		}

	}

}


void Box::showRecording(bool recorded)
{
	int option;
	char a = 0;
	system("cls");
	if (recorded)
	{
		cout << endl << "################## RECORDED PROGRAMS ##################" << endl << endl;
		for (size_t i = 0; i < recordedPrograms.size(); i++)
		{
			cout << " <" << i + 1 << "> " << recordedPrograms[i].getName() << " - "; recordedPrograms[i].getDate().displayDate();
			cout << endl;
		}
		cout << " <" << recordedPrograms.size() + 1 << "> Back" << endl;
		cout << endl << "######################################################" << endl;
		cout << endl << "What do you want to do? "; cin >> option;
		while (cin.fail() || option < 1 || option > recordedPrograms.size() + 1)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Try again: "; cin >> option;
		}
		if (option <= recordedPrograms.size())
		{
			system("cls");
			cout << endl << "You are watching " << recordedPrograms[option - 1].getName() << " recording..." << endl << endl;
			system("pause");
		}
	}
	else
	{
		cout << endl << "################ SCHEDULED RECORDINGS #################" << endl << endl;
		for (size_t i = 0; i < toBeRecorded.size(); i++)
		{
			cout << " <" << i + 1 << "> " << toBeRecorded[i].getName() << " - "; toBeRecorded[i].getDate().displayDate();
			cout << endl;
		}
		cout << endl << "######################################################" << endl;
		cout << endl << "Enter ESC to go back or ENTER to cancel a recording";
		while (a != 27 && a != 13)
		{
		
			a = _getch();
		}
		if (a == 13)
		{
			system("cls");
			cout << endl << "################ SCHEDULED RECORDINGS #################" << endl << endl;
			for (size_t i = 0; i < toBeRecorded.size(); i++)
			{
				cout << " <" << i + 1 << "> " << toBeRecorded[i].getName() << " - "; toBeRecorded[i].getDate().displayDate();
				cout << endl;
			}
			cout << endl << "######################################################" << endl;
			cout << endl << "Which one do you want to cancel? ";
			cin >> option;
			while (cin.fail() || option < 1 || option > toBeRecorded.size())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input! Try again: "; cin >> option;
			}
			system("cls");
			toBeRecorded.erase(toBeRecorded.begin() + option - 1);
			cout << endl << "Recording cancelled. Please wait...." << endl;
			cout << endl << endl;
			Sleep(2000);
			system("pause");

		}
	}
}

// CRUD Movie

bool Box::createdMovie(string movieName, float price){
	for (size_t i = 0; i < movieClub.size(); i++)
	{
		if (movieName == movieClub[i].getTitle())
		{
			return false;
		}
	}
	Movie movie(movieName, price);
	movieClub.push_back(movie);
	return true;
}
bool Box::removeMovie(int i) 
{
	movieClub.erase(movieClub.begin() + i);
	return true;
}
bool Box::updateMovie(int i, string name, float price)
{

	movieClub[i].setName(name);
	movieClub[i].setCost(price);
	return true;
}
bool Box::rentMovies(int i, bool seen){
	if (seen)
	{
		seenMovies[i].set_timesRented(seenMovies[i].get_timesRented() + 1);
	}
	else
	{
		movieClub[i].set_timesRented(movieClub[i].get_timesRented() + 1);
		seenMovies.push_back(movieClub[i]);
		movieClub.erase(movieClub.begin() + i);
	}
	return true;
}
float Box::moneySpent()
{
	float total = 0;

	for (size_t i = 0; i < seenMovies.size(); i++)
	{
		total += (seenMovies[i].getCost() * seenMovies[i].get_timesRented());
	}
	return total;
}

bool Box::changePassword(){
	char a = 0;
	unsigned int guesses = 3;
	char ch;
	string pass;
	string newPass1;
	string newPass2;
	system("cls");
	cout << endl << "Are you sure you want to change the password? " << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a != 13)
	{
		a = _getch();
	}
	system("cls");
	while (guesses != 0)
	{
		cout << endl << "Actual Password: ";
		ch = _getch();
		while (ch != 13)
		{//character 13 is enter
			if (ch != 8)
			{
				pass.push_back(ch);
				cout << '*';
			}
			else
			{
				if (pass.length() != 0)
				{
					cout << "\b \b";
					pass.resize(pass.length() - 1);
				}
			}
			ch = _getch();
		}
		if (pass == password)
		{
			cout << endl << "New Password: ";
			ch = 8;
			while (ch != 13)
			{//character 13 is enter
				if (ch != 8)
				{
					newPass1.push_back(ch);
					cout << '*';
				}
				else
				{
					if (newPass1.length() != 0)
					{
						cout << "\b \b";
						newPass1.resize(newPass1.length() - 1);
					}
				}
				ch = _getch();
			}
			cout << endl << "Please enter the new password again: ";
			ch = 8;
			while (ch != 13)
			{//character 13 is enter
				if (ch != 8)
				{
					newPass2.push_back(ch);
					cout << '*';
				}
				else
				{
					if (newPass2.length() != 0)
					{
						cout << "\b \b";
						newPass2.resize(newPass2.length() - 1);
					}
				}
				ch = _getch();
			}
			if (newPass1  == newPass2)
			{
				system("cls");
				cout << endl << "Changing your password....";
				Sleep(2000);
				cout << endl << endl;
				cout << endl << "Password changed sucessefully!";
				system("pause");
				cout << endl << endl;
				password = newPass1;
				return true;
			}
			else
			{
				cout << endl << "Passwords don't match" << endl << endl;
				system("pause");
				return false;
			}
		}
		else if (guesses == 1)
		{
			cout << endl << "Wrong password! No more guesses";
			pass = "";
			guesses--;
			cout << endl << endl;
			system("pause");
			return false;
		}
		else
		{
			cout << endl << "Worng password! Try again: ";
			pass = "";
			guesses--;
		}
	}
	return true;
}

// CRUD Channel

bool Box::createdChanel()
{
	char a = 0;
	string channelName;
	system("cls");
	cout << endl << "Are you sure you want to creat a new channel? " << endl << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a != 13)
	{
		a = _getch();
	}
	system("cls");
	cout << endl << "Enter the new channel's name: " << endl;
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, channelName);
	for (size_t i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName() == channelName)
		{
			cout << endl << "There is alrady a channel with that name.";
			cout << endl << "Returning to the last menu....";
			cout << endl << endl;
			system("pause");
			return false;
		}
	}
	system("cls");
	cout << endl << "Creating a new channel. Please wait...." << endl;
	Channel channel(channelName);
	channels.push_back(channel);
	cout << endl << endl;
	Sleep(2000);
	system("pause");
	return true;
}
bool Box::removeChanel()
{
	char a = 0;
	unsigned int channelNumber;

	system("cls");
	cout << endl << "Are you sure you want to remove a channel? " << endl << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a != 13)
	{
		a = _getch();
	}
	system("cls");
	cout << "################## REMOVE CHANNEL ##################" << endl << endl;
	for (size_t  i = 0; i <channels.size(); i++)
	{
		cout << " <" << i + 1 << "> " << channels[i].getName() << endl;
	}
	cout << "####################################################" << endl << endl;
	cout << "Wich channel do you like to delete: ";
	cin >> channelNumber;
	while (cin.fail() || channelNumber < 1 || channelNumber > channels.size())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> channelNumber;
	}
	system("cls");
	channels.erase(channels.begin() + channelNumber - 1);
	cout << endl << "Deleting this channel. Please wait...." << endl;
	cout << endl << endl;
	Sleep(2000);
	system("pause");
	return true;
}
bool Box::updateChanel()
{
	char a = 0;
	string newName;
	unsigned int channelNumber;

	system("cls");
	cout << endl << "Are you sure you want to update a channel? " << endl << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a != 13)
	{
		a = _getch();
	}
	system("cls");
	cout << "################## UPDATE CHANNEL ##################" << endl << endl;
	for (size_t i = 0; i <channels.size(); i++)
	{
		cout << " <" << i + 1 << "> " << channels[i].getName() << endl;
	}
	cout << "####################################################" << endl << endl;
	cout << "Wich channel do you like to update: ";
	cin >> channelNumber;
	while (cin.fail() || channelNumber < 1 || channelNumber > channels.size())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> channelNumber;
	}
	system("cls");
	cout << endl << "Channel's current name: " << channels[channelNumber - 1].getName() << endl;
	cout <<endl << "Insert the channel's new name: ";
	cin.clear();
	cin.ignore(10000, '\n');
	getline(cin, newName);
	channels[channelNumber - 1].setName(newName);
	system("cls");
	cout << endl << "Updating this channel. Please wait...." << endl;
	cout << endl << endl;
	Sleep(2000);
	system("pause");
	return true;
}

// SAVE FILES

void Box::saveChannels() const{
	string filename = "channels.txt";
	ofstream channelsFile;
	channelsFile.open(filename.c_str());
	for (size_t i = 0; i < channels.size(); i++)
	{
		channelsFile << channels[i].getName() << endl;
		channelsFile << channels[i].getNumberPrograms() << endl;
		for (size_t j = 0; j < channels[i].getNumberPrograms(); j++)
		{
			channelsFile << channels[i].getProgram(j).getName() << endl;
			channelsFile << channels[i].getProgram(j).getType() << endl;
			channelsFile << channels[i].getProgram(j).getDate().getDay() << endl;
			channelsFile << channels[i].getProgram(j).getDate().getHour() << endl;
			channelsFile << channels[i].getProgram(j).getDate().getMinutes() << endl;
			channelsFile << channels[i].getProgram(j).getDuration() << endl;
		}
	}
	channelsFile.close();
}
void Box::saveMovies() const{
	string filename = "movies.txt";
	ofstream moviesFile;
	moviesFile.open(filename.c_str());
	for (size_t i = 0; i < movieClub.size(); i++)
	{
		moviesFile << movieClub[i].getTitle() << endl << movieClub[i].getCost() << endl;
	}
	moviesFile.close();
}
void Box::saveMoviesSeen() const{
	string filename = "moviesSeen.txt";
	ofstream moviesFile;
	moviesFile.open(filename.c_str());
	for (size_t i = 0; i < seenMovies.size(); i++)
	{
		moviesFile << seenMovies[i].getTitle() << endl << seenMovies[i].getCost() << endl << seenMovies[i].get_timesRented() << endl;
	}
	moviesFile.close();
}
void Box::saveDefinitions() const{
	string filename = "general_information.txt";
	ofstream defFile;
	defFile.open(filename.c_str());
	defFile << password << endl << channels.size() << endl << movieClub.size() << endl << seenMovies.size() << endl << toBeRecorded.size() + recordedPrograms.size();
	defFile.close();
}

//LIST Channels

void Box::listByDay(string day)
{
	int option;
	vector <Program> sorted;
	for (size_t i = 0; i < channels.size(); i++)
	{
		for (size_t j = 0; j < channels[i].getNumberPrograms(); j++)
		{
			if (channels[i].getProgram(j).getDate().getDay() == day)
			{
				sorted.push_back(channels[i].getProgram(j));
			}
		}

	}
	sort(sorted.begin(), sorted.end());
	system("cls");
	cout << endl << "############### " << day << " ###############" << endl << endl;
	for (size_t i = 1; i <= sorted.size(); i++)
	{
		cout << " <" << i << "> " << sorted[i - 1].getName() << " (" << sorted[i - 1].getType() << ")" << " - "; sorted[i - 1].getDate().displayDate(); cout << endl;
	}
	cout << endl << " <" << sorted.size() + 1 << "> Back" << endl << endl;
	currentDate.displayDate(); cout << endl << endl;
	cout << endl << "#############################################" << endl << endl;
	cout << "What do you want to do (choose a program to record it)? ";
	cin >> option;
	while (cin.fail() || option < 1 || option > sorted.size() + 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> option;
	}
	system("cls");
	if (option != sorted.size() + 1)
	{
		if (sorted[option - 1].getDate() < currentDate)
		{
			cout << endl << "This program already aired..." << endl << endl;
			system("pause");
		}
		else
		{
			for (size_t i = 0; i < toBeRecorded.size(); i++)
			{
				if (toBeRecorded[i] == sorted[option - 1])
				{
					cout << endl << "Recording already scheduled...." << endl << endl;
					break;
				}
				else if (i == toBeRecorded.size() - 1)
				{
					cout << endl << "Recording is now scheduled...." << endl << endl;
				}
			}
			system("pause");
			toBeRecorded.push_back(sorted[option - 1]);
		}
	}
}
void Box::listByChannel(int chanI, string day)
{
	int option;
	vector <Program> sorted;
	for (size_t j = 0; j < channels[chanI].getNumberPrograms(); j++)
	{
		if (day != "")
		{
			if (channels[chanI].getProgram(j).getDate().getDay() == day)
			{
				sorted.push_back(channels[chanI].getProgram(j));
			}
		}
		else
		{
			sorted.push_back(channels[chanI].getProgram(j));
		}
	}
	sort(sorted.begin(), sorted.end());
	system("cls");
	cout << endl << "############### " << day << " ###############" << endl << endl;
	for (size_t i = 1; i <= sorted.size(); i++)
	{
		cout << " <" << i << "> " << sorted[i - 1].getName() << " (" << sorted[i - 1].getType() << ")" << " - "; sorted[i - 1].getDate().displayDate(); cout << endl;
	}
	cout << endl << " <" << sorted.size() + 1 << "> Back" << endl << endl;
	currentDate.displayDate(); cout << endl << endl;
	cout << endl << "#############################################" << endl << endl;
	cout << "What do you want to do (choose a program to record it)? ";
	cin >> option;
	while (cin.fail() || option < 1 || option > sorted.size() + 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> option;
	}
	system("cls");
	if (option != sorted.size() + 1)
	{
		if (sorted[option - 1].getDate() < currentDate)
		{
			cout << endl << "This program already aired..." << endl << endl;
			system("pause");
		}
		else
		{
			for (size_t i = 0; i < toBeRecorded.size(); i++)
			{
				if (toBeRecorded[i] == sorted[option - 1])
				{
					cout << endl << "Recording already scheduled...." << endl << endl;
					break;
				}
				else if (i == toBeRecorded.size() - 1)
				{
					cout << endl << "Recording is now scheduled...." << endl << endl;
				}
			}
			system("pause");
			toBeRecorded.push_back(sorted[option - 1]);
		}
	}
}
void Box::listByType(string  type, string day)
{
	int option;
	vector <Program> sorted;
	for (size_t i = 0; i < channels.size(); i++)
	{
		for (size_t j = 0; j < channels[i].getNumberPrograms(); j++)
		{
			if (day != "")
			{
				if (channels[i].getProgram(j).getDate().getDay() == day && channels[i].getProgram(j).getType() == type)
				{
					sorted.push_back(channels[i].getProgram(j));
				}
			}
			else
			{
				if (channels[i].getProgram(j).getType() == type)
				{
					sorted.push_back(channels[i].getProgram(j));
				}
			}
		}
	}
	sort(sorted.begin(), sorted.end());
	system("cls");
	cout << endl << "############### " << day << " ###############" << endl << endl;
	for (size_t i = 1; i <= sorted.size(); i++)
	{
		cout << " <" << i << "> " << sorted[i - 1].getName() << " (" << sorted[i - 1].getType() << ")" << " - "; sorted[i - 1].getDate().displayDate(); cout << endl;
	}
	cout << endl << " <" << sorted.size() + 1 << "> Back" << endl << endl;
	currentDate.displayDate(); cout << endl << endl;
	cout << endl << "#############################################" << endl << endl;
	cout << "What do you want to do (choose a program to record it)? ";
	cin >> option;
	while (cin.fail() || option < 1 || option > sorted.size() + 1)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> option;
	}
	system("cls");
	if (option != sorted.size() + 1)
	{
		if (sorted[option - 1].getDate() < currentDate)
		{
			cout << endl << "This program already aired..." << endl << endl;
			system("pause");
		}
		else
		{
			for (size_t i = 0; i < toBeRecorded.size(); i++)
			{
				if (toBeRecorded[i] == sorted[option - 1])
				{
					cout << endl << "Recording already scheduled...." << endl << endl;
					break;
				}
				else if (i == toBeRecorded.size() - 1)
				{
					cout << endl << "Recording is now scheduled...." << endl << endl;
				}
			}
			system("pause");
			toBeRecorded.push_back(sorted[option - 1]);
		}
	}
}

//CRUD Program

bool Box::createdProgram(){
	char a = 0;
	int option;
	string name,type, weekday1,date;
	unsigned int duration1, hours1, minutes1;


	system("cls");
	cout << endl << "Are you sure you want to creat a new program? " << endl << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a != 13)
	{
		a = _getch();
	}
	system("cls");
	cout << endl << "Channels:" << endl << endl;
	for (size_t i = 0; i < channels.size(); i++)
	{
		cout << " <" << i + 1 << "> " << channels[i].getName() << endl;

	}
	cout << endl << "Wich channel do you like add a program: ";
	cin >> option;
	while (cin.fail() || option < 1 || option > channels.size())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> option;
	}
	system("cls");
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl << "Name of the program: ";
	getline(cin, name);
	cout << endl << "Typer of the program(News, Sports or Entertainment): ";
	getline(cin, type);
	while (type != "News" && type != "Sports" && type != "Entertainment")
	{
		cout << "Invalid input! Try again: ";
		getline(cin, type);
	}
	cout << endl << "Day of the week: ";
	getline(cin, weekday1);
	while (!(weekday1 == "monday" || weekday1 == "sunday" || weekday1 == "tuesday" || weekday1 == "wednesday" || weekday1 == "thursday" || weekday1 == "friday" || weekday1 == "saturday" || weekday1 == ""))
	{
		cout << "Invalid input! Try again: ";
		getline(cin, weekday1);
	}
	cout << endl << "Hour= ";
	cin >> hours1;
	while (cin.fail() || hours1 < 0 || hours1 > 23)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> hours1;
	}
	cout << endl << "Minutes= ";
	cin >> minutes1;
	while (cin.fail() || minutes1 < 0 || minutes1 > 59)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> minutes1;
	}
	cout << endl << "Duration= ";
	cin >> duration1;
	while (cin.fail() || duration1 < 0)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> duration1;
	}
	system("cls");
	Program program(name, type, duration1, weekday1, hours1, minutes1);
	if (program.getDate() < currentDate)
	{
		cout << endl << "You can't creat a program before of the actual date..." << endl << endl;
		system("pause");
		return false;
	}
	for (size_t i = 0; i < channels[option-1].getNumberPrograms() ; i++)
	{
		if (program.getDate() < channels[option - 1].getProgram(i).getDate())
		{
			if (channels[option - 1].getProgram(i).getDate() < program.getDate() + program.getDuration())
			{
				cout << endl << "This new program overlaps onther one..." << endl << endl;
				system("pause");
				return false;
			}
		}
		else
		{
			if (program.getDate() < channels[option - 1].getProgram(i).getDate() + channels[option - 1].getProgram(i).getDuration())
			{
				cout << endl << "This new program overlaps onther one..." << endl << endl;
				system("pause");
				return false;
			}
		}
	}
	cout << "Creating a new program. Please Wait....."<< endl << endl;
	system("pause");
	channels[option - 1].addProgram(program);
	return true;
}
bool Box::removeProgram(){
	char a = 0;
	int option, option2;

	system("cls");
	cout << endl << "Are you sure you want to remove a program? " << endl << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a != 13)
	{
		a = _getch();
	}
	system("cls");
	cout << endl << "Channels:" << endl << endl;
	for (size_t i = 0; i < channels.size(); i++)
	{
		cout << " <" << i + 1 << "> " << channels[i].getName() << endl;

	}
	cout << endl << "Wich channel do you like remove a program: ";
	cin >> option;
	while (cin.fail() || option < 1 || option > channels.size())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> option;
	}
	system("cls");
	cout << endl << "################## PROGRAMS #################" << endl << endl;
	for (size_t i = 1; i <= channels[option-1].getNumberPrograms(); i++)
	{
		cout << " <" << i << "> " << channels[option - 1].getProgram(i - 1).getName() << " - "; channels[option - 1].getProgram(i - 1).getDate().displayDate(); cout << endl;
	}
	currentDate.displayDate(); cout << endl << endl;
	cout << endl << "#############################################" << endl << endl;
	cout << "What do you want to do (choose a program to remove it it)? ";
	cin >> option2;
	while (cin.fail() || option2 < 1 || option2 > channels[option - 1].getNumberPrograms())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> option2;
	}
	system("cls");
	if (channels[option - 1].getProgram(option2 - 1).getDate() < currentDate)
	{
		cout << endl << "You can't remove programs that already aired" << endl;
		system("pause");
		return false;
	}
	cout << endl << "Program removed......" << endl;
	system("pause");
	for (size_t i = 0; i < toBeRecorded.size(); i++)
	{
		if (toBeRecorded[i] == channels[option - 1].getProgram(option2 - 1))
		{
			toBeRecorded.erase(toBeRecorded.begin() + i);
		}
	}
	channels[option - 1].removeProgram(option2 - 1);
	return true;
}
bool Box::updateProgram()
{
	char a = 0;
	int option, option2;
	string name, type;

	system("cls");
	cout << endl << "Are you sure you want to update a program? " << endl << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a != 13)
	{
		a = _getch();
	}
	system("cls");
	cout << endl << "Channels:" << endl << endl;
	for (size_t i = 0; i < channels.size(); i++)
	{
		cout << " <" << i + 1 << "> " << channels[i].getName() << endl;

	}
	cout << endl << "Wich channel do you like to update a program: ";
	cin >> option;
	while (cin.fail() || option < 1 || option > channels.size())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> option;
	}
	system("cls");
	cout << endl << "################## PROGRAMS #################" << endl << endl;
	for (size_t i = 1; i <= channels[option - 1].getNumberPrograms(); i++)
	{
		cout << " <" << i << "> " << channels[option - 1].getProgram(i - 1).getName() << " - "; channels[option - 1].getProgram(i - 1).getDate().displayDate(); cout << endl;
	}
	currentDate.displayDate(); cout << endl << endl;
	cout << endl << "#############################################" << endl << endl;
	cout << "What do you want to do (choose a program to update it)? ";
	cin >> option2;
	while (cin.fail() || option2 < 1 || option2 > channels[option - 1].getNumberPrograms())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> option2;
	}
	system("cls");
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl << "Name of the program: ";
	getline(cin, name);
	cout << endl << "Type of the program(News, Sports or Entertainment): ";
	getline(cin, type);
	while (type != "News" && type != "Sports" && type != "Entertainment")
	{
		cout << "Invalid input! Try again: ";
		getline(cin, type);
	}
	system("cls");
	for (size_t i = 0; i < toBeRecorded.size(); i++)
	{
		if (toBeRecorded[i] == channels[option - 1].getProgram(option2 - 1))
		{
			toBeRecorded[i].setName(name);
			toBeRecorded[i].setType(type);
		}
	}
	for (size_t i = 0; i < recordedPrograms.size(); i++)
	{
		if (recordedPrograms[i] == channels[option - 1].getProgram(option2 - 1))
		{
			recordedPrograms[i].setName(name);
			recordedPrograms[i].setType(type);
		}
	}
	channels[option - 1].setNameProg(name, option2 - 1);
	channels[option - 1].setTypeProg(type, option2 - 1);
	cout << endl << "Program Updated. Please wait..." << endl << endl;
	Sleep(2000);
	system("pause");
	return true;
}