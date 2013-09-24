#include<iostream>
using namespace std;

class base{
public:
	virtual void f()const =0;
	virtual void g()const=0{
		cout<<"base::g()"<<endl;
	}
};

void base::f()const{
	cout<<"base::f()"<<endl;
}

class derived :public base
{
public:
	void f()const{
		base::f();
		cout<<"gaga"<<endl;
	}
	void g()const {
		base::g();
		cout<<"gaga"<<endl;
	}
};

void pvdef(){
	derived D;
D.f();
D.g();
}