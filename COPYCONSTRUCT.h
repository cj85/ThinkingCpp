#ifndef COPYCONSTRUCT_H_
#define COPYCONSTRUCT_H_

class CopyConstruct{
public:
	CopyConstruct();
	CopyConstruct(const CopyConstruct& cc);
	~CopyConstruct();
};

static void f(CopyConstruct c);
static CopyConstruct g();
void copyconstructor_test();
#endif // !COPYCONSTRUCT_H_
