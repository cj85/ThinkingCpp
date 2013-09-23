#include<fstream>
#include<iostream>
#include<assert.h>
#include"functions.h"
using namespace std;

void seeking(){
	ifstream in("seeking.cpp");
	assert(in);
	in.seekg(0,ios::end);
	streampos sp=in.tellg();  //size of the file
	cout<<"file size = "<<sp<<endl;
	in.seekg(-sp/10,ios::end);
	streampos sp2= in.tellg();
	in.seekg(0,ios::beg);
	cout<<in.rdbuf();//print entire file
	in.seekg(sp2);
	cout<<endl<<endl<<in.rdbuf()<<endl;
}
