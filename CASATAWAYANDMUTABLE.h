#ifndef CASTAWAYANDMUTABLE_H_
#define CASTAWAYANDMUTABLE_H_
class CastawayAndMutable{
	int i;
	mutable int j;
public:
	CastawayAndMutable(){i=j=0;}
	void f() const{
		((CastawayAndMutable*)this)->i++;
	}
	void g() const{
		j++;
	}
};
#endif