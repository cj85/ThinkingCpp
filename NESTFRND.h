//Ƕ���಻���Զ�ʹ�ð������˽�����ݣ����java��ȫ��һ��
//�������ڲ���(class)����Ƕ����(static class)
#ifndef NESTFRND_H_
#define NESTFRND_H_
struct holder{
private:
	int a[32];
public:
	void initialize();
	struct pointer{
	private:
		holder* h;
		int* p;
	public:
		//��������Կ��� c++����ڲ���Ĭ��ΪǶ���ࣨstatic class��
		void initialize(holder* H);
		void next();
		void previous();
		void top();
		void end();
		int read();
		void set(int i);
	};
	friend holder::pointer;
};

void nestfrndtest();

#endif