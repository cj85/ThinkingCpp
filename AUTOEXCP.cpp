//�쳣ƥ��
#include<iostream>

namespace autoexcp_space{
using namespace std;
class except1{};
class except2{
public:
	except2(except1&){}
};

static void f(){
	throw except1();
}

class trouble{};
class small:public trouble{};
class big: public trouble{};

static void g(){
	throw big();
}
}

void autoexept(){
	using namespace autoexcp_space;
	/*
	�������ǿ�����Ϊ��һ����������ʹ�ù��캯��ת������һ��e x c e p t 1����ת����e x c e p t 2
���󣬵���ϵͳ���쳣�����ڼ佫����ִ��������ת�������ǽ���e x c e p t 1����ֹ��
	*/
	try{
		f();
	}catch(except2){
		cout<<"except 2"<<endl;
	}catch(except1){
		cout<<"except 1"<<endl;
	}
	cout<<"-------------------------"<<endl;

	/*
	������쳣������ƣ����ڵ�һ������������ƥ��һ��t r o u b l e������t r o u b l e������ʲô
������ڵ�һ�������������漰�ڶ��͵����������������쳣�����Եڶ��͵�����������Զ
�������á��Ⲷ���������쳣�ѻ����һ���쳣����ĩ�˲����������
	*/
	try{
		g();
	}catch(trouble){
		cout<<"trouble"<<endl;
	}catch(big){
		cout<<"big"<<endl;
	}catch(small){
		cout<<"small"<<endl;
	}
}