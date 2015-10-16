#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Date.h"
#include "Box.h"


using namespace std;

int mainMenu() {
	int option = 0;
	system("cls");
	cout << endl;
	cout << "##################### MAIN MENU #####################" << endl << endl;
	cout << " <1> TV                                              " << endl;
	cout << " <2> Movie Club                                      " << endl;
	cout << " <3> Definitions                                     " << endl;
	cout << " <4> Turn Off                                        " << endl << endl;
	cout << "#####################################################" << endl;
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
	if (option == 1)
	{
		return 2;
	}
	else if (option == 2)
	{
		return 3;
	}
	else if (option == 3)
	{
		return 4;
	}
	else
	{
		return 0;
	}
}
int tvMenu(){
	int option = 0;
	system("cls");
	cout << endl << "###################### TV MENU ######################" << endl;
	cout << endl;
	cout << " <1> Channels                                        " << endl;
	cout << " <2> Programs                                        " << endl;
	cout << " <3> Back                                            " << endl;
	cout << " <4> Turn Off                                        " << endl;
	cout << endl << "#####################################################" << endl;
	cout << endl << "Choose one of the above options: "; cin >> option;
	while (option < 1 || option > 4)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input! Try again: "; cin >> option;
		}
		else
		{
			cout << "Invalid input! Try again: "; cin >> option;
		}
	}
	if (option == 1)
	{
		return 5;
	}
	else if (option == 2)
	{
		return 6;
	}
	else if (option == 3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int movieMenu(){
	int option = 0;
	system("cls");
	cout << endl << "################## MOVIE CLUB MENU ##################" << endl;
	cout << endl;
	cout << " <1> Movies Seen                                     " << endl;
	cout << " <2> Movies not seen                                 " << endl;
	cout << " <3> Money spent                                     " << endl;
	cout << " <4> Back                                            " << endl;
	cout << " <5> Turn Off                                        " << endl;
	cout << endl << "#####################################################" << endl;
	cout << endl << "Choose one of the above options: "; cin >> option;
	while (option < 1 || option > 5)
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
	if (option == 1)
	{
		return 7;
	}
	else if (option == 2)
	{
		return 8;
	}
	else if (option == 3)
	{
		return 9;
	}
	else if (option == 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int defenitionsMenu() {
	int option = 0;
	system("cls");
	cout << endl << "################# DEFINITIONS MENU ##################" << endl;
	cout << endl;
	cout << " <1> Change Password                                 " << endl;
	cout << " <2> Back                                            " << endl;
	cout << " <3> Turn Off                                        " << endl;
	cout << endl << "#####################################################" << endl;
	cout << endl << "Choose one of the above options: "; cin >> option;
	while (option < 1 || option > 3)
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
	if (option == 1)
	{
		return 4001;
	}
	else if (option == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int ChannelsMenu(unsigned int NumberOfChannels, Box &box){
	int option = 0;
	system("cls");
	cout << endl << "##################### CHANNELS #####################" << endl << endl;
	for (size_t i = 1; i <= NumberOfChannels; i++)
	{

		cout << " <" << i << "> " << box.getChannel(i - 1).getName() << endl;
		if (i == NumberOfChannels)
		{
			cout << endl << endl;
			cout << " <" << i + 1 << "> " << "Creat Channel" << endl;
			cout << " <" << i + 2 << "> " << "Remove Channel" << endl;
			cout << " <" << i + 3 << "> " << "Update Channel" << endl;
			cout << " <" << i + 4 << "> " << "Back" << endl;
			cout << " <" << i + 5 << "> " << "Turn Off";
		}
	}
	cout << endl << "#####################################################" << endl;
	cout << endl << "Choose one of the above options: "; cin >> option;
	while (option < 1 || option > NumberOfChannels + 5)
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
	if (option <= NumberOfChannels)
	{
		return 1000 + option;
	}
	else if (option == NumberOfChannels + 1)
	{
		return 1997;
	}
	else if (option == NumberOfChannels + 2)
	{
		return 1998;
	}
	else if (option == NumberOfChannels + 3)
	{
		return 1999;
	}
	else if (option == NumberOfChannels + 4)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}
int programsMenu() {
	int option = 0;
	system("cls");
	cout << endl << "####################  PROGRAMS  #####################" << endl << endl;
	cout << " <1> " << "Sort by day" << endl;
	cout << " <2> " << "Sort by channel" << endl;
	cout << " <3> " << "Sort by type of program" << endl;
	cout << " <4> " << "Recordings" << endl;
	cout << " <5> " << "Scheduled recordings" << endl;
	cout << " <6> " << "Creat Program" << endl;
	cout << " <7> " << "Remove Program" << endl;
	cout << " <8> " << "Update Program" << endl;
	cout << " <9> " << "Back" << endl;
	cout << " <10> " << "Turn Off" << endl;
	cout << endl << "#####################################################" << endl;
	cout << endl << "Choose one of the above options: "; cin >> option;
	while (option < 1 || option > 10)
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
	if (option == 1)
	{
		return 22;
	}
	else if (option == 2)
	{
		return 23;
	}
	else if (option == 3)
	{
		return 24;
	}
	else if (option == 4)
	{
		return 20;
	}
	else if (option == 5)
	{
		return 21;
	}
	else if (option == 6)
	{
		return 25;
	}
	else if (option == 7)
	{
		return 26;
	}
	else if (option == 8)
	{
		return 27;
	}
	else if (option == 9)
	{
		return 2;
	}
	else
	{
		return 0;
	}

}
int seenMovieMenu(Box &box, unsigned int numberOfMovies){
	int option = 0;
	system("cls");
	cout << endl << "#################### MOVIES SEEN ####################" << endl;
	cout << endl;
	for (size_t i = 1; i <= numberOfMovies; i++)
	{

		cout << " <" << i << "> " << box.getSeenMovie(i - 1).getTitle() << " - " << box.getSeenMovie(i - 1).getCost() << "$" << " / seen " << box.getSeenMovie(i - 1).get_timesRented() << " time(s)" << endl;
		if (i == numberOfMovies)
		{
			cout << endl << endl;
			cout << " <" << i + 1 << "> " << "Back" << endl;
			cout << " <" << i + 2 << "> " << "Turn Off";
		}
	}
	cout << endl << "#####################################################" << endl;
	cout << endl << "Choose one of the above options: "; cin >> option;
	while (option < 1 || option > numberOfMovies + 2)
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
	if (option <= numberOfMovies)
	{
		return 2000 + option;
	}
	else if (option == numberOfMovies + 1)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}
int movieClubMenu(Box &box, unsigned int numberOfMovies){
	int option = 0;
	system("cls");
	cout << endl << "################## MOVIES NOT SEEN ##################" << endl;
	cout << endl;
	for (size_t i = 1; i <= numberOfMovies; i++)
	{

		cout << " <" << i << "> " << box.getMovieClub(i - 1).getTitle() << " - " << box.getMovieClub(i - 1).getCost() << "$" << endl;
		if (i == numberOfMovies)
		{
			cout << endl << endl;
			cout << " <" << i + 1 << "> " << "Creat Movie" << endl;
			cout << " <" << i + 2 << "> " << "Remove Movie" << endl;
			cout << " <" << i + 3 << "> " << "Update Movie" << endl;
			cout << " <" << i + 4 << "> " << "Back" << endl;
			cout << " <" << i + 5 << "> " << "Turn Off";
		}
	}
	cout << endl << "#####################################################" << endl;
	cout << endl << "Choose one of the above options: "; cin >> option;
	while (option < 1 || option > numberOfMovies + 5)
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
	if (option <= numberOfMovies)
	{
		return 2000 + option;
	}
	else if (option == numberOfMovies + 1)
	{
		return 2997;
	}
	else if (option == numberOfMovies + 2)
	{
		return 2998;
	}
	else if (option == numberOfMovies + 3)
	{
		return 2999;
	}
	else if (option == numberOfMovies + 4)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}
int creatMovie(Box &box, unsigned int &numberOfMovies) {
	char a = 0;
	string movieName;
	float price;
	bool flag = false;
	system("cls");
	cout << endl << "################## CREAT MOVIE ##################" << endl << endl;
	cout << "Are you sure you want to creat a movie? " << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a!= 13)
	{
		a = _getch();
	}
	if (a == 27)
	{
		return 8;
	}
	else
	{
		while (!flag)
		{
			system("cls");
			cout << endl << "################## CREAT MOVIE ##################" << endl << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Movie name: ";
			while (movieName == "")
			{
				getline(cin, movieName);
			}
			cout << "Price: ";
			cin >> price;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input! Try again: "; cin >> price;
			}
			flag = box.createdMovie(movieName, price);
			if (!flag)
			{
				cout << endl << "Name unaviable...." << endl;
				Sleep(2000);
			}
		}
	}
	system("cls");
	cout << endl << endl << "Creating Movie, please wait......" << endl << endl << endl;
	Sleep(3000);
	system("pause");
	numberOfMovies++;
	return 8;
}
int removeMovie(Box &box, unsigned int &numberOfMovies){
	char a = 0;
	int movieNumber;

	system("cls");
	cout << endl << "################## REMOVE MOVIE ##################" << endl << endl;
	cout << "Are you sure you want to remove a movie? " << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a != 13)
	{
		a = _getch();
	}
	if (a == 27)
	{
			return 8;
	}
	system("cls");
	cout << endl << "################## REMOVE MOVIE ##################" << endl << endl;
	for (size_t i = 1; i <= numberOfMovies; i++)
	{
		cout << " <" << i << "> " << box.getMovieClub(i - 1).getTitle() << endl;
	}
	cout << endl << "##################################################" << endl;
	cout << endl << "Which one do you want to remove? ";
	cin >> movieNumber;
	while (cin.fail() || movieNumber < 1 || movieNumber > numberOfMovies)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> movieNumber;
	}
	box.removeMovie(movieNumber - 1);
	system("cls");
	cout << endl << endl << "Removing Movie. Please wait....";
	Sleep(2000);
	cout << endl << endl;
	system("pause");
	numberOfMovies--;
	return 8;
}
int updateMovie(Box &box, unsigned int &numberOfMovies){
	int option;
	char a = 0;
	string movieName;
	float price;
	int movieNumber;

	system("cls");
	cout << endl << "################## UPDATE MOVIE ##################" << endl << endl;
	cout << "Are you sure you want to update a movie? " << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a != 13)
	{
		a = _getch();
	}
	if (a == 27)
	{
		return 8;
	}
	system("cls");
	cout << endl << "################## UPDATE MOVIE ##################" << endl << endl;
	for (size_t i = 1; i <= numberOfMovies; i++)
	{
		cout << " <" << i << "> " << box.getMovieClub(i - 1).getTitle() << endl;
	}
	cout << endl << "##################################################" << endl;
	cout << endl << "Which one do you want to update? ";
	cin >> movieNumber;
	while (cin.fail() || movieNumber < 1 || movieNumber > numberOfMovies)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> movieNumber;
	}
	system("cls");
	cout << endl << "################## UPDATE MOVIE ##################" << endl << endl;
	cout << " <1> Update Name" << endl << " <2> Update Cost" << endl;
	cout << endl << "##################################################" << endl;
	cout << endl << "Which one do you want to update? ";
	cin >> option;
	while (cin.fail() || option < 1 || option > 2)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input! Try again: "; cin >> option;
	}
	system("cls");
	cout << endl << "################## UPDATE MOVIE ##################" << endl << endl;
	if (option == 1)
	{
		cout << "Movie's current name:" << box.getMovieClub(movieNumber - 1).getTitle() << endl;
		cout << "New Name: ";
		cin.clear();
		cin.ignore(10000, '\n');
		getline(cin, movieName);
		box.updateMovie(movieNumber - 1, movieName, box.getMovieClub(movieNumber - 1).getCost());
	}
	else
	{
		cout << "Movie's current cost:" << box.getMovieClub(movieNumber - 1).getCost() << endl;
		cout << "New Cost: ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> price;
		while (cin.fail() || price < 0)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Try again: "; cin >> price;
		}
		box.updateMovie(movieNumber - 1, box.getMovieClub(movieNumber - 1).getTitle(), price);
	}
	system("cls");
	cout << endl << endl << "Updating Movie. Please wait....";
	Sleep(2000);
	cout << endl << endl;
	system("pause");
	return 8;
}
int rentMovie(Box &box, int movieNumber, bool seen, unsigned int &seenMovies, unsigned int &movieClub)
{
	char a = 0;
	system("cls");
	cout << endl << "################### SEE MOVIE ####################" << endl << endl;
	cout << "Are you sure you want to see this movie? " << endl;
	cout << "ENTER - YES" << endl;
	cout << "ESC - NO" << endl;
	while (a != 27 && a != 13)
	{
		a = _getch();
	}
	if (a == 27)
	{
		if (seen){
			return 7;
		}
		else
		{
			return 8;
		}
	}
	system("cls");
	if (seen)
	{
		cout << "You are now watching " << box.getSeenMovie(movieNumber - 1).getTitle() << "......" << endl << endl;
		box.rentMovies(movieNumber - 1, seen);
	}
	else
	{
		cout << "You are now watching " << box.getMovieClub(movieNumber - 1).getTitle() << "......" << endl << endl;
		box.rentMovies(movieNumber - 1, seen);
		seenMovies++;
		movieClub--;
	}
	if (seen){
		return 7;
	}
	else
	{
		return 8;
	}
}