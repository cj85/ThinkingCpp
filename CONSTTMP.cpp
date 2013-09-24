#include"functions.h"
class X {
	int i;
public:
	X():i(10){}
	void modify(){
		i*=10;
	}
	void show()const{cout<<"x.i="<<i<<endl;}
};

static const X f(){return X();}
static const X& f2(){return X();}
static X f3(){return X();}
static void g1(X& x){x.modify();x.show();}
static void g2(const X&x){ x.show();}
static void g3(int i){i++;cout<<"i="<<i<<endl;}
void consttmp(){
	
	//f3()���صĲ����� ������ʱ����
	X tmp=f2();
	g1(tmp);g1(f3());
	g2(tmp);
	g2(f());
	//const �� primtive �Ѿ����Դ�����const �ĺ�����
	const int i=0;
	g3(i);
	const X x;
	g2(x);
	//g1(x);//Illegal

	//f()=X(); //Illegal
	//f().modify(); //Illegal
	g1(f3());
}
// ����˵�Ĺ�ʱ�ˣ���
/*
����f ( )������X��һ�������ֵ������ζ������ȡf ( )�ķ���ֵ���������ݸ���������ʱ
������g 1 ( )��g 2 ( )�����ĵ��ã���������һ����ʱ�������Ǹ���ʱ�����ǳ���������������g 1 ( )��
�ĵ����Ǵ���ģ���Ϊg 1 ( )����һ��������c o n s t�����ã����Ǻ���g 2 ( )�еĵ�������ȷ�ġ�
*/