#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

sem_t l,s,b;

void func(void){

	sem_wait(&l);
	printf("Weighting\n");
	sleep(4);
	sem_post(&l);

	sem_wait(&s);
	printf("Checking\n");
	sleep(7);
	sem_post(&s);

	sem_wait(&b);
	printf("getting boarding pass\n");
	sleep(3);
	sem_post(&b);


	pthread_exit(0);
}
int main(){
	pthread_t t[10];
	int a;

	sem_init(&l,0,1);
	sem_init(&s,0,1);
	sem_init(&b,0,1);

	for(a=0;a<10;a++){
		pthread_create(&t[a],NULL,(void*)&func,NULL);
	}

	for(a=0;a<10;a++){
		pthread_join(t[a],NULL);
	}

	sem_destroy(&l);
	sem_destroy(&s);
	sem_destroy(&b);

	return 0;
}


