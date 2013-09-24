#include<fstream>
#include<iostream>

namespace persist1_space{
using namespace std;

class persistent{
int objSize;
public:
	persistent(int sz):objSize(sz){
	}
	void write(ostream& out)const{
		out.write((char*)this,objSize);
	}
	void read(istream& in){
		in.read((char*)this,objSize);
	}
};

class data{
	double d[3];
public:
	data(double d1=0.0,double d2=0.0,double d3=0.0){
		d[0]=d1;
		d[1]=d2;
		d[2]=d3;
	}
	void print(const char* msg=""){
		if(*msg) cout<<msg<<"   ";
		for(int i=0;i<3;i++){
			cout<<"d["<<i<<"]="<<d[i]<<endl;
		}
	}
};

class wdata1: public persistent,public data{
public:
	wdata1(double d1=0.0,double d2=0.0,double d3=0.0):data(d1,d2,d3),persistent(sizeof(wdata1)){}
};

class wdata2: public data,public persistent{
public:
	wdata2(double d1=0.0,double d2=0.0,double d3=0.0):data(d1,d2,d3),persistent(sizeof(wdata2)){}
};
}

void persist1(){
	using namespace persist1_space;
	{
		ofstream f1("f1.dat"), f2("f2.dat");
		wdata1 d1(1.1,2.2,3.3);
		wdata2 d2(4.4,5.5,6.6);
		d1.print("d1 before storage");
		d2.print("d2 before storage");
		d1.write(f1);
		d2.write(f2);
	}//close files
	ifstream f1("f1.dat"),f2("f2.dat");
	wdata1 d1;
	wdata2 d2;
	d1.read(f1);
	d2.read(f2);

	d1.print("d1 after storage");
	d2.print("d2 after storage");
}