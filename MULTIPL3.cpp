#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
/*
d 1��d 2�����ǵĹ��캯���ж������b a s e��ʼ����������������һ������m i��xҲ����
�ˣ��������Ǻ�b a s e����ü�����Ρ�������Ϊÿһ�����ܳ�Ϊ���������ࡣ���������޷�
֪��ʹ��d 1��ʼ��b a s e����ʹ��d 2�ģ�����������Ǳ����������������о���ָ����ע�⣬
���������ѡ�е�������캯�������á�*/
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
	x():base(4){}//��������д
};

//����������������д
class bbase{
public:
	bbase(int i=1){}
	virtual void f()=0;
};
//����Ĭ�Ϲ��캯��
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