//can't jump pass constructor
class NOJUMP{
public:
	NOJUMP(){}
	void f(int i){
		if(i<10){
			//goto jump1; //error can't go bypass init
		}
		NOJUMP x1;
jump1:
		switch(i){
		case 1:
			NOJUMP x2; 
			break;
		//case 2:   //Error:  case bypass init
			NOJUMP x3;
			break;
		}
	}
	void test(){

	}
};

