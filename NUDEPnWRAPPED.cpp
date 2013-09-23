#include<iostream>
#include<stdlib.h>

/*
当编写的程序出现异常时，我们总会问：“当异常出现时，这能被合理地清除掉吗？”这
是十分重要的。对于大多数情况，程序是相当安全的；但是如果构造函数中出现异常，这将产
生问题：如果异常抛出发生在构造函数创建对象时，对象的析构函数将无法调用其相应的对象。
这意味着在编写构造函数的程序时必须十分谨慎。
构造函数进行存储资源分配时存在普遍的困难。如果构造函数在运行时有异常抛出，析构
函数将无法收回这些存储资源。这些问题大多数发生在未加保护的指针上
*/

namespace nudepNwrapped_space{
using namespace std;
class bonk{
public:
	bonk(){cout<<"bonk()"<<endl;}
	~bonk(){cout<<"~bonk()"<<endl;}
};

class og{
public:
	void* operator new(size_t sz){
		cout<<"allocating an og"<<endl;
		throw int(47);
		return 0;
	}
	void operator delete(void* p){
		cout<<"Deallocating an go"<<endl;
		::delete p;
	}
};

class useResources{
	bonk* bp;
	og* op;
public:
	useResources(int count=1){
		cout<<"useResources()"<<endl;
		bp=new bonk[count];
		op=new og;
	}
	~useResources(){
		cout<<"~useResources()"<<endl;
		delete[] bp;
		delete op;
	}
};
/*
为了防止上文提到的情况，应避免对象通过本身的构造函数和析构函数将“不完备的”资
源分配到对象中。利用这种方法，每个分配就变成了原子的，像一个对象，并且如果失败，那
么已分配资源的对象也被正确地清除。采用模板是修改上例的一个好方法：
*/

template<class T> class pwrap{
	T* ptr;
public:
	class rangeError{};// Exception class
	pwrap(){
		cout<<"pwrap constructor"<<endl;
	}
	void generate(int size=1){
		if(size==1){
			ptr=new T;
		}else{
			ptr=new T[size];
		}
	}
	~pwrap(){
		delete[] ptr;
		cout<<"~pwrap Deconstructor"<<endl;
	}
	T& operator[](int i) throw(rangeError){
		if(i>=0 && i<sz) return ptr[i];
		throw rangeError();
	}
};

class useResources1{
	pwrap<bonk> Bonk;
	pwrap<og>op;
public:
	useResources1(int count=1){
		cout<<"useResources1()"<<endl;
		Bonk.generate(3);
		op.generate();
	}
	~useResources1(){
		cout<<"~useResources1()"<<endl;
	}
};
}

void nudep(){
	using namespace nudepNwrapped_space;
	try{
		useResources ur(3);
	}catch(int){
		cout<<"inside handler"<<endl;
	}
}

void wrapped(){
	using namespace nudepNwrapped_space;
	try{
		useResources1 ur;
	}catch(int){
		cout<<"inside handler"<<endl;
	}
}