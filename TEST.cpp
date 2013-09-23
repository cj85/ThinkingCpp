#include<iostream>
namespace test_space{
	using namespace std;
	class Test{
	public:
		friend ostream& operator <<(ostream& os,const Test& t){
			os<<"Test!";
			return os;
		}
	};

}

void test(){
	using namespace test_space;
		Test t[10];
		cout<<t[0]<<endl;
}