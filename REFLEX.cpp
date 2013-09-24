class number{
	int i;
public:
	number(int I=0){i=I;}
	const number operator+(const number&n)const{
		return number(i+n.i);
	}
	friend const number operator-(const number& n1, const number& n2){
		return number(n1.i-n2.i);
	}
};

void reflex(){
	number a(47),b(11);
	a+b;
	a+1;//2nd arg converted to number
	//!1+a;  //wrong! 1st arg not of type number
	a-b;
	a-1;
	1-a;
	
	// both args convert to number
}