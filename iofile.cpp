#include "functions.h"
#include<iostream>
#include<fstream>
using namespace std;
void iofile(){
	ifstream in("iofile.cpp");
	ofstream out("iofile.out");
	out<<in.rdbuf();
	in.close();
	out.close();
	//open for reading and writing
	ifstream in2("iofile.out",ios::in|ios::out);
	ostream out2(in2.rdbuf());
	cout<<in2.rdbuf();
	out2<<"where dose this end up?";
	out2.seekp(0,ios::beg);
	out2<<"And what about this?";//¸²¸ÇÎÄ±¾£¡
	in2.seekg(0,ios::beg);
	cout<<in2.rdbuf();
}