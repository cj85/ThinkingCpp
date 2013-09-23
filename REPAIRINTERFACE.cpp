#include<iostream>
/*
ʹ�ö��ؼ̳е���õ�����֮һ��ʹ�ÿ���֮��Ĵ��롣�ٶ��Ѿ�ӵ����һ����ͷ�ļ���
�Ѿ�����ĳ�Ա������ɵĿ⣬����û�г�Ա������Դ���롣�ÿ��Ǿ����麯�������Σ���
����һЩʹ�ÿ��л���ָ���ȫ�ֺ����������˵����̬��ʹ�ÿ�������ڣ��ٶ�����Χ��
�Ÿÿⴴ����һ��Ӧ�ó��������û���Ķ�̬��ʽ��д���Լ��Ĵ��롣
��������Ŀ������ά���ڼ䣬���Ƿ��ֻ���ӿں͹�Ӧ�����ṩ�Ĳ����ݣ���������Ҫ
����ĳ�麯���������ṩ��ȴ�Ƿ���ģ����߶��ڽ�����ǵ�����Ļ����麯���ڽӿ��и���
�����ڡ�������Դ��������Է���ȥ�޸ģ���������û�У������д�������������ӿڵ�����
�ɵĴ��룬��ʱ���ؼ̳����Ǽ��õĽ��������
*/
namespace repairinterface_space{
/************************************************** 
* VENDOR.H--vendor-supplied class header        *
* you only get this & the compiled VENDOR.OBJ *
***************************************************/
	class vendor{
	public:
		virtual void v() const;
		void f() const;
		~vendor();
	};
	class vendor1: public vendor{
	public:
		void v() const;
		void f() const;
		~vendor1();
	};

	void A(const vendor&);
	void B(const vendor&);

	/***************************************************
	* VENDOR.CPP--implementation of VENDOR.H   *
	* This is compiled and unavailable to you              *
	***************************************************/

	using namespace std;
	void vendor::v() const{
		cout<<"vendor::v()"<<endl;
	}
	void vendor::f() const{
		cout<<"vendor::f()"<<endl;
	}
	vendor::~vendor( ){
		cout<<"~vendor()"<<endl;
	}

	void vendor1::v() const{
		cout<<"vendor1::v()"<<endl;
	}
	void vendor1::f() const{
		cout<<"vendor1::f()"<<endl;
	}
	vendor1::~vendor1( ){
		cout<<"~vendor1()"<<endl;
	}

	void A(const vendor& V){
		V.v();
		V.f();
	}

	void B(const vendor* V){
		V->v();
		V->f();
	}

	/*
	�����ǵ���Ŀ�У���ЩԴ�����ǲ��ܵõ��ģ������ǵõ������ѱ������V E N D O R . O B J
��V E N D O R . L I B�ļ�����ϵͳ����Ӧ�ĵȼ����
ʹ�øÿ��������⡣������������������ģ���ʵ�����Ǵ����ߵ�һ����ƴ������⣬
f ( )Ҳ������ģ�������ǿ�Ĵ�������Ϊû�б�Ҫ���������ǻᷢ�ֻ���ӿ�ʧȥ�˽��ǰ��
����ı�Ҫ���������������Ѿ�ʹ���Ѵ��ڵĽӿڣ�����������A ( )��B ( )����Ϊ���ǲ��ܿ��ƣ�
�����˴������룬���Ҳ�������ı�����
Ϊ�˲��ȸ����⣬���ǿ��Դ����Լ�����ӿ��Լ������ǵĽӿں��Ѵ��ڵ����н��ж���
�̳У��Ա�����һ�����ࣺ

	*/


	/****************************************
	*    PASTE.CPP--Fixing a mess with MI *
	****************************************/

	class mybase{//repair vendor interface
	public:
		virtual void v()const =0;
		virtual void f()const =0;
		// new interface function:
		virtual void g() const =0;
		virtual ~mybase(){ cout<<"~mybase()"<<endl;}
	};

	class paste1: public mybase, public vendor1{
	public:
		void v()const{
			cout<<"paset1::v()      ";
			vendor1::v();
		}
		void f()const{
			cout<<"pase1::f()        ";
			vendor1::f();
		}
		void g()const {
			cout<<"pase1::g() "<<endl;
		}
		~paste1(){
			cout<<"~paste1()"<<endl;
		}
	};
}

void repairinterface(){
	using namespace repairinterface_space;
	paste1& p1p=*new paste1;  //upcast
	mybase& mp=p1p;
	cout<<"calling v()-------------------"<<endl;
	mp.v();//right behavior
	p1p.v();
	cout<<"calling f()-------------------"<<endl;
	mp.f();//right behavior
	p1p.f();
	cout<<"calling g()-------------------"<<endl;
	mp.g();//new behavior
	cout<<"calling A(p1p)---------------"<<endl;
	A(p1p); //same old behavior
	cout<<"calling B(&p1p)---------------"<<endl;
	B(&p1p); //same old behavior
	cout<<"delete mp--------------------"<<endl;
	delete &mp;//right behavior
}