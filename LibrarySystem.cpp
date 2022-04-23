#include "LibrarySystem.h"
#include "Writing.h"

#include <stdlib.h>

string title;   //I used this string to print the header once for repetitive commands
Writing writing;

struct checkoutMovie{  //Checked out movie Linked List in User Linked List
int movieId;
string movieTitle;
int year;
checkoutMovie* next;
};

struct notcheckoutMovie{ //Not checked out movie Linked List
int movieId;
string movieTitle;
int year;
notcheckoutMovie* next;
};
notcheckoutMovie* head1 = NULL;
notcheckoutMovie* tail1 = NULL;

struct User{  //User Linked List
int userId;
string userName;
checkoutMovie* movie;
User* next;
User* prev;
};
User* head = NULL;


LibrarySystem::LibrarySystem() {
}

LibrarySystem::~LibrarySystem() {
}

void LibrarySystem::addUser(const int userId, const string userName){

	//In this method, it is use to add a user. It checks that user has exist or not.

	   if(title!="addUser()"){
		   title="addUser()";
		   writing.writefile("\n==="+title+" method test===\n");
	   }

	   User* newuser=new User();

	   newuser->userId = userId;
	   newuser->userName=userName;

	   if(head==NULL){    //Situation that empty User Linked List
		   head=newuser;
		   newuser->next=newuser;
		   newuser->prev=newuser;
	   }
	   else{
		   User* iter=head;						//iter definition for User's head
		   if(iter->userId==userId){
			   writing.writefile("User "+to_string(userId)+" already exists\n");
			   return;
			   }
		   	iter=iter->next;
		   	while(iter!=head){
		   		if(iter->userId==userId){
		   			writing.writefile("User "+to_string(userId)+" already exists\n");
		   			return;
		   			}
		   			iter=iter->next;
		   		}
		   newuser->next=head;      //Object definition
		   newuser->prev=head->prev;
		   head->prev->next=newuser;
		   head->prev=newuser;
		   head=newuser;

	   }
	   writing.writefile("User "+to_string(userId)+" has been added\n");

	}

void LibrarySystem::deleteUser(const int userId){
	User* iter=head;			//iter definition for User's head

		if(title!="deleteUser()"){
			title="deleteUser()";

			writing.writefile("\n==="+title+" method test===\n");
	   }
		if(head==NULL){       ////Situation that empty User Linked List
			writing.writefile("User "+to_string(userId)+" does not exist\n");
			return;
		}
		if(iter->userId==userId){
			if(head==head->next){
				head=NULL;
				free(iter);
				writing.writefile("User "+to_string(userId)+" has been deleted\n");
				return;
			}
			writing.writefile("User "+to_string(userId)+" has been deleted\n");
			if(iter->movie!=NULL){
				free(iter->movie);
				}
			iter->next->prev=iter->prev;
			iter->prev->next=iter->next;
			head=head->next;
			free(iter);
			return;
		}
		iter=iter->next;
		while(iter!=head){
			if(iter->userId==userId){
				writing.writefile("User "+to_string(userId)+" has been deleted\n");
				if(iter->movie!=NULL){
					free(iter->movie);
					}
				iter->next->prev=iter->prev;
			    iter->prev->next=iter->next;
				free(iter);
				return;
			}
			iter=iter->next;
		}
		writing.writefile("User "+to_string(userId)+" does not exist\n");


}

