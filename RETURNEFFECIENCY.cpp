#include<iostream>
using namespace std;

class ReturnEffeciency{
	const char* function;
public:
	ReturnEffeciency(const char* s):function(s){
		cout<<function<<" constructor"<<endl;
	}
	ReturnEffeciency(const ReturnEffeciency& c):function(c.function){
		cout<<function<<"  CC"<<endl;
	}
	~ReturnEffeciency(){
		cout<<function<<" de-constructor"<<endl;
	}
};
static ReturnEffeciency f(){
	return ReturnEffeciency("f");
}

static ReturnEffeciency g(){
	ReturnEffeciency tmp("g");
	return tmp;
}
void returnEffeciency(){
//对象直接建立在f()外面
	f();
	cout<<"-------------"<<endl;
	//对象建立在g（）里面，再用CC弄出去
	g();
}