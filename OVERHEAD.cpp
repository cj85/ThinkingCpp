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
总之，虚拟多重继
承不过是权益之计，在重视效率的情况下，应该保守地（或避免）使用它。*/
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