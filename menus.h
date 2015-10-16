#ifndef _MENUS
#define _MENUS

using namespace std;

int mainMenu();
int tvMenu();
int movieMenu();
int defenitionsMenu();
int ChannelsMenu(unsigned int NumberOfChannels, Box &box);
int programsMenu();
int seenMovieMenu(Box &box, unsigned int numberOfMovies);
int movieClubMenu(Box &box, unsigned int numberOfMovies);
int creatMovie(Box &box, unsigned int &numberOfMovies);
int removeMovie(Box &box, unsigned int &numberOfMovies);
int updateMovie(Box &box, unsigned int &numberOfMovies);
int rentMovie(Box &box, int movieNumber, bool seen, unsigned int &seenMovies, unsigned int &movieClub);
#endif
