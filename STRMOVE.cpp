#include<iostream>
#include<strstream>
#include "functions.h"

using namespace std;

void strmove(){
	ostrstream s;
	cout<<(void*)s.str()<<endl;//δ�����ַ�ǰ=0��������ʼ����ʱ�ſ�ʼ����
	s.rdbuf()->freeze(0);
	s<<"hi";
	char* old=s.str();
	s.rdbuf()->freeze(0);
	for(int i=0;i<1000;i++){
		s<<"howdy hello hi pig n chick";
	}
	cout<<"old="<<(void*)old<<endl;
	cout<<"new="<<(void*)s.str()<<endl;
	delete s.str();
}