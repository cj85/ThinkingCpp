#define _CRT_SECURE_NO_WARNINGS 
#include "EFFECTOR.h"

fixw::fixw(const char*S,int width){
	s=(char*)malloc(width+1);
	assert(s);
	strncpy(s,S,width);
	s[width]=0;//NULL-terminate
}

fixw::~fixw(){free(s);}

ostream& operator <<(ostream& os, fixw& fw){
	return os<<fw.s;
}

bin::bin(ulong N){ n=N;}

ostream& operator<<(ostream& os, bin&b){
	ulong bit=~(ULONG_MAX>>1);
	while(bit){
		os<<(b.n&bit?'1':'0');
		bit>>=1;
	}
	return os;
}

void effector(){
 char* string="Things that make us happy, make us wise";
 for(int i=1;i<=(int)strlen(string);i++){
	cout<<fixw(string,i)<<endl;
 }
 ulong x=0xfedcba98UL;
 ulong y=0x76543210UL;
 cout<<"x in binary:"<<bin(x)<<endl;
 cout<<"y in binary:"<<bin(y)<<endl;
}