void LibrarySystem::addMovie(const int movieId, const string movieTitle, const int year){
	 notcheckoutMovie* newmovie=new notcheckoutMovie();

	 if(title!="addMovie()"){
		   title="addMovie()";
		   writing.writefile("\n==="+title+" method test===\n");
	   }
	 User* root=head;      //root definition for User's head
	 if(root!=NULL){
		 if(root->movie!=NULL){
			 struct checkoutMovie* root2=root->movie;
			 if(root2->movieId==movieId){
				 writing.writefile("Movie "+to_string(movieId)+" already exists\n");
				 return;
			 }
			 root2=root2->next;
			 while(root2!=root->movie){
				 if(root2->movieId==movieId){
					 writing.writefile("Movie "+to_string(movieId)+" already exists\n");
					 return;
				 }
				 root2=root2->next;
			 }
		 }
		 root=root->next;
		 while(root!=head){
			 if(root->movie!=NULL){
				 struct checkoutMovie* root2=root->movie;
				 if(root2->movieId==movieId){
					 writing.writefile("Movie "+to_string(movieId)+" already exists\n");
					 return;
				 }
				 root2=root2->next;
				 while(root2!=root->movie){
					 if(root2->movieId==movieId){
						 writing.writefile("Movie "+to_string(movieId)+" already exists\n");
						 return;
					 }
					 root2=root2->next;
				 }
		 }
		root=root->next;
	 }
	 }
	 newmovie->movieId=movieId;
	 newmovie->movieTitle=movieTitle;
	 newmovie->year=year;

	if(head1==NULL){
		head1=newmovie;
		tail1=newmovie;
		head1->next=newmovie;
	}
	else{
		notcheckoutMovie* iter=head1;
		if(iter->movieId==movieId){
			writing.writefile("Movie "+to_string(movieId)+" already exists\n");
			return;
			}
			iter=iter->next;
			while(iter!=head1){
				if(iter->movieId==movieId){
					writing.writefile("Movie "+to_string(movieId)+" already exists\n");
					return;
					}
					iter=iter->next;
				}
		newmovie->next=head1;
		tail1->next=newmovie;
		head1=newmovie;

	}
	//Prints following this situation, if it doesn't meet any of the above conditions.
	writing.writefile("Movie "+to_string(movieId)+" has been added\n");
}


void LibrarySystem::deleteMovie(const int movieId){

	if(title!="deleteMovie()"){
			   title="deleteMovie()";
			   writing.writefile("\n==="+title+" method test===\n");
		   }

	notcheckoutMovie* iter=head1;    //iter definition for Not check out Linked List.
	 if(iter!=NULL){
		   if(iter->movieId==movieId){
			   if(head1==head1->next){
				   head1=NULL;
				   tail1=NULL;
				   writing.writefile("Movie "+to_string(iter->movieId)+" has not been checked out\n");
				   writing.writefile("Movie "+to_string(iter->movieId)+" has been deleted\n");
				   free(iter);   //With free, it deletes summoned elements.
				   return;
			   	   }
			   tail1->next=head1->next;
			   head1=head1->next;
			   writing.writefile("Movie "+to_string(iter->movieId)+" has not been checked out\n");
			   writing.writefile("Movie "+to_string(iter->movieId)+" has been deleted\n");
			   free(iter);
			   return;
			}
		   notcheckoutMovie* previous=iter;  //This object, it uses to find previous element of iter.
		   iter=iter->next;
		   while(iter!=head1){
			   if(iter->movieId==movieId){
				   if(iter==tail1){
					   tail1=previous;
					   tail1->next=head1;
					   writing.writefile("Movie "+to_string(iter->movieId)+" has not been checked out\n");
					   writing.writefile("Movie "+to_string(iter->movieId)+" has been deleted\n");
					   free(iter);
					   return;
				   }
				   writing.writefile("Movie "+to_string(iter->movieId)+" has not been checked out\n");
				   writing.writefile("Movie "+to_string(iter->movieId)+" has been deleted\n");
				   previous->next=iter->next;
				   free(iter);
				   return;
					}
			   iter=iter->next;
			   previous=previous->next;
		   }
	   }
	 User* iter2=head;  //iter2 definition for User Linked List.
	 if(iter2!=NULL){
		struct checkoutMovie* iter3=iter2->movie;  //iter3 definition for Check out Movie Linked List.
		if(iter3!=NULL){
			if(iter3->movieId==movieId){
				struct checkoutMovie* last=iter3;
				while(last->next!=iter2->movie){
					last=last->next;
					}
				if(last==iter2->movie){
					iter2->movie=NULL;
					writing.writefile("Movie "+to_string(iter3->movieId)+" has been checked out\n");
				    writing.writefile("Movie "+to_string(iter3->movieId)+" has been deleted\n");
					free(iter3);
					return;
					}
				last->next=iter3->next;
				iter2->movie=iter3->next;
				writing.writefile("Movie "+to_string(iter3->movieId)+" has been checked out\n");
				writing.writefile("Movie "+to_string(iter3->movieId)+" has been deleted\n");
				free(iter3);
				return;
			}
			struct checkoutMovie* previous=iter3; //This object, it uses to find previous element of iter.
			iter3=iter3->next;
			while(iter3!=iter2->movie){
				if(iter3->movieId==movieId){
					previous->next=iter3->next;
					writing.writefile("Movie "+to_string(iter3->movieId)+" has been checked out\n");
					writing.writefile("Movie "+to_string(iter3->movieId)+" has been deleted\n");
					free(iter3);
					return;
				}
				previous=previous->next;
				iter3=iter3->next;
			}
		}
		iter2=iter2->next;
		while(iter2!=head){
			struct checkoutMovie* iter4=iter2->movie;  //iter4 definition for Check out Movie Linked List.
					if(iter4!=NULL){
						if(iter4->movieId==movieId){
							struct checkoutMovie* last=iter4;
							while(last->next!=iter2->movie){//This object, it uses to find last element of movie of iter2.
								last=last->next;
								}
							if(last==iter2->movie){
								iter2->movie=NULL;
								writing.writefile("Movie "+to_string(iter4->movieId)+" has been checked out\n");
								writing.writefile("Movie "+to_string(iter4->movieId)+" has been deleted\n");
								free(iter4);
								return;
							}
							last->next=iter4->next;
							iter2->movie=iter4->next;
							writing.writefile("Movie "+to_string(iter4->movieId)+" has been checked out\n");
							writing.writefile("Movie "+to_string(iter4->movieId)+" has been deleted\n");
							free(iter4);
							return;
						}
						struct checkoutMovie* previous=iter4; //This object, it uses to find previous element of iter4.
						iter4=iter4->next;
						while(iter4!=iter2->movie){
							if(iter4->movieId==movieId){
								previous->next=iter4->next;
								writing.writefile("Movie "+to_string(iter4->movieId)+" has been checked out\n");
								writing.writefile("Movie "+to_string(iter4->movieId)+" has been deleted\n");
								free(iter4);
								return;
							}
							previous=previous->next;
							iter4=iter4->next;
						}
					}
					iter2=iter2->next;
				}
			}
			writing.writefile("Movie "+to_string(movieId)+" not exist\n");
}


