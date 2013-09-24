//format.cpp -- using manipulators
#include<fstream>
#include<iomanip>
#include"functions.h"

using namespace std;
void manips(){
	ofstream T("trace.out");
	int i=47;
	float f=(float)2300114.414159;
	char *s="Is there any more?";

	T<<setiosflags(ios::unitbuf|ios::_Stdio|ios::showbase
		|ios::uppercase|ios::showpos);

	T<<i<<endl;
	T<<hex<<i<<endl;
	T<<resetiosflags(ios::uppercase)<<oct<<i<<endl;
	T.setf(ios::left,ios::adjustfield);
	T<<resetiosflags(ios::showbase)<<dec<<setfill('0');
	T<<"file char:"<<T.fill()<<endl;
	T<<setw(10)<<i<<endl;
	T.setf(ios::right,ios::adjustfield);
	T<<setw(10)<<i<<endl;
	T.setf(ios::internal,ios::adjustfield);
	T<<setw(10)<<i<<endl;
	T<<i<<endl;//without setw(10)

	T<<resetiosflags(ios::showpos)<<setiosflags(ios::showpoint)
		<<"prec="<<T.precision()<<endl;
	T.setf(ios::scientific,ios::floatfield);
	T<<f<<endl;
	T.setf(ios::fixed,ios::floatfield);
	T<<f<<endl;
	T.setf(0,ios::floatfield);//Automatic
	T<<f<<endl;
	T<<setprecision(20);
	T<<"prec="<<T.precision()<<endl;
	T<<f<<endl;
	T.setf(ios::scientific,ios::floatfield);
	T<<f<<endl;
	T.setf(ios::fixed,ios::floatfield);
	T<<f<<endl;
	T.setf(0,ios::floatfield);//Automatic
	T<<f<<endl;

	T<<setw(10)<<s<<endl;
	T<<setw(40)<<s<<endl;
	T.setf(ios::left,ios::adjustfield);
	T<<setw(40)<<s<<endl;

	T<<resetiosflags(ios::showpoint|ios::unitbuf|ios::_Stdio);

}