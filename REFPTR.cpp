#include<iostream>
using namespace std;
static void increment(int*& i){
	i++;
}

static void increment2(int* i){
	i++;
}

static void increment3(int**i){
	(*i)++;
}
void refptr(){
int*i=0;
cout<<"i="<<i<<endl;
increment(i);
cout<<"i="<<i<<endl;
increment2(i);
cout<<"i="<<i<<endl;
increment3(&i);
cout<<"i="<<i<<endl;
}
