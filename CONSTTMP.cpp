#include"functions.h"
class X {
	int i;
public:
	X():i(10){}
	void modify(){
		i*=10;
	}
	void show()const{cout<<"x.i="<<i<<endl;}
};

static const X f(){return X();}
static const X& f2(){return X();}
static X f3(){return X();}
static void g1(X& x){x.modify();x.show();}
static void g2(const X&x){ x.show();}
static void g3(int i){i++;cout<<"i="<<i<<endl;}
void consttmp(){
	
	//f3()返回的不再是 常量临时变量
	X tmp=f2();
	g1(tmp);g1(f3());
	g2(tmp);
	g2(f());
	//const 的 primtive 已经可以传给非const 的函数了
	const int i=0;
	g3(i);
	const X x;
	g2(x);
	//g1(x);//Illegal

	//f()=X(); //Illegal
	//f().modify(); //Illegal
	g1(f3());
}
// 以下说的过时了！！
/*
函数f ( )返回类X的一个对象的值。这意味着立即取f ( )的返回值并把它传递给其他函数时
（正如g 1 ( )和g 2 ( )函数的调用），建立了一个临时变量，那个临时变量是常量。这样，函数g 1 ( )中
的调用是错误的，因为g 1 ( )不带一个常量（c o n s t）引用，但是函数g 2 ( )中的调用是正确的。
*/