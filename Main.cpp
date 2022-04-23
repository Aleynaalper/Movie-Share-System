#include <iostream>
#include "ReadFromFile.h"
using namespace std;

int main(int argc, const char *argv[]) {


    ReadFromFile readfromfile;
    readfromfile.command(argv[1],argv[2]);
    return 0;
}
