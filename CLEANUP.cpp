//exceptions clean up objects
/*
异常处理的部分难度就在于异常抛出时从正常程序流转入异常处理器中。如果异常抛出时
对象没有被正确地清除，这一操作将不会很有效。C + +的异常处理器可以保证当我们离开一个
作用域时，该作用域中所有结构完整的对象的析构函数都将被调用，以清除这些对象。
这里给出一个例子，用以演示当对象的构造函数不完整时其析构函数将不被调用，它也用
来展示如果在被创建对象过程中发生异常抛出时将出现什么结果，如果unexpected( )函数再次
抛出意外的异常时将出现什么结果：
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<eh.h>

namespace cleanup_space{
	using namespace std;

	class noisy{
		static int i;
		int objnum;
		enum{sz=40};
		char name[sz];
	public:
		noisy(const char* nm="array elem")throw(int){
			objnum=i++;
			memset(name,0,sz);
			strncpy(name,nm,sz-1);
			cout<<"constructing noisy "<<objnum<<" name["<<name<<"]"<<endl;
			if(objnum==5) throw int(5);
			if(*nm=='z' ) throw char('z');
		}
		~noisy(){
			cout<<"destructing noisy "<<objnum<<" name["<<name<<"]"<<endl;
		}
		void* operator new[](size_t sz){
			cout<<"noisy::new[] "<<endl;
			return ::new char[sz];
		}
		void operator delete[](void*p){
			cout<<"noisy::delete[] "<<endl;
			::delete []p;
		}
	};

	int noisy::i=0;

	void unexpected_rethrow(){
		cout<<"inside unexpected_rethrow()"<<endl;
		throw;
	}
}

void cleanup(){
	using namespace cleanup_space;
	set_unexpected(unexpected_rethrow);
	try{
		noisy n1("before array");
		noisy* array=new noisy[7];
		noisy n2("after array");
	}catch(int i){
		cout<<"caught "<<i<<endl;
	}

	cout<<"testing unexpected: "<<endl;
	try{
		noisy n3("before unexpected");
		noisy n4("z");
		noisy n5("after unexpected");
	}catch(char c){
		cout<<"caught "<<c<<endl;
	}
}