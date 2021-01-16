#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#define size 4 

#define MAX_THREAD 4 
  
int matA[size][size]; 
int matB[size][size]; 
int matD[size][size]; 
int steps = 0;
int addstep=0;   
int alarmFlag = 0;
void alarmHandler ( ) {
    printf ("\nAn Alarm clock signal was received\n");
    alarmFlag = 1;
}

void* matrixadd(void* v)
{
 int i,j,k;
 for(i=0;i<size;i++)
 {
   for(j=0;j<size;j++)
   {
       matD[i][j]=matA[i][j]+matB[i][j];
   }
 }
}  
int main() 
{ 
    int i,j; 
    void (*oldHandler)( );
    signal(SIGALRM, alarmHandler);
    for (i = 0; i < size; i++) { 
        for (j = 0; j < size; j++) { 
            matA[i][j] = rand() % 10; 
            matB[i][j] = rand() % 10; 
        } 
    } 
  
    printf("Matrix A:\n"); 
    for (i = 0; i < size; i++) { 
        for (j = 0; j < size; j++)
        { printf("%d\t",matA[i][j]); 
         }   
        printf("\n");
    } 
   
    printf("Matrix B:\n");
    for (i = 0; i < size; i++) { 
        for (j = 0; j < size; j++)
        { printf("%d\t",matB[i][j]); 
         }   
        printf("\n");
    } 
  
    pthread_t a[MAX_THREAD];
    printf("\nprocess 1\n");
    for(i=0;i<MAX_THREAD;i++)
    {
       printf("\n\n");
       printf("\nEntering Into Critical Section For 5 seconds\n");
       alarm (5) ;
       oldHandler = signal(SIGINT, SIG_IGN);
    pthread_create(&a[i],NULL,matrixadd,(void*)&a[i]);
     while(!alarmFlag){
	    pause();
            printf("\nLoop ends due to alarm signal\n");	
       }
        alarmFlag=0;
       signal (SIGINT, oldHandler);
       printf("\nGoing Out From Critical Section\n");
       printf("\n");
    }
    printf("\nprocess 2\n");
    
    for(i=0;i<MAX_THREAD;i++)
    {
     printf("\n---\n");
	printf("\nEntering Into Critical Section For 5 seconds\n");
	alarm (5) ;
	oldHandler = signal(SIGINT, SIG_IGN);
    pthread_join(a[i],NULL);
    while(!alarmFlag){
	     pause();
             printf("\nLoop ends due to alarm signal\n");	
        }
	alarmFlag=0;
        signal (SIGINT, oldHandler);
        printf("\nGoing Out From Critical Section\n");	
	printf("\n----\n");
    }  
      printf("Resultant Addition Matrix:\n");
    for (i = 0; i < size; i++) { 
        for (j = 0; j < size; j++)
        { printf("%d\t",matD[i][j]); 
         }   
        printf("\n");
    }
    return 0;
   }
