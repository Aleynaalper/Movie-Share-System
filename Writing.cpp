#include "Writing.h"

Writing::Writing() {
}
Writing::~Writing() {
}
string text;

void Writing::define(string path2){
	text=path2;

}
void Writing::writefile(string line){

	ofstream outfile;

	outfile.open(text, ios_base::app);		//it crates new text file that name is output.txt
	outfile << line;								//it prints each element it takes as a parameter to text file

	}

