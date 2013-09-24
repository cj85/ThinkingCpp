//use fo set_terminate();

#include<iostream>
#include<stdlib.h>

namespace trmnator_space{
	using namespace std;
	void terminator(){
		cout<<"I'll be back"<<endl;
	}

	void (*old_terminate)()=set_terminate(terminator);
	class botch{
	public:
		class fruit{};
		void f(){
			cout<<"botch::f()"<<endl;
			throw fruit();
		}
		~botch(){
			throw 'c';
		}
	};
}

void trmnator(){
	using namespace trmnator_space;
	try{
		botch b;
		b.f();
	}catch(...){
		cout<<"inside catch(...)"<<endl;
	}
}