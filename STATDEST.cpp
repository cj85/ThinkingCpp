#include "STATDEST.h"
#include<iostream>
using namespace std;
Statdest A('A');

static void f(){
	static Statdest B('B');
}

static void g(){
	static Statdest C('C');
}

 void statdest(){
	out<<"inside statdest()"<<endl;
	f();
	out<<"leaving statdest()"<<endl;
}