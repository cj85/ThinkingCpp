#include<iostream>
using namespace std;


class one{
public:
	one(){}
};

class two{
public:
	two(const one&){
		cout<<"two(const one&) called"<<endl;
	}
};

class three{
	
	three(const one&){
		cout<<"three(const one&)"<<endl;
	}
public:
	three(){}
};

class four{
public:
	four(){}
	explicit four(const one&){
		cout<<"four(const one&) called"<<endl;
	}
	operator three() const{//另一种自动转换的方法
		return three();
	}
};

static void f(two){

}
static void g(three){
}
static void h(four){
}
static void u(three){
}
void autuocnt(){
	one One;
	f(One);//wants a two, has a one
	//!g(One);
	//!h(One);
	four Four;
	u(Four);
}