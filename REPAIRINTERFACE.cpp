#include<iostream>
/*
使用多重继承的最好的理由之一是使用控制之外的代码。假定已经拥有了一个由头文件和
已经编译的成员函数组成的库，但是没有成员函数的源代码。该库是具有虚函数的类层次，它
含有一些使用库中基类指针的全局函数，这就是说它多态地使用库对象。现在，假定我们围绕
着该库创建了一个应用程序并且利用基类的多态方式编写了自己的代码。
在随后的项目开发或维护期间，我们发现基类接口和供应商所提供的不兼容：我们所需要
的是某虚函数而可能提供的却是非虚的，或者对于解决我们的问题的基本虚函数在接口中根本
不存在。假若有源代码则可以返回去修改，但是我们没有，我们有大量的依赖最初接口的已生
成的代码，这时多重继承则是极好的解决方法。
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
	在我们的项目中，这些源代码是不能得到的，而我们得到的是已编译过的V E N D O R . O B J
或V E N D O R . L I B文件（或系统中相应的等价物）。
使用该库会产生问题。首先析构函数不是虚的，这实际上是创建者的一个设计错误。另外，
f ( )也不是虚的，这可能是库的创建者认为没有必要。但是我们会发现基类接口失去了解决前述
问题的必要能力。假若我们已经使用已存在的接口（不包含函数A ( )和B ( )，因为它们不受控制）
编制了大量代码，而且并不打算改变它。
为了补救该问题，我们可以创建自己的类接口以及从我们的接口和已存在的类中进行多重
继承，以便生成一批新类：

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