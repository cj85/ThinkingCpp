#include<iostream>
#include<strstream>
#include "functions.h"
using namespace std;
#define SZ 100

void ostring(){
cout<<"type an int, a float and a string"<<endl;
int i;
float f;
cin>>i>>f;
cin>>ws;//throw away whitespace
char buf[SZ];
cin.getline(buf,SZ);
//cin.rdbuf(); //would be awkward

ostrstream os(buf,SZ,ios::app);
os<<endl;
os<<"integer="<<i<<endl;
os<<"float="<<f<<endl;
os<<ends;
cout<<buf;//����'\0'�ͽ�����
cout<<os.rdbuf()<<endl;//�����е�buf�����
cout<<os.tellp();
cout<<os.rdbuf();
}
