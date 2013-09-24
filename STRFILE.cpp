//Stream I/O with files
//the difference between get() & getline()
#include<iostream>
#include<fstream>
#include<assert.h>
#include "functions.h"
#define SZ 100
using namespace std;
void strfile_test(){
	char buf[SZ];
	{
		//不区分大小写
		ifstream in("strfile.cpp");
		assert(in);
		ofstream out("strfile.out");
		assert(out);
		int i=1;
		while(in.get(buf,SZ)){
			in.get();//Throw away next character(\n)
			cout<<buf<<endl;
			out<<i++<<": "<<buf<<endl;
		}
	}
	ifstream in("strfile.out");
	assert(in);
	while(in.getline(buf,SZ)){
		char* p=buf;
		while(*p!=':')
			p++;
		p+=2;//pass ': '
		cout<<p<<endl;
	}
}