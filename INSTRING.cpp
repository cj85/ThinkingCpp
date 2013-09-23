#include"functions.h"
#include <strstream>
#include <iostream>
using namespace std;
void instring(){
	istrstream s("1.414 47 This is a test");
	int i;
	float f;
	s>>i>>f; //whitspace- delimited input
	char buf2[100];
	s>>buf2;
	cout<<"i= "<<i<<", f= "<<f;
	cout<<" buf2= "<<buf2<<endl;
	cout<<s.rdbuf()<<endl;
	cout<<s.tellg();
}