void LibrarySystem::checkoutMovie(const int movieId, const int userId){

	if(title!="checkoutMovie()"){
	   title="checkoutMovie()";
	   writing.writefile("\n==="+title+" method test===\n");
   }

	User* iter=head;  //iter definition for User Linked List.
	bool control=true;
	if(iter==NULL){
		writing.writefile("User "+to_string(userId)+" does not exist for checkout\n");
		return;
	}
	else{
		if(iter->userId!=userId){
			iter=iter->next;
			while(iter!=head){
				if(iter->userId==userId){
					control=false;
					break;
					}
				iter=iter->next;
			}
		}
		else{
			control=false;
		}
	}
	if(control){
		writing.writefile("User "+to_string(userId)+" does not exist for checkout\n");
		return;
	}

	notcheckoutMovie* iter2=head1; ////iter2 definition for Not Check out Movie Linked List.
	if(iter2==NULL){
		writing.writefile("Movie "+to_string(movieId)+" does not exist for checkout\n");
	}
	else{
		if(iter2->movieId==movieId){
			tail1->next=iter2->next;
			head1=tail1->next;
			struct checkoutMovie* newmovie =new struct checkoutMovie();
			newmovie->movieId=iter2->movieId;
			newmovie->movieTitle=iter2->movieTitle;
			newmovie->year=iter2->year;
			free(iter2);

			struct checkoutMovie* iter3=iter->movie;  //iter3 definition for Check out Movie Linked List.
			if(iter3==NULL){
				iter->movie=newmovie;
				iter->movie->next=iter->movie;
				writing.writefile("Movie "+to_string(movieId)+" has been checked out by User "+to_string(userId)+"\n");
				return;
			}
			else{
                if(iter->movie->next==iter->movie) {
                    newmovie->next=iter->movie;
                    iter->movie->next=newmovie;
                    iter->movie=newmovie;
                    writing.writefile("Movie "+to_string(movieId)+" has been checked out by User "+to_string(userId)+"\n");
                    return;
                }
				newmovie->next=iter->movie->next;
				iter->movie=newmovie;
				writing.writefile("Movie "+to_string(movieId)+" has been checked out by User "+to_string(userId)+"\n");
				return;
			}
		}
		else{
			notcheckoutMovie* previous=iter2;
			iter2=iter2->next;
			while(iter2!=head1){
				if(iter2->movieId==movieId){
					if(iter2==tail1){
						tail1=previous;
						tail1->next=head1;
						struct checkoutMovie* newmovie =new struct checkoutMovie();
						newmovie->movieId=iter2->movieId;
						newmovie->movieTitle=iter2->movieTitle;
						newmovie->year=iter2->year;
						free(iter2);

						struct checkoutMovie* iter3=iter->movie;
							if(iter3==NULL){
								iter->movie=newmovie;
								iter->movie->next=iter->movie;
								writing.writefile("Movie "+to_string(movieId)+" has been checked out by User "+to_string(userId)+"\n");
								return;
							}
							else{
                                if(iter->movie->next==iter->movie) {
                                    newmovie->next=iter->movie;
                                    iter->movie->next=newmovie;
                                    iter->movie=newmovie;
                                    writing.writefile("Movie "+to_string(movieId)+" has been checked out by User "+to_string(userId)+"\n");
                                    return;
                                }
								newmovie->next=iter->movie->next;
								iter->movie=newmovie;
								writing.writefile("Movie "+to_string(movieId)+" has been checked out by User "+to_string(userId)+"\n");
								return;
							}
					}
					else{
						previous->next=iter2->next;
						struct checkoutMovie* newmovie =new struct checkoutMovie();
							newmovie->movieId=iter2->movieId;
							newmovie->movieTitle=iter2->movieTitle;
							newmovie->year=iter2->year;
							free(iter2);

							struct checkoutMovie* iter3=iter->movie;
								if(iter3==NULL){
									iter->movie=newmovie;
									iter->movie->next=iter->movie;
									writing.writefile("Movie "+to_string(movieId)+" has been checked out by User "+to_string(userId)+"\n");
									return;
								}
								else{
								    if(iter->movie->next==iter->movie) {
								        newmovie->next=iter->movie;
								        iter->movie->next=newmovie;
								        iter->movie=newmovie;
								        writing.writefile("Movie "+to_string(movieId)+" has been checked out by User "+to_string(userId)+"\n");
                                        return;
								    }
									newmovie->next=iter->movie;
									iter->movie=newmovie;
									writing.writefile("Movie "+to_string(movieId)+" has been checked out by User "+to_string(userId)+"\n");
									return;
								}
							}
						}
				previous=previous->next;
				iter2=iter2->next;
				}
			}
		}
	    writing.writefile("Movie "+to_string(movieId)+" does not exist for checkout\n");
	}



