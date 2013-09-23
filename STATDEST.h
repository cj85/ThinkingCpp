#ifndef STATDEST_H_
#define STATDEST_H_

#include<fstream>
using namespace std;

static ofstream out("statdest.out");

class Statdest{
char c;
public:
	Statdest(char C):c(C){
		out<<"Statdest::Statdest() for "<<c<<endl;
	}
	~Statdest(){
		out<<"Statdest::~Statdest() for "<<c<<endl;
	}
};

void statdest();

#endif // !STATDEST_H_

