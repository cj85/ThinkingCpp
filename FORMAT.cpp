#include<iostream>
#include<fstream>
#include "functions.h"
using namespace std;
#define D(a) T<<#a<<endl; a
ofstream T("format.out");

void format(){
	D(int i=47;)
	D(float f=(float)2300114.414159;)
	char* s= "Is there any more?";

	D(T.setf(ios::unitbuf);)
	D(T.setf(ios::_Stdio);)

	D(T.setf(ios::showbase);)
	D(T.setf(ios::uppercase);)
	D(T.setf(ios::showpos);)
	D(T<<i<<endl;)//default to dec
	D(T.setf(ios::hex,ios::basefield);)
	D(T<<i<<endl;)
	D(T.unsetf(ios::uppercase);)
	D(T.setf(ios::oct,ios::basefield);)
	D(T<<i<<endl;)
	D(T.unsetf(ios::showbase);)
	D(T.setf(ios::dec,ios::basefield);)
	D(T.setf(ios::left,ios::adjustfield);)
	D(T.fill('0');)
	D(T<<"fill char:"<<T.fill()<<endl;)
	D(T.width(10);)
	T<<i<<endl;
	D(T.setf(ios::right,ios::adjustfield);)
	D(T.width(10);)
	D(T.setf(ios::internal,ios::adjustfield);)
	D(T.width(10);)
	T<<i<<endl;
	D(T<<i<<endl;)

	D(T.unsetf(ios::showpos);)
	D(T.setf(ios::showpoint);)
	D(T<<"prec="<<T.precision()<<endl;)
	D(T.setf(ios::scientific,ios::floatfield);)
	D(T<<endl<<f<<endl;)
	D(T.setf(ios::fixed,ios::floatfield);)
    D(T<<f<<endl;)
	D(T.setf(0,ios::floatfield);)//Automatic
	D(T<<f<<endl;)
	D(T.precision(20);)
	D(T<<"prec="<<T.precision()<<endl;)
	D(T<<endl<<f<<endl;)
	D(T.setf(ios::scientific,ios::floatfield);)
	D(T<<endl<<f<<endl;)
	D(T.setf(ios::fixed,ios::floatfield);)
	D(T<<f<<endl;)
	D(T.setf(0,ios::floatfield);)
	D(T<<f<<endl;)

	D(T.width(10);)
	T<<s<<endl;
	D(T.width(40);)
	T<<s<<endl;
	D(T.setf(ios::left,ios::adjustfield);)
	D(T.width(40);)
	T<<s<<endl;

	D(T.unsetf(ios::showpoint);)
	D(T.unsetf(ios::unitbuf);)
	D(T.unsetf(ios::_Stdio);)

}