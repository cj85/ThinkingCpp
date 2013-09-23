//嵌套类不能自动使用包含类的私有数据，这和java完全不一样
//无论是内部类(class)还是嵌套类(static class)
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
		//从这里可以看出 c++里的内部类默认为嵌套类（static class）
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