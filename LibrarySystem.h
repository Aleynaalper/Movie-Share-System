#ifndef LIBRARYSYSTEM_H_
#define LIBRARYSYSTEM_H_
#include <iostream>
using namespace std;

class LibrarySystem {
public:
	LibrarySystem();
	virtual ~LibrarySystem();


	void addMovie(const int movieId, const string movieTitle, const int year);
	void deleteMovie(const int movieId);

	void addUser(const int userId, const string userName);
	void deleteUser(const int userId);

	void checkoutMovie(const int movieId, const int userId);
	void returnMovie(const int movieId);
	void returnmovie_adding(const int movieId, const string movieTitle, const int year);

	void showAllMovie();
	void showMovie(const int movieId);
	void showUser(const int userId);

	void beginning(string a,string path2);

};

#endif /* LIBRARYSYSTEM_H_ */
