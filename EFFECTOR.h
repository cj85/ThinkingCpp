#ifndef EFFECTOR_H_
#define EFFECTOR_H_
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<limits.h>
using namespace std;
//put out a portion of string
class fixw{
	char* s;
public:
	fixw(const char*S, int width);
	~fixw();
	friend ostream& operator<<(ostream&, fixw&);
};

typedef unsigned long ulong;
class bin{
	ulong n;
public:
	bin(ulong N);
	friend ostream& operator<<(ostream&,bin&);
};

void effector();
#endif