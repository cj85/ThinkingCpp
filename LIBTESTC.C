#define _CRT_SECURE_NO_WARNINGS 
#include "lib.h"
#include <stdio.h>
#include <assert.h>

#define BUFSIZE 80

void libtestc(){
	Stash intStash, stringStash;
	int i;
	FILE * file;
	char buf[BUFSIZE];
	char* cp;

	initialize(&intStash,sizeof(int));
	for(i=0;i<100;i++){
		add(&intStash,&i);
	}
	
	initialize(&stringStash,sizeof(char)*BUFSIZE);
	file=fopen("LIBTESTC.C","r");
	assert(file);
	while(fgets(buf,BUFSIZE,file))
		add(&stringStash,buf);
	fclose(file);
	for(i=0;i<count(&intStash);i++)
		printf("fetch(&intStash,%d)=%d\n",i,*(int*)fetch(&intStash,i));
	i=0;
	while((cp=(char*)fetch(&stringStash,i++))!=0)
		printf("fetch(&stringStash,%d)=%s",i-1,cp);
	putchar('n');
	cleanup(&intStash);
	cleanup(&stringStash);
	
}