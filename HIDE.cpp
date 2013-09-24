////如果在基类中有一个函数名被重载几次，在派生类中重定义这个函数名会掩盖所有基类版
//本，这也就是说，它们在派生类中变得不再可用。
//java 没有
class homer{
public:
	int doh(int) const {return 1;}
	char doh(char) const{return 'd';}
	float doh(float) const{return (float)1.1;}
};

class bart:public homer{
public:
	class milhouse{};
	void doh(milhouse)const{}
};

void hide(){
	bart b;
	//b.doh(1);
	//b.doh('x');
	//b.doh(1.0);
}