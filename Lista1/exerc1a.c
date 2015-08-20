

SOP/lista_fork01/fork1A.c
@AndressaUmetsu AndressaUmetsu 5 days ago 15/08/15

1 contributor
37 lines (34 sloc) 0.515 kB
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*  A
|   |   | 
B   C   D */

int main(){
	pid_t f;
	//Pai A	
	printf("Pai (PID=%u) \n", getpid());
	printf("A");
	f = fork();
	//Filho B	
	if (f == 0){ //se retorno de f igual a 0 então é o filho
		printf("B");
	    exit(0);
	}
	f = fork();
	//Filho C	
	if (f == 0){
	    printf("C");
	    exit(0);
	}
	f = fork();
	//Filho D	
	if (f == 0){
	    printf("D");
	    exit(0);
	}
	//sleep(10);
    return 0;
}
