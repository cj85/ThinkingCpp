//异常匹配
#include<iostream>

namespace autoexcp_space{
using namespace std;
class except1{};
class except2{
public:
	except2(except1&){}
};

static void f(){
	throw except1();
}

class trouble{};
class small:public trouble{};
class big: public trouble{};

static void g(){
	throw big();
}
}

void autoexept(){
	using namespace autoexcp_space;
	/*
	尽管我们可能认为第一个处理器会使用构造函数转化，将一个e x c e p t 1对象转化成e x c e p t 2
对象，但是系统在异常处理期间将不会执行这样的转换，我们将在e x c e p t 1处终止。
	*/
	try{
		f();
	}catch(except2){
		cout<<"except 2"<<endl;
	}catch(except1){
		cout<<"except 1"<<endl;
	}
	cout<<"-------------------------"<<endl;

	/*
	这里的异常处理机制，对于第一个处理器总是匹配一个t r o u b l e对象或从t r o u b l e派生的什么
事物，由于第一个处理器捕获涉及第二和第三处理器的所有异常，所以第二和第三处理器永远
不被调用。光捕获派生类异常把基类的一般异常放在末端捕获更有意义
	*/
	try{
		g();
	}catch(trouble){
		cout<<"trouble"<<endl;
	}catch(big){
		cout<<"big"<<endl;
	}catch(small){
		cout<<"small"<<endl;
	}
}