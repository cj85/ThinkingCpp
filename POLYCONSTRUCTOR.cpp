#include<iostream>
namespace polyconstructor_space{
using namespace std;
//C++���캯��û�ж�̬
//java ��
class base{
public:
	 base(){
		g();
	}
	 //���ӵĻ�
	 //base* p=new derived();
	//delete p; ����Ӱ��
	 //derived D; ������ζ�û��Ӱ�죬��Ϊ���Ƕ�̬
	 virtual~base(){
		h();
	}
	virtual void g()const{
		cout<<"base::g()"<<endl;
	}
	virtual void h()const{
		cout<<"base:: h()"<<endl;
	}
	//��ͨ�����Ϳ�����������overide k()������j(), ������Զ�call����ȷ��k();
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