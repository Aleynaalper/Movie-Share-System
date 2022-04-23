
#ifndef CONTROL_H_
#define CONTROL_H_
#include <iostream>
using namespace std;


class Control {
public:
	Control();
	virtual ~Control();
	void controlling(string controlarray[4],string path2);
};

#endif /* CONTROL_H_ */
