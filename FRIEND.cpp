//thinking in c++ p46
#define _CRT_SECURE_NO_WARNINGS 	
struct X;

struct Y{
	void f(X*);
};

struct X{
private:
	int i;
public:
	void initialize();
	friend void g(X*, int); //Global friend
	//编译不过，估计是版本问题
	//TODO
	friend void Y::f(X*x);// Struct member friend
	friend struct Z;// Entire struct is a friend
	friend void h();
};

void X::initialize(){i=0;}

void g(X*x,int i){x->i=i;}

void Y::f(X* x){x->i=47;}

struct Z{
private:
	int j;
public :
	void initialize();
	void g(X* x);
};

void Z::initialize(){j=99;}

void Z::g(X* x){x->i+=j;}

void h(){
	X x;
	x.i=100;
}

void friendtest(){
	X x;
	Z z;
	z.g(&x);
	
}