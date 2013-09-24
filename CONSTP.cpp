#include "functions.h"
static void t(int*){}

static void u(const int* cip){
	//!*cip=2;
	int i=*cip;
	//!int* ip2=cip;
}

static const char* v(){
	return "result of functions";
}

static const int* const w(){
	static int i;
	return &i;
}
static  int*  w2(){
	static int i;
	return &i;
}

void constp(){
	int x=0;
	int* ip=&x;
	const int* cip=&x;
	t(ip);
	//!t(cip);
	u(ip);
	u(cip);
	//!char* cp=v();
	const char* ccp=v();
	//!int* ip2=w();
	const int* cip2=w();
	//!*w()=1;
	int i=1;

}