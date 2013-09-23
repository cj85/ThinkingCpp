#include<iostream>
#include<stdlib.h>

/*
����д�ĳ�������쳣ʱ�������ܻ��ʣ������쳣����ʱ�����ܱ������������𣿡���
��ʮ����Ҫ�ġ����ڴ����������������൱��ȫ�ģ�����������캯���г����쳣���⽫��
�����⣺����쳣�׳������ڹ��캯����������ʱ������������������޷���������Ӧ�Ķ���
����ζ���ڱ�д���캯���ĳ���ʱ����ʮ�ֽ�����
���캯�����д洢��Դ����ʱ�����ձ�����ѡ�������캯��������ʱ���쳣�׳�������
�������޷��ջ���Щ�洢��Դ����Щ��������������δ�ӱ�����ָ����
*/

namespace nudepNwrapped_space{
using namespace std;
class bonk{
public:
	bonk(){cout<<"bonk()"<<endl;}
	~bonk(){cout<<"~bonk()"<<endl;}
};

class og{
public:
	void* operator new(size_t sz){
		cout<<"allocating an og"<<endl;
		throw int(47);
		return 0;
	}
	void operator delete(void* p){
		cout<<"Deallocating an go"<<endl;
		::delete p;
	}
};

class useResources{
	bonk* bp;
	og* op;
public:
	useResources(int count=1){
		cout<<"useResources()"<<endl;
		bp=new bonk[count];
		op=new og;
	}
	~useResources(){
		cout<<"~useResources()"<<endl;
		delete[] bp;
		delete op;
	}
};
/*
Ϊ�˷�ֹ�����ᵽ�������Ӧ�������ͨ������Ĺ��캯�������������������걸�ġ���
Դ���䵽�����С��������ַ�����ÿ������ͱ����ԭ�ӵģ���һ�����󣬲������ʧ�ܣ���
ô�ѷ�����Դ�Ķ���Ҳ����ȷ�����������ģ�����޸�������һ���÷�����
*/

template<class T> class pwrap{
	T* ptr;
public:
	class rangeError{};// Exception class
	pwrap(){
		cout<<"pwrap constructor"<<endl;
	}
	void generate(int size=1){
		if(size==1){
			ptr=new T;
		}else{
			ptr=new T[size];
		}
	}
	~pwrap(){
		delete[] ptr;
		cout<<"~pwrap Deconstructor"<<endl;
	}
	T& operator[](int i) throw(rangeError){
		if(i>=0 && i<sz) return ptr[i];
		throw rangeError();
	}
};

class useResources1{
	pwrap<bonk> Bonk;
	pwrap<og>op;
public:
	useResources1(int count=1){
		cout<<"useResources1()"<<endl;
		Bonk.generate(3);
		op.generate();
	}
	~useResources1(){
		cout<<"~useResources1()"<<endl;
	}
};
}

void nudep(){
	using namespace nudepNwrapped_space;
	try{
		useResources ur(3);
	}catch(int){
		cout<<"inside handler"<<endl;
	}
}

void wrapped(){
	using namespace nudepNwrapped_space;
	try{
		useResources1 ur;
	}catch(int){
		cout<<"inside handler"<<endl;
	}
}