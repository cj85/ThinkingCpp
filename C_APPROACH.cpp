/*
s e t j m p ( )��һ���ر�ĺ�������Ϊ�������ֱ�ӵ����������Ͱѵ�ǰ����״̬���������
��Ϣ�����j m p _ b u f�У��������㡣������������Ϊ��ͨ���ĺ�����Ȼ�������ʹ��ͬһ��
j m p b u f����l o n g j m p ( )��������ٴδ�s e t j m p ( )���أ�����ȷ�ص���s e t j m p ( )�ĺ�ˡ���ʱ����
��ֵ����l o n g j m p ( )�ǵڶ��������������ܷ���ʵ���ϴ�l o n g j m p ( )�з����ˡ����������ж��
��ͬ��j m p b u f�����Ե�������Ķ����ͬλ�õ���Ϣ���ֲ�g o t o���ñ�ţ�������Ǿֲ���
ת�Ĳ�ͬ����������ͨ��s e t j m p / l o n g j m p��ת���κεط���һЩ���Ʋ����������ۣ���
��C++�е������ǣ�longjmp()�������ڶ����ر��ǣ�����������Χʱ����������������[1]��
�������������Ǳ���ģ��������ַ�����C++�в����С�
*/

//������������Ȼ������~rainbow��������
#include<iostream>
#include<setjmp.h>
namespace c_approach_space{
using namespace std;
class rainbow{
public:
	rainbow(){cout<<"rainbow()"<<endl;}
	~rainbow(){cout<<"~rainbow()"<<endl;}
};

jmp_buf kansas;

void OZ(){
	rainbow RB;
	for(int i=0;i<3;i++){
		cout<<"there's no place like home"<<endl;
	}
	longjmp(kansas,47);
}
}

void c_approach(){
	using namespace c_approach_space;
	if(setjmp(kansas)==0){
		cout<<"tornado, witch, munchkins...."<<endl;
		OZ();
	}else{
		cout<<"Auntie em! I had the strangest dream..."<<endl;
	}
}