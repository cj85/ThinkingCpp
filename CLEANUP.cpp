//exceptions clean up objects
/*
�쳣����Ĳ����ѶȾ������쳣�׳�ʱ������������ת���쳣�������С�����쳣�׳�ʱ
����û�б���ȷ���������һ�������������Ч��C + +���쳣���������Ա�֤�������뿪һ��
������ʱ���������������нṹ�����Ķ���������������������ã��������Щ����
�������һ�����ӣ�������ʾ������Ĺ��캯��������ʱ�������������������ã���Ҳ��
��չʾ����ڱ�������������з����쳣�׳�ʱ������ʲô��������unexpected( )�����ٴ�
�׳�������쳣ʱ������ʲô�����
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<eh.h>

namespace cleanup_space{
	using namespace std;

	class noisy{
		static int i;
		int objnum;
		enum{sz=40};
		char name[sz];
	public:
		noisy(const char* nm="array elem")throw(int){
			objnum=i++;
			memset(name,0,sz);
			strncpy(name,nm,sz-1);
			cout<<"constructing noisy "<<objnum<<" name["<<name<<"]"<<endl;
			if(objnum==5) throw int(5);
			if(*nm=='z' ) throw char('z');
		}
		~noisy(){
			cout<<"destructing noisy "<<objnum<<" name["<<name<<"]"<<endl;
		}
		void* operator new[](size_t sz){
			cout<<"noisy::new[] "<<endl;
			return ::new char[sz];
		}
		void operator delete[](void*p){
			cout<<"noisy::delete[] "<<endl;
			::delete []p;
		}
	};

	int noisy::i=0;

	void unexpected_rethrow(){
		cout<<"inside unexpected_rethrow()"<<endl;
		throw;
	}
}

void cleanup(){
	using namespace cleanup_space;
	set_unexpected(unexpected_rethrow);
	try{
		noisy n1("before array");
		noisy* array=new noisy[7];
		noisy n2("after array");
	}catch(int i){
		cout<<"caught "<<i<<endl;
	}

	cout<<"testing unexpected: "<<endl;
	try{
		noisy n3("before unexpected");
		noisy n4("z");
		noisy n5("after unexpected");
	}catch(char c){
		cout<<"caught "<<c<<endl;
	}
}