void LibrarySystem::showUser(const int userId){

	if(title!="showUser()"){
				   title="showUser()";
				   writing.writefile("\n==="+title+" method test===\n");
			   }

	User* iter=head;
	if(iter->userId==userId){
		writing.writefile("User id: "+to_string(userId)+" User name: "+iter->userName+"\n");
		writing.writefile("User "+to_string(userId)+" checked out the following Movies:\n");
		if(iter->movie!=NULL){
			writing.writefile("Movie id - Movie name - Year - Status\n");
			struct checkoutMovie* iter2=iter->movie;
			writing.writefile(to_string(iter2->movieId)+" "+iter2->movieTitle+" "+to_string(iter2->year)+"\n");
			iter2=iter2->next;
			while(iter2!=iter->movie){
				writing.writefile(to_string(iter2->movieId)+" "+iter2->movieTitle+" "+to_string(iter2->year)+"\n");
				iter2=iter2->next;
			}
		}
	}
	iter=iter->next;
	while(iter!=head){
		if(iter->userId==userId){
			writing.writefile("User id: "+to_string(userId)+" User name: "+iter->userName+"\n");
			writing.writefile("User "+to_string(userId)+" checked out the following Movies:\n");
			if(iter->movie!=NULL){
				writing.writefile("Movie id - Movie name - Year - Status\n");
				struct checkoutMovie* iter2=iter->movie;
				writing.writefile(to_string(iter2->movieId)+" "+iter2->movieTitle+" "+to_string(iter2->year)+"\n");
				iter2=iter2->next;
				while(iter2!=iter->movie){
					writing.writefile(to_string(iter2->movieId)+" "+iter2->movieTitle+" "+to_string(iter2->year)+"\n");
					iter2=iter2->next;
				}
			}
		}
		iter=iter->next;
	}
}
void LibrarySystem::showAllMovie(){

    title="showAllMovie()";
    writing.writefile("\n==="+title+" method test===\n");

    writing.writefile("Movie id - Movie name - Year - Status\n");

	notcheckoutMovie* iter=head1;
	    if(iter!=NULL)  {
	       writing.writefile(to_string(iter->movieId)+" "+iter->movieTitle+" "+to_string(iter->year)+" Not checked out\n");
		   iter=iter->next;
		   while(iter!=head1){
			   writing.writefile(to_string(iter->movieId)+" "+iter->movieTitle+" "+to_string(iter->year)+" Not checked out\n");
			   iter=iter->next;
			   }
	   }

	User* iter2=head;
	if(iter2!=NULL){
		if(iter2->movie!=NULL){
			struct checkoutMovie* iter3=iter2->movie;
			writing.writefile(to_string(iter3->movieId)+" "+iter3->movieTitle+" "+to_string(iter3->year)+" Checked out by User "+to_string(iter2->userId)+"\n");
						iter3=iter3->next;
						while(iter3!=iter2->movie){
							writing.writefile(to_string(iter3->movieId)+" "+iter3->movieTitle+" "+to_string(iter3->year)+" Checked out by User "+to_string(iter2->userId)+"\n");
							iter3=iter3->next;
						}
					}
			iter2=iter2->next;
			while(iter2!=head){
				if(iter2->movie!=NULL){
					struct checkoutMovie* iter3=iter2->movie;
					writing.writefile(to_string(iter3->movieId)+" "+iter3->movieTitle+" "+to_string(iter3->year)+" Checked out by User "+to_string(iter2->userId)+"\n");
								iter3=iter3->next;
								while(iter3!=iter2->movie){
									writing.writefile(to_string(iter3->movieId)+" "+iter3->movieTitle+" "+to_string(iter3->year)+" Checked out by User "+to_string(iter2->userId)+"\n");
									iter3=iter3->next;
								}
						}
					iter2=iter2->next;
				}
         }
	}

