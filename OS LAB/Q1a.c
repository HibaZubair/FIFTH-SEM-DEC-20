#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<errno.h>
#include<semaphore.h>
#include<sys/types.h>

unsigned int rem_ice=3;

sem_t sal;

void func(void){
	if(rem_ice>0){
		sem_wait(&sal);
		printf("Remain icectream %d\n",rem_ice);
		rem_ice--;
		sem_post(&sal);
	}
	pthread_exit(0);
}
int main(){

	sem_init(&sal,0,1);
	pthread_t t1,t2,t3;

	pthread_create(&t1,NULL,(void*)&func,NULL);
	pthread_create(&t2,NULL,(void*)&func,NULL);
	pthread_create(&t3,NULL,(void*)&func,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

	sem_destroy(&sal);
	return 0;
}
