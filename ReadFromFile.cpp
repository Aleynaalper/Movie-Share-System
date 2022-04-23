#include "ReadFromFile.h"
#include "Control.h"

ReadFromFile::ReadFromFile() {
}
ReadFromFile::~ReadFromFile() {
}

void ReadFromFile::command(string path,string path2){
   ifstream file(path);
    if(!file){
        cerr <<"File couldn't find" << endl;
        exit(1);
    }
    while(file){
        string controlarray[4];
        string name;

        getline(file,name);

        int l=name.length();

        char commandarray[l + 1];   //to using strtok , I converted string to char array
        char split[]="	";
        strcpy(commandarray, name.c_str());
        char *token=strtok(commandarray,split);

        int i=0;
        while(token){
            controlarray[i]=token;      //to find which command, I define every element into the array after separating it with spaces
            token = strtok(NULL,split);
            i++;
        }

        Control control;
        control.controlling(controlarray,path2);
   }
}
