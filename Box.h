#ifndef _BOX
#define _BOX

#include<iostream>
#include<vector>
#include<string>

#include "Date.h"
#include "Channel.h"
#include "Program.h"
#include "Movie.h"

using namespace std;


class Box{
	string password;
	Date currentDate;
	vector<Channel> channels;
	vector<Movie> movieClub;
	vector<Movie> seenMovies;
	vector<Program> toBeRecorded;
	vector<Program> recordedPrograms;

public:
	Box(string passwd, Date currentDate);
	void listByDay(string day);
	void listByChannel(int chanI, string day);
	void listByType(string  type, string day);
	bool rentMovies(int i, bool seen);
	float moneySpent();
	bool changePassword();          // ask, verify and change the password
	// Channel CRUD
	bool createdChanel();
	bool removeChanel();
	bool updateChanel();
	// Program CRUD
	bool createdProgram();
	bool removeProgram();
	bool updateProgram();
	// Movie CRUD
	bool createdMovie(string channelName, float price);
	bool removeMovie(int i);
	bool updateMovie(int i, string name, float price);
	//get's
	Date getDate() const;
	string getPassword() const;
	Channel getChannel(int i) const;
	Movie getMovieClub(int i) const;
	Movie getSeenMovie(int i) const;
	void showRecording(bool recorded);
	void loadChannels();
	void loadMovies();
	void loadMoviesSeen();
	void loadDefinitions(unsigned int &ClubMovies, unsigned int &seenMovies, unsigned int &channels, unsigned int &programsRecorded);
	void loadRecordings();
	void saveChannels() const;
	void saveMovies() const;
	void saveMoviesSeen() const;
	void saveDefinitions() const;
};

#endif

