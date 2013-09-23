#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>

struct bird{int i;};
struct rock{int j;};
//class not allowed in C
//class sun{int k;};

static void Cpointer(){
	void *v;
	struct rock* r=NULL;
    struct bird *b=NULL;
	
	v=r;
	b=(struct bird*)v;
}


 //rock* r=(rock*)malloc(sizeof(rock));;

//
//const int i=10;
//int a[i];