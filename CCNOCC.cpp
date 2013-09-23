#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
using namespace std;
class withCC{
public:
	withCC(){}
	withCC(const withCC& cc){
		cout<<"CC"<<endl;
	}
};

class woCC{
	enum{bsz=30};
	char buf[bsz];
public:
	woCC(const char* msg=0){
		memset(buf,0,bsz);
		if(msg) 
			strncpy(buf,msg,bsz);
	}
	void print(const char*msg=0)const{
		if(msg) cout<<msg<<": ";
		cout<<buf<<endl;
	}
};

class composite{
	withCC CC;
	woCC noCC;
public:
	composite():noCC("composite()"){}
	void print(const char* msg=0){
		noCC.print(msg);
	}
};

class composite2{
	withCC CC;
	woCC noCC;
public:
	composite2():noCC("composite2()"){}
	composite2(const composite2& c){}
	void print(const char* msg=0){
		noCC.print(msg);
	}
};

class composite3{
	withCC CC;
	woCC noCC;
public:
	composite3():noCC("composite3()"){}
	composite3(const composite3& c) :CC(c.CC),noCC(c.noCC){}
	void print(const char* msg=0){
		noCC.print(msg);
	}
};

class composite4{
	withCC CC;
	woCC noCC;
public:
	composite4():noCC("composite4()"){}
	composite4(const composite4& c) {CC=c.CC;noCC=c.noCC;}
	void print(const char* msg=0){
		noCC.print(msg);
	}
};


//总而言之，有cc就用cc，没有cc，编译器构造一个bitcopy的cc然后再用他
//就是要用cc

void ccnocc_test(){
cout<<"compoiste----------"<<endl;
 composite c;
 c.print("contents of c");
 cout<<"calling composite copy-constructor"<<endl;
 composite c2=c;
 c2.print("contents of c2");
cout<<"compoiste2----------"<<endl;
 composite2 d;
 composite2 d2=d;
 cout<<"compoiste3----------"<<endl;
  composite3  e;
 composite3 e2=e;
 cout<<"compoiste4----------"<<endl;
  composite4 f;
 composite4 f2=f;
 cout<<"another--------"<<endl;
 composite3 x;
 composite3 y;
 y=x;
}

