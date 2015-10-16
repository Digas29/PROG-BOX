#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>
#include <conio.h>
#include <fstream>

#include "Date.h"
#include "Box.h"
#include "menus.h"


using namespace std;

// Randomly generates a valid day, hour and minute
Date currentDate(){
	srand((unsigned int)time(NULL));
	string daystr;
	unsigned int day;
	unsigned int hour;
	unsigned int minutes;
	day = rand() % 7 + 1;
	hour = rand() % 24;
	minutes = rand() % 60;
	switch (day)
	{
	case 1:
		daystr = "sunday";
		break;
	case 2:
		daystr = "monday";
		break;
	case 3:
		daystr = "tuesday";
		break;
	case 4:
		daystr = "wednesday";
		break;
	case 5:
		daystr = "thursday";
		break;
	case 6:
		daystr = "friday";
		break;
	case 7:
		daystr = "saturday";
		break;
	default:
		break;
	}
	Date date = Date(daystr, hour, minutes);
	return date;
}

bool initialization() {
	string YorN;
	bool valid = false;
	cout << endl << endl << "Welcome to JJ-Cable box!!" << endl << endl << "Do you want to enter in the edition mode?" << endl << "Y - Yes" << endl << "N - No" << endl;
	while (!valid)
	{
		getline(cin, YorN);
		if (YorN == "y" || YorN == "Y" || YorN == "n" || YorN == "N")
		{
			valid = true;
		}
		else
		{
			cout << endl << "ERROR!!" << " please insert your anwser again!";
		}
	}
	if (YorN == "y" || YorN == "Y")
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool askPassword(string boxpass){
	string pass = "";
	bool edition;
	char ch;
	unsigned int trials = 3;

	cout << endl << "Insert your password (3 guesses): ";
	while (trials != 0)
	{
		ch = _getch();
		while (ch != 13){//character 13 is enter
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
		if (pass == boxpass)
		{
			edition = true;
			pass = "";
			system("cls");
			cout << endl << endl << "You entered sucessefully the edition mode.";
			cout << endl << endl;
			break;
		}
		else if (trials == 1)
		{
			cout << endl << "Wrong password! No more guesses (entering normal mode).";
			edition = false;
			pass = "";
			trials--;
		}
		else
		{
			cout << endl << "Worng password! Try again: ";
			pass = "";
			trials--;
		}
	}
	cout << endl << endl;
	system("pause");
	return edition;
}


int main(){
	unsigned int menu = 1;
	Box box = Box("naotem", currentDate());
	unsigned int ClubFilms;
	unsigned int seenMovies;
	unsigned int numberOfChannels;
	unsigned int programsRecorded;
	unsigned int option;
	bool editionMode;
	bool seenMovie;
	string day;


	box.getDate().displayDate();
	box.loadDefinitions(ClubFilms, seenMovies, numberOfChannels, programsRecorded);
	box.loadChannels();
	box.loadMovies();
	box.loadMoviesSeen();
	box.loadRecordings();

	editionMode = initialization();
	if (editionMode)
	{
		editionMode = askPassword(box.getPassword());
	}
	while (menu != 0)
	{
		if (menu == 1)
		{
			menu = mainMenu();
		}
		else if (menu == 2)
		{
			menu = tvMenu();
		}
		else if (menu == 3)
		{
			menu = movieMenu();
		}
		else if (menu == 4)
		{
			menu = defenitionsMenu();
		}
		else if (menu == 5)
		{
			menu = ChannelsMenu(numberOfChannels, box);
		}
		else if (menu == 6){
			menu = programsMenu();
		}
		else if (menu == 7){
			menu = seenMovieMenu(box, seenMovies);
			seenMovie = true;
		}
		else if (menu == 8){
			menu = movieClubMenu(box, ClubFilms);
			seenMovie = false;
		}
		else if (menu == 9)
		{
			system("cls");
			cout << endl << "You spent " << box.moneySpent() << "$" << endl << endl;
			system("pause");
			menu = 3;
		}
		
		else if (menu == 20)
		{
			box.showRecording(true);
			menu = 6;
		}
		else if (menu == 21)
		{
			box.showRecording(false);
			menu = 6;
		}
		else if (menu == 22)
		{
			system("cls");
			cout << endl << "Any specific day? ";
			cin.clear();
			cin.ignore(10000, '\n');
			getline(cin, day);
			while (!(day == "monday" || day == "sunday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday" || day == "saturday" || day == ""))
			{
				cout << endl << "Invalid input! Try again: ";
				getline(cin, day);
			}
			if (day == "monday" || day == "sunday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday" || day == "saturday")
			{
				box.listByDay(day);
			}
			else if (day == "")
			{
				box.listByDay(box.getDate().getDay());
			}
			menu = 6;
		}
		else if (menu == 23)
		{
			system("cls");
			cout << endl << "##################### CHANNELS #####################" << endl << endl;
			for (size_t i = 1; i <= numberOfChannels; i++)
			{

				cout << " <" << i << "> " << box.getChannel(i - 1).getName() << endl;
				if (i == numberOfChannels)
				{
					cout << endl << endl;
					cout << " <" << i + 1 << "> " << "Back" << endl;
				}
			}
			cout << endl << "#####################################################" << endl;
			cout << endl << "Choose one of the above options: "; cin >> option;
			while (option < 1 || option > numberOfChannels + 1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid input! Try again: "; cin >> option;
				}
				else
				{
					cout << "Invalid input! Try again: "; cin >> option;
				}

			}
			if (option != numberOfChannels +1)
			{
				system("cls");
				cout << endl << "Any specific day? ";
				cin.clear();
				cin.ignore(10000, '\n');
				getline(cin, day);
				while (!(day == "monday" || day == "sunday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday" || day == "saturday" || day == ""))
				{
					cout << endl << "Invalid input! Try again: ";
					getline(cin, day);
				}
				box.listByChannel(option - 1, day);
			}
			menu = 6;
		}
		else if (menu == 24)
		{
			system("cls");
			cout << endl << "##################### TYPES #####################" << endl << endl;
			cout << " <1> Entertainment" << endl;
			cout << " <2> News" << endl;
			cout << " <3> Sports" << endl;
			cout << " <4> Back" << endl;
			cout << endl << "#####################################################" << endl;
			cout << endl << "Choose one of the above options: "; cin >> option;
			while (option < 1 || option > 4)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "Invalid input! Try again: "; cin >> option;
				}
				else
				{
					cout << "Invalid input! Try again: "; cin >> option;
				}

			}
			if (option != 4)
			{
				system("cls");
				cout << endl << "Any specific day? ";
				cin.clear();
				cin.ignore(10000, '\n');
				getline(cin, day);
				while (!(day == "monday" || day == "sunday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday" || day == "saturday" || day == ""))
				{
					cout << endl << "Invalid input! Try again: ";
					getline(cin, day);
				}
				switch (option)
				{ 
				case 1:
					box.listByType("Entertainment", day);
					break;
				case 2:
					box.listByType("News", day);
					break;
				case 3:
					box.listByType("Sports", day);
					break;
				default:
					break;
				}
			}
			menu = 6;
		}
		else if (menu == 25)
		{
			if (editionMode){
				box.createdProgram();
			}
			else
			{
				system("cls");
				cout << endl << endl << "You don't have the priveleges to do this action..." << endl << endl;
				system("pause");
			}
			menu = 6;
		}
		else if (menu == 26)
		{
			if (editionMode){
				box.removeProgram();
			}
			else
			{
				system("cls");
				cout << endl << endl << "You don't have the priveleges to do this action..." << endl << endl;
				system("pause");
			}
			menu = 6;
		}
		else if (menu == 27)
		{
			if (editionMode){
				box.updateProgram();
			}
			else
			{
				system("cls");
				cout << endl << endl << "You don't have the priveleges to do this action..." << endl << endl;
				system("pause");
			}
			menu = 6;
		}
		else if (menu > 1000 && menu < 1997)
		{

			system("cls");
			cout << endl << endl << "You are now watching " << box.getChannel(menu - 1001).getName() << "...." << endl << endl;
			system("pause");
			menu = 5;
		}
		else if (menu == 1997)
		{
			if (editionMode)
			{
				if (box.createdChanel())
				{
					numberOfChannels++;
				}
			}
			else
			{
				system("cls");
				cout << endl << endl << "You don't have the priveleges to do this action..." << endl << endl;
				system("pause");
			}
			menu = 5;
		}
		else if (menu == 1998)
		{
			if (editionMode)
			{
				if (box.removeChanel())
				{
					numberOfChannels--;
				}
			}
			else
			{
				system("cls");
				cout << endl << endl << "You don't have the priveleges to do this action..." << endl << endl;
				system("pause");
			}
			menu = 5;
		}
		else if (menu == 1999)
		{
			if (editionMode)
			{
				box.updateChanel();
			}
			else
			{
				system("cls");
				cout << endl << endl << "You don't have the priveleges to do this action..." << endl << endl;
				system("pause");
			}
			menu = 5;
		}
		else if (menu > 2000 && menu < 2996)
		{
			menu = rentMovie(box, menu - 2000, seenMovie, seenMovies, ClubFilms);
		}
		else if (menu == 2997)
		{
			if (editionMode){
				menu = creatMovie(box, ClubFilms);
			}
			else
			{
				system("cls");
				cout << endl << endl << "You don't have the priveleges to do this action..." << endl << endl;
				system("pause");
				menu = 8;
			}
		}
		else if (menu == 2998)
		{
			if (editionMode){
				if (seenMovie)
				{
					menu = removeMovie(box, seenMovies);
				}
				else
				{
					menu = removeMovie(box, ClubFilms);
				}
			}
			else
			{
				system("cls");
				cout << endl << endl << "You don't have the priveleges to do this action..." << endl << endl;
				system("pause");
				if (seenMovie)
				{
					menu = 7;
				}
				else
				{
					menu = 8;
				}
			}
		}
		else if (menu == 2999)
		{
			if (editionMode){
				if (seenMovie)
				{
					menu = updateMovie(box, seenMovies);
				}
				else
				{
					menu = updateMovie(box, ClubFilms);
				}
			}
			else
			{
				system("cls");
				cout << endl << endl << "You don't have the priveleges to do this action..." << endl << endl;
				system("pause");
				if (seenMovie)
				{
					menu = 7;
				}
				else
				{
					menu = 8;
				}
			}
		}
		else if (menu == 4001)
		{
			if (editionMode)
			{
				box.changePassword();
			}
			else
			{
				system("cls");
				cout << endl << endl << "You don't have the priveleges to do this action..." << endl << endl;
				system("pause");
			}
			menu = 4;
		}
	}
	box.saveChannels();
	box.saveDefinitions();
	box.saveMovies();
	box.saveMoviesSeen();
	exit(0);
}