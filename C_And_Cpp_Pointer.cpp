extern "C"{
struct bird{int i;};
struct rock{int j;};

static bird* b=0;
static rock* r=0;
static void* v=0;

static void f(){
	r=(rock*)v;
	v=b;
}


static const int i=10;
static int a[i];
};
