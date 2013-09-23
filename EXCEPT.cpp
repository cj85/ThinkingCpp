//basic exceptions
//Exception specification & unexpected()

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string>
#include<eh.h>
namespace except_space{
	using namespace std;
	class up{};
	class fit{};
	void g();

	void f(int i) throw (up,fit){
		switch(i){
			case 1: throw up();
			case 2: throw fit();
		}
		g();
	}

	void g()throw (fit){
		throw 47;//can throw built-in types
	}

	void my_unexpected(){
		cout<<"unexpected exception thrown";
		exit(1);
	}
}
//我去？ my_unexpected 没奏效？
void except(){
	using namespace except_space;
	set_unexpected(my_unexpected);
	for(int i=1;i<=3;i++){
		try{
			f(i);
		}catch(up){
			cout<<"up caught"<<endl;
		}catch(fit){
			cout<<"fit caught"<<endl;
		}
		catch(...){
			cout<<"all exception will be caught here"<<endl;
		}
	}


}