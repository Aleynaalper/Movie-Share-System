#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#ifndef READFROMFILE_H_
#define READFROMFILE_H_

using namespace std;

class ReadFromFile {
public:
    ReadFromFile();
    virtual ~ReadFromFile();
    void command(string path,string path2);
};

#endif /* READFROMFILE_H_ */
