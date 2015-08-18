//cc -o exe1 exe1.c
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t f1,f2,f3,f4,f5;

	f1 =fork();

	if(f1==0){
		printf("A\n");
	
	
	}else{
	if(f2==0){
		printf("B\n");
	}
	if(f3==0){
		printf("C\n");
	}else{
	if(f4==0){
		printf("D\n");

	}
	if(f5==0){
		printf("E\n");
	}}
	}
return 0;
