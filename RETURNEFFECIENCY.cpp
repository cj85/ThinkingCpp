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
//����ֱ�ӽ�����f()����
	f();
	cout<<"-------------"<<endl;
	//��������g�������棬����CCŪ��ȥ
	g();
}