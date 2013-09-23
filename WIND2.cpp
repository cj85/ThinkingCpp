#include<iostream>
using namespace std;
enum note{middleC, Csharp, Cflat};
class instrument{
public:
	void play(note)const{
		cout<<"instrument::play"<<endl;
	}
	virtual void play2(note)const {
		cout<<"instrument::play2"<<endl;
	}
};

class wind:public instrument{
public:
	void play(note)const{
		cout<<"wind::play"<<endl;
	}
	void play2(note)const{
			cout<<"wind::play2"<<endl;
	}
};

static void tune(instrument& i){
	i.play(middleC);
	i.play2(middleC);
}
static void tune2(instrument* i){
	i->play(middleC);
	i->play2(middleC);
}

void wind2(){
	wind flute;
	tune(flute);
	cout<<"----------"<<endl;
	tune2(&flute);
}