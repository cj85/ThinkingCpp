class base1{
public:
	char f() const{return 'a';}
	int g() const {return 2;}
	float h() const{ return (float)4.1;}
};

class derived : private base1{
public:
	base1::f;
	base1::h;
};

void privinh(){
	derived d;
	d.f();
	d.h();
	//!d.g(); //error-- private functions
}