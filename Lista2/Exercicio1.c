//gcc -Wall -pthread -o exerc1lista2 Exercicio1.c


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS    50

/*
 Modifique o programa simples.c, dispon ́ıvel nos exemplos de Pthreads, para que cada thread retorne
o quadrado do numero
recebido como parametro. O programa principal deve imprimir a soma dos
valores de retorno de todas as threads. 
 */


void *PrintHello(void *arg) {
   long tid = (long)arg;
   printf("Alo da thread %ld\n", tid);
   pthread_exit((void *)(tid*tid));
}

int main (int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   int rc,soma;
   long t;
   void *b;
   for (t=0; t<NUM_THREADS; t++){
      printf("main: criando thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
      if (rc) {
         printf("ERRO - rc=%d\n", rc);
         exit(-1);
      }
   }
   
   for(t=0; t<NUM_THREADS; t++){
		pthread_join(threads[t],&b);
		soma += (long)b;
   }
   
   printf("\n\n ---> Soma: %d <---\n", soma);
   
   /* Ultima coisa que main() deve fazer */
   pthread_exit(NULL); 
}
