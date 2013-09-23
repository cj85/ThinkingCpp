/*
s e t j m p ( )是一个特别的函数，因为如果我们直接调用它，它就把当前进程状态的所有相关
信息存放在j m p _ b u f中，并返回零。这样，它的行为象通常的函数。然而，如果使用同一个
j m p b u f调用l o n g j m p ( )，这就象再次从s e t j m p ( )返回，即正确地弹出s e t j m p ( )的后端。这时，返
回值对于l o n g j m p ( )是第二个参数，所以能发现实际上从l o n g j m p ( )中返回了。可以想象，有多个
不同的j m p b u f，可以弹出程序的多个不同位置的信息。局部g o t o（用标号）和这个非局部跳
转的不同在于我们能通过s e t j m p / l o n g j m p跳转到任何地方（一些限制不在这里讨论）。
在C++中的问题是，longjmp()不适用于对象，特别是，当它跳出范围时它不调用析构函数[1]。
析构函数调用是必须的，所以这种方法在C++中不可行。
*/

//话擦。。。居然调用了~rainbow（）。。
#include<iostream>
#include<setjmp.h>
namespace c_approach_space{
using namespace std;
class rainbow{
public:
	rainbow(){cout<<"rainbow()"<<endl;}
	~rainbow(){cout<<"~rainbow()"<<endl;}
};

jmp_buf kansas;

void OZ(){
	rainbow RB;
	for(int i=0;i<3;i++){
		cout<<"there's no place like home"<<endl;
	}
	longjmp(kansas,47);
}
}

void c_approach(){
	using namespace c_approach_space;
	if(setjmp(kansas)==0){
		cout<<"tornado, witch, munchkins...."<<endl;
		OZ();
	}else{
		cout<<"Auntie em! I had the strangest dream..."<<endl;
	}
}