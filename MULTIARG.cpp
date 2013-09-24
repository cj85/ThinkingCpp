//multiple constructor arguments with aggregate initialization

class MULTIARG{
	int i,j;
public:
	MULTIARG(int I, int J){
		i=I;
		j=J;
	}
	static void test(){
		MULTIARG x[]={MULTIARG(1,2),MULTIARG(3,4)};
	}
};