void LibrarySystem::showMovie(const int movieId){
	if(title!="showMovie()"){
			   title="showMovie()";
			   writing.writefile("\n==="+title+" method test===\n");
		   }

	notcheckoutMovie* iter=head1;
		   if(iter!=NULL){
			   if(iter->movieId==movieId){
				   writing.writefile(to_string(iter->movieId)+" "+iter->movieTitle+" "+to_string(iter->year)+" Not checked out\n");
				   return;
				}
			   iter=iter->next;
			   while(iter!=head1){
				   if(iter->movieId==movieId){
					   writing.writefile(to_string(iter->movieId)+" "+iter->movieTitle+" "+to_string(iter->year)+" Not checked out\n");
				   return;
					}
				   iter=iter->next;
			   }
		   }

	User* iter2=head;
	if(iter2!=NULL){
		if(iter2->movie!=NULL){
			struct checkoutMovie* iter3=iter2->movie;
			if(iter3->movieId==movieId){
				writing.writefile(to_string(iter3->movieId)+" "+iter3->movieTitle+" "+to_string(iter3->year)+" Checked out by User "+to_string(iter2->userId)+"\n");
				return;
			}
			iter3=iter3->next;
			while(iter3!=iter2->movie){
				if(iter3->movieId==movieId){
					writing.writefile(to_string(iter3->movieId)+" "+iter3->movieTitle+" "+to_string(iter3->year)+" Checked out by User "+to_string(iter2->userId)+"\n");
					return;
				}
				iter3=iter3->next;
			}
		}
			iter2=iter2->next;
			while(iter2!=head){
				if(iter2->movie!=NULL){
					struct checkoutMovie* iter3=iter2->movie;
					if(iter3->movieId==movieId){
						writing.writefile(to_string(iter3->movieId)+" "+iter3->movieTitle+" "+to_string(iter3->year)+" Checked out by User "+to_string(iter2->userId)+"\n");
						return;
					}
					iter3=iter3->next;
					while(iter3!=iter2->movie){
						if(iter3->movieId==movieId){
							writing.writefile(to_string(iter3->movieId)+" "+iter3->movieTitle+" "+to_string(iter3->year)+" Checked out by User "+to_string(iter2->userId)+"\n");
							return;
						}
						iter3=iter3->next;
					}
						}
					iter2=iter2->next;
				}
			}
		writing.writefile("Movie with the id "+to_string(movieId)+" does not exits\n");
     }

