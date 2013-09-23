#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
/*
d 1和d 2在它们的构造函数中都必须对b a s e初始化，这和我们想象的一样。但m i和x也都如
此，尽管它们和b a s e相隔好几个层次。这是因为每一个都能成为最晚辈派生类。编译器是无法
知道使用d 1初始化b a s e还是使用d 2的，因而我们总是被迫在最晚辈派生类中具体指出。注意，
仅仅这个被选中的虚基构造函数被调用。*/
namespace multipl3_space{
using namespace std;
class base{
public:
	base(int){}
	virtual char* vf() const=0;
};

class d1:virtual public base{
public:
	d1():base(1){}
	virtual char* vf() const{
		return "d1";
	};
};

class d2:virtual public base{
public:
	d2():base(2){}
	virtual char* vf() const{
		return "d2";
	};
};

class mi: public d1, public d2{
public:
	mi():base(3){}
	char* vf()const{
		return strcat("mi: ",d1::vf());
	}
};

class x:public mi{
public:
//!	x():mi(){}
	x():base(4){}//必须这样写
};

//所以虚基类可以这样写
class bbase{
public:
	bbase(int i=1){}
	virtual void f()=0;
};
//调用默认构造函数
class dd1:virtual public bbase{
public:
	void f(){}
};
class dd2:virtual public bbase{
public:
	void f(){}
} ;
class mmi:public dd1, public dd2{
public:
	void f(){}
};
}

void multipl3(){
	using namespace multipl3_space;
base *b=new d1();
cout<<b->vf()<<endl;
bbase* bb=new mmi();
bb->f();
}