#include"COPYCONSTRUCT.h"
#include<iostream>
using namespace std;

CopyConstruct::CopyConstruct(){
	cout<<"constructor called"<<endl;
}

CopyConstruct::CopyConstruct(const CopyConstruct& cc){
	cout<<"copy constructor called"<<endl;
}

CopyConstruct::~CopyConstruct(){
cout<<"~CopyConstruct called"<<endl;
}
static void f(CopyConstruct c){

}

static CopyConstruct g(){
	CopyConstruct c;
	return c;
}
 void copyconstructor_test(){
	CopyConstruct c;
	cout<<"---------------"<<endl;
	f(c);
	cout<<"----------------"<<endl;
	g();
	cout<<"----------------"<<endl;
	c=g();
	cout<<"------------------"<<endl;
	CopyConstruct b=g();
}