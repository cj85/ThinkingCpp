#include<iostream>
using namespace std;

class widget{
	enum{count=4};
	void (widget::*fptr[count])(int);
public:

	void f(int){cout<<"widget::f"<<endl;};
	void g(int){cout<<"widget::g"<<endl;};
	void h(int ){cout<<"widget::h"<<endl;};
	void u(int){cout<<"widget::u"<<endl;};
	widget(){
		fptr[0]=&widget::f;
		fptr[1]=&widget::g;
		fptr[2]=&widget::h;
		fptr[3]=&widget::u;
	}
	void select(int i, int j){
		(this->*fptr[i])(j);
	}
	int Count(){
		return count;
	}
};


void pmep(){
	widget w;
	widget* wp=&w;
	void (widget::*pmem)(int)=&widget::h;
	(w.*pmem)(1);
	(wp->*pmem)(2);
	pmem=&widget::u;
	(w.*pmem)(3);
	(wp->*pmem)(4);
	cout<<"---------------------"<<endl;
	for(int i=0;i<w.Count();i++)
		w.select(i,47);
}