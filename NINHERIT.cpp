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
	derived d2=d1;//CC ȷʵ���̳� ������ root(const root&)�����Զ���Ϊ derived(const derived&)
	//cout<<d1.s<<endl;//ok
	cout<<"d2.s="<<d2.s<<endl;//wrong  (CC ֻprint) //������� CC ��ͨ�������CC
	cout<<"d2.i="<<d2.i<<endl;
	cout<<"-------------"<<endl;
	//!derived d3(1);
	derived d4("d4",4);
	d4=d2;//��ʵ֤��derived::operator= ����ֱ�Ӽ̳������� root::operator= 
	cout<<"d4.s="<<d4.s<<endl; //�ⲿ�ֿ������ǣ�root��copy char* s ��ֵ��derivedҲ��copy
	cout<<"d4.i="<<d4.i<<endl;//�ⲿ�־�¶���ˣ�i ���ǳ�Ա��ֵ�� d4.i=d2.i
	cout<<"-------------"<<endl;
	f(d1);
	cout<<"-------------"<<endl;
}