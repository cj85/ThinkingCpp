/*

无论是通过创建成员对象还是通过继承的方式，当我们把一个类的子对象嵌入一个新类中
时，编译器会把每一个子对象置于新对象中。当然，每一个子对象都有自己的t h i s指针，在处
理成员对象的时候可以万事俱简。但是只要引入多重继承，一个有趣的现象就会出现：由于对
象在向上映射期间出现多个类，因而对象存在多个t h i s指针。下面就是这种情况的例子：

*/

#include<iostream>

namespace mithis_space{
	using namespace std;
	class base1{
		char c[0x10];
	public:
		void printthis1(){
			cout<<"base1 this="<<this<<endl;
		}
	};

	class base2{
		char c[0x10];
	public:
		void printthis2(){
			cout<<"base2 this="<<this<<endl;
		}
	};
	class member1{
		char c[0x10];
	public:
		void printthism1(){
			cout<<"member1 this="<<this<<endl;
		}
	};

	class member2{
		char c[0x10];
	public:
		void printthism2(){
			cout<<"member2 this="<<this<<endl;
		}
	};

	class mi:public base1,public base2{
		member1 m1;
		member2 m2;

	public:
		void printthis(){
			cout<<"mi this="<<this<<endl;
			printthis1();
			printthis2();
			m1.printthism1();
			m2.printthism2();
		}
	};


}

void mithis(){
	using namespace mithis_space;
	mi MI;

	cout<<"sizeof(mi)="<<hex<<sizeof(mi)<<" hex"<<endl;
	MI.printthis();
	// A second demonstration

	base1* b1=&MI;
	base2* b2=&MI;

	cout<<"base1 pointer="<<b1<<endl;
	cout<<"base2 pointer="<<b2<<endl;

}