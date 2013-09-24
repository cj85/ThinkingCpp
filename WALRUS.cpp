#include <iostream>
#include <strstream>
#include "functions.h"
using namespace std;


void walrus(){
	ostrstream s;
	s<<"'The time has come', the walrus said, ";
	s<<ends;
	cout<<s.str()<<endl; //String is frozen
	//s is frozen; destructor won't delete
	//the streambuf storage on the heap
	s.seekp(-1,ios::cur);
	s.rdbuf()->freeze(0); //unfreeze it
	//now destructor release memory, and
	//you can add more character 
	//but you'd better not use the previous str() value
	s<<" 'To speak of many things'"<<ends;
	cout<<s.rdbuf();
}