#include "Writing.h"
#include "Control.h"
#include "LibrarySystem.h"

int starting=0;

Control::Control() {
}
Control::~Control() {
}

//in this class, I checked every line to find which command

void Control::controlling(string controlarray[4],string path2){
	LibrarySystem librarysystem;
	if(starting==0){
		librarysystem.beginning("===Movie Library System===\n",path2);
		starting++;
		//I used this algorithm to write file only one times
	}

	if(controlarray[0]=="addUser"){
		int userId=stoi(controlarray[1]);
		librarysystem.addUser(userId, controlarray[2]);
	}

	else if(controlarray[0]=="deleteUser"){
		int userId=stoi(controlarray[1]);
		librarysystem.deleteUser(userId);
	}

	else if(controlarray[0]=="addMovie"){
		int movieId=stoi(controlarray[1]);
		int year=stoi(controlarray[3]);
		librarysystem.addMovie(movieId, controlarray[2], year);
	}

	else if(controlarray[0]=="showAllMovie"){
		librarysystem.showAllMovie();
		}

	else if(controlarray[0]=="checkoutMovie"){
		int movieId=stoi(controlarray[1]);
		int userId=stoi(controlarray[2]);
		librarysystem.checkoutMovie(movieId, userId);
		}

	else if(controlarray[0]=="showMovie"){
		int movieId=stoi(controlarray[1]);
		librarysystem.showMovie(movieId);

		}

	else if(controlarray[0]=="showUser"){
		int userId=stoi(controlarray[1]);
		librarysystem.showUser(userId);
		}

	else if(controlarray[0]=="deleteMovie"){
		int movieId=stoi(controlarray[1]);
		librarysystem.deleteMovie(movieId);

		}

	else if(controlarray[0]=="returnMovie"){
		int movieId=stoi(controlarray[1]);
		librarysystem.returnMovie(movieId);

	    }
}


