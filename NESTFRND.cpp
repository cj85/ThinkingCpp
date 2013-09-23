#include<stdio.h>
#include<string.h>
#include "NESTFRND.h"
#define SZ 20


void holder::initialize(){
	memset(a,0,SZ*sizeof(int));
}

void holder::pointer::initialize(holder*H){
	h=H;
	p=h->a;
}

void holder::pointer::next(){
	if(p<&(h->a[SZ-1]))
		p++;
}

void holder::pointer::previous(){
	if(p>&(h->a[0])) p--;
}

void holder::pointer::top(){
	p=&(h->a[0]);
}

void holder::pointer::end(){
	p=&(h->a[SZ-1]);
}

int holder::pointer::read(){
	return *p;
}

void holder::pointer::set(int i){
	*p=i;
}

void nestfrndtest(){
	holder h;
	holder::pointer hp,hp2;
	int i;

	h.initialize();
	hp.initialize(&h);
	hp2.initialize(&h);

	for(i=0;i<SZ;i++){
		hp.set(i);
		hp.next();
	}
	hp.top();
	hp2.end();
	for(i=0;i<SZ;i++){
		printf("hp= %d, hp2=%d\n",hp.read(),hp2.read());
		hp.next();
		hp2.previous();
	}
}