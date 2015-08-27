#include <stdio.h>
#include <pthread.h>



int n = 1;
int fim_x,fim_z = 0;
pthread_mutex_t mtx;
pthread_cond_t cond_y,cond_z;



void *fx(){
	pthread_mutex_lock(&mtx);
	printf("entrei na fx...\n");
	n = n * 16;
	printf("fx -> n = %d\n\n",n);
	fim_x = 1;
	pthread_cond_signal(&cond_z);
	pthread_mutex_unlock(&mtx);
	pthread_exit(NULL);
	//up(sz);
}

void *fy(){
	//down(sy);
	pthread_mutex_lock(&mtx);
	if(!fim_z)
		pthread_cond_wait(&cond_y,&mtx);
	printf("Entrei na fy....\n");
	n = n/7;
	printf("fy -> n = %d\n\n",n);
	pthread_mutex_unlock(&mtx);
	pthread_exit(NULL);
}

void *fz(){
	//down(sz);
	pthread_mutex_lock(&mtx);
	printf("Entrei na fz....\n");
	if(!fim_x)
		pthread_cond_wait(&cond_z,&mtx);
	n = n + 40;
	fim_z = 1;
	printf("fz -> n = %d\n\n",n);
	pthread_cond_signal(&cond_y);
	pthread_mutex_unlock(&mtx);
	pthread_exit(NULL);
	//up(sy);
}

int main(){
	pthread_t tx, ty, tz;
	int rc;
	
	pthread_mutex_init(&mtx,NULL);
	pthread_cond_init(&cond_z,NULL);
	pthread_cond_init(&cond_y,NULL);
	
	pthread_create(&tx,NULL,fx,NULL);
	pthread_create(&ty,NULL,fy,NULL);
	pthread_create(&tz,NULL,fz,NULL);
	
	rc = pthread_join(tx,NULL);
	printf("\nFinalizando x: \n");
	printf("x -> [rc = %d]\n",rc);
	pthread_join(ty,NULL);
	printf("\nFinalizando y: \n");
	printf("y -> [rc = %d]\n",rc);
	pthread_join(tz,NULL);
	printf("\nFinalizando z: \n");
	printf("z -> [rc = %d]\n",rc);
	
	printf("\n\nValor de n -> %d\n", n);
	return 0;
}


compilar: gcc -pthread -o exerc_ipc_4 exerc_ipc_4.c
