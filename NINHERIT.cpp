#include<iostream>
using namespace std;

class root{
public:
	const char* s;
	root(char * S):s(S){}
	root(){cout<<"Root Constructor"<<endl;}
	root(const root& r):s(r.s){cout<<"Root CC"<<endl;}
	root(int){cout<<"Root INT C"<<endl;}
	root& operator=(const root& r){cout<<"Root::="<<endl;return *this;}
	class other{};
	operator other(){cout<<"Root->other"<<endl;return other();}
	~root(){cout<<"~root()"<<endl;}
};

class derived:public root{
public:
	int i;
	derived(const char* S,int I):i(I){
		root::s=S;
	}
};

static void f(root::other){}

void ninherit(){
	root r1("r1");
	root r2("r2");
	r1=r2;
	cout<<"r1.s="<<r1.s<<endl;
	cout<<"--------------"<<endl;
	derived d1("d1",1);
	cout<<"-------------"<<endl;
	derived d2=d1;//CC 确实不继承 估计是 root(const root&)不能自动成为 derived(const derived&)
	//cout<<d1.s<<endl;//ok
	cout<<"d2.s="<<d2.s<<endl;//wrong  (CC 只print) //正常输出 CC 做通常意义的CC
	cout<<"d2.i="<<d2.i<<endl;
	cout<<"-------------"<<endl;
	//!derived d3(1);
	derived d4("d4",4);
	d4=d2;//事实证明derived::operator= 不是直接继承了上面 root::operator= 
	cout<<"d4.s="<<d4.s<<endl; //这部分开起来是，root不copy char* s 的值，derived也不copy
	cout<<"d4.i="<<d4.i<<endl;//这部分就露馅了，i 就是成员赋值了 d4.i=d2.i
	cout<<"-------------"<<endl;
	f(d1);
	cout<<"-------------"<<endl;
}