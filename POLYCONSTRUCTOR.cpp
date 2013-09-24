#include<iostream>
namespace polyconstructor_space{
using namespace std;
//C++构造函数没有多态
//java 有
class base{
public:
	 base(){
		g();
	}
	 //不加的话
	 //base* p=new derived();
	//delete p; 会受影响
	 //derived D; 无论如何都没有影响，因为不是多态
	 virtual~base(){
		h();
	}
	virtual void g()const{
		cout<<"base::g()"<<endl;
	}
	virtual void h()const{
		cout<<"base:: h()"<<endl;
	}
	//普通函数就可以在子类里overide k()而不动j(), 子类会自动call到正确的k();
	virtual void j()const{
		k();
	}
	virtual void k()const{
		cout<<"base:k()"<<endl;
	}
};

class derived: public base{
public:
	void g()const{
		cout<<"derived::g()"<<endl;
	}
	void h()const{
		cout<<"derived::h()"<<endl;
	}
	void k() const{
		cout<<"derived::k()"<<endl;
	}
	derived(){
		cout<<"derived()"<<endl;
	}

	~derived(){
		cout<<"~derived()"<<endl;
	}
};
}
void polyconstructor(){
	using namespace polyconstructor_space;
derived D;
cout<<"----------------"<<endl;
base* p=new derived();
p->j();
delete p;
}