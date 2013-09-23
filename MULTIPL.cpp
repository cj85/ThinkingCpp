#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

namespace multipl_space{
using namespace std;
class base{
public:
	virtual char* vf()const=0;
};

class d1 :virtual public base{
public:
	
	char* vf()const{
		return "d1";
	}
};

class d2:virtual public base{
public:
	char* vf() const{
		return "d2";
	}
};

class mi: public d1,public d2{
	char* vf() const{
		char* a=new char[20];
		memset(a,0,20);
		strcat(a,"mi: ");
		strcat(a,d1::vf());
		return a;
	}
};

class dd1 : public base{
public:
	
	char* vf()const{
		return "dd1";
	}
};

class dd2: public base{
public:
	char* vf() const{
		return "dd2";
	}
};

class mmi:virtual public dd1, virtual public dd2{
public:
	char* vf()const{return "o l ";}
};
}

 void multipl(){
	using namespace multipl_space;
	base* b[3];
	b[0]=new d1();
	b[1]=new d2();
	b[2]=new mi();
	for(int i=0;i<3;i++){
		cout<<b[i]->vf()<<endl;
		cout<<"-----------"<<endl;
	}

	base *a;
	mmi* m=new mmi();
//!	a=new mmi();
}