void LibrarySystem::returnmovie_adding(const int movieId, const string movieTitle, const int year){
	notcheckoutMovie* newmovie=new notcheckoutMovie();

		 newmovie->movieId=movieId;
		 newmovie->movieTitle=movieTitle;
		 newmovie->year=year;

		if(head1==NULL){
			head1=newmovie;
			tail1=newmovie;
			head1->next=newmovie;
		}
		else{
			newmovie->next=head1;
			tail1->next=newmovie;
			head1=newmovie;
		}
}


void LibrarySystem::returnMovie(const int movieId){

	if(title!="returnMovie()"){
				   title="returnMovie()";
				   writing.writefile("\n==="+title+" method test===\n");
			   }

	notcheckoutMovie* iter=head1;
	if(iter!=NULL){
		if(iter->movieId==movieId){
			writing.writefile("Movie "+to_string(movieId)+" has not been checked out\n");
			return;
			}
		iter=iter->next;
		while(iter!=head1){
			if(iter->movieId==movieId){
				writing.writefile("Movie "+to_string(movieId)+" has not been checked out\n");
				return;
				}
			iter=iter->next;
		}
	}
	User* iter2=head;
	if(iter2!=NULL){
		struct checkoutMovie* iter3=iter2->movie;
		if(iter3!=NULL){
			if(iter3->movieId==movieId){
				struct checkoutMovie* last=iter3;
				while(last->next!=iter2->movie){
					last=last->next;
					}
				if(last==iter2->movie){
					iter2->movie=NULL;
					writing.writefile("Movie "+to_string(movieId)+" has been returned\n");
					free(iter3);
					return;
					}
				last->next=iter3->next;
				iter2->movie=iter3->next;
				returnmovie_adding(iter3->movieId,iter3->movieTitle,iter3->year);
				free(iter3);
				writing.writefile("Movie "+to_string(movieId)+" has been returned\n");
				return;
			}
			struct checkoutMovie* previous=iter3;
			iter3=iter3->next;
			while(iter3!=iter2->movie){
				if(iter3->movieId==movieId){
					previous->next=iter3->next;
					returnmovie_adding(iter3->movieId,iter3->movieTitle,iter3->year);
					free(iter3);
					writing.writefile("Movie "+to_string(movieId)+" has been returned\n");
					return;
				}
				previous=previous->next;
				iter3=iter3->next;
			}
		}
		iter2=iter2->next;
		while(iter2!=head){
			struct checkoutMovie* iter4=iter2->movie;
					if(iter4!=NULL){
						if(iter4->movieId==movieId){
							struct checkoutMovie* last=iter4;
							while(last->next!=iter2->movie){
								last=last->next;
								}
							if(last==iter2->movie){
								iter2->movie=NULL;
								writing.writefile("Movie "+to_string(movieId)+" has been returned\n");
								free(iter4);
								return;
								}
							last->next=iter4->next;
							iter2->movie=iter4->next;
							returnmovie_adding(iter4->movieId,iter4->movieTitle,iter4->year);
							free(iter4);
							writing.writefile("Movie "+to_string(movieId)+" has been returned\n");
							return;
						}
						struct checkoutMovie* previous=iter4;
						iter4=iter4->next;
						while(iter4!=iter2->movie){
							if(iter4->movieId==movieId){
								previous->next=iter4->next;
								returnmovie_adding(iter4->movieId,iter4->movieTitle,iter4->year);
								free(iter4);
								writing.writefile("Movie "+to_string(movieId)+" has been returned\n");
								return;
							}
							previous=previous->next;
							iter4=iter4->next;
						}
					}
					iter2=iter2->next;
				}
			}
			writing.writefile("Movie "+to_string(movieId)+" not exist in the library\n");

}
void LibrarySystem::beginning(string a,string path2){  //This part is used to define output path and write a first title.
	writing.define(path2);
	writing.writefile(a);
}


