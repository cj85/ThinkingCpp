/*

������ͨ��������Ա������ͨ���̳еķ�ʽ�������ǰ�һ������Ӷ���Ƕ��һ��������
ʱ�����������ÿһ���Ӷ��������¶����С���Ȼ��ÿһ���Ӷ������Լ���t h i sָ�룬�ڴ�
���Ա�����ʱ��������¾�򡣵���ֻҪ������ؼ̳У�һ����Ȥ������ͻ���֣����ڶ�
��������ӳ���ڼ���ֶ���࣬���������ڶ��t h i sָ�롣�������������������ӣ�

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