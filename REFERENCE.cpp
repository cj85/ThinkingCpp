#include<iostream>
using namespace std;

static int * f(int *x){
(*x)++;
return x; //safe; x is outside this scope
}

static int& g(int &x){
x++;
return x;//safe; x is outside this scope
}

static void g2(const int &x){

	
}

static int&  h(){
	int q=1;
	//�����Ǵ��󣬶���������a��ֵȷʵ��a��
	//
	return q;
	/*static int x;
	return x;*/
}



void reference(){
	int a=0;
	a=h();
	const int b=3;

	//g(1);	
	g2(1);
	cout<<"a="<<a<<endl;
}