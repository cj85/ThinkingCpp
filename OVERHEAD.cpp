#include<iostream>

namespace overhead_space{
using namespace std;
class base{
public:
	virtual void f() const{};
};

class NVI:public base{};
class VI:virtual public base{};
class VI2:virtual public base{};

class mi:public VI, public VI2{};

#define WRITE(arg) \
	cout<<#arg<<" = "<<arg<<endl;

}

void overhead(){

	/*
��֮��������ؼ�
�в�����Ȩ��֮�ƣ�������Ч�ʵ�����£�Ӧ�ñ��صأ�����⣩ʹ������*/
	using namespace overhead_space;
	base b;
	WRITE(sizeof(b));
	NVI nvi;
	WRITE(sizeof(nvi));
	VI vi;
	WRITE(sizeof(vi));
	mi MI;
	WRITE(sizeof(MI));
}