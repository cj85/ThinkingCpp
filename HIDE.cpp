////����ڻ�������һ�������������ؼ��Σ������������ض���������������ڸ����л����
//������Ҳ����˵���������������б�ò��ٿ��á�
//java û��
class homer{
public:
	int doh(int) const {return 1;}
	char doh(char) const{return 'd';}
	float doh(float) const{return (float)1.1;}
};

class bart:public homer{
public:
	class milhouse{};
	void doh(milhouse)const{}
};

void hide(){
	bart b;
	//b.doh(1);
	//b.doh('x');
	//b.doh(1.0);
}