#include "lib.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void initialize(Stash* S, int Size){
	S->size=Size;
	S->quantity=0;
	S->storage=0;
	S->next=0;
}

void cleanup(Stash*S){
	if(S->storage){
		puts("freeing storge");
		free(S->storage);
	}
}

void  add(Stash* S, void* element){
	if(S->next>=S->quantity){
		inflate(S,100);
	}
	memcpy(&(S->storage[S->next*S->size]),element,S->size);
	S->next++;
}

void* fetch(Stash*S, int index){
	if(index>=S->next||index<0){
		return 0;
	}
	return &(S->storage[index*S->size]);
}

int count(Stash* S){
	return S->next;
}

void inflate(Stash*S, int increase){
	void * v=realloc(S->storage,(S->quantity+increase)*S->size);
	assert(v);
	S->storage=(unsigned char *)v;
	S->quantity+=increase;
}