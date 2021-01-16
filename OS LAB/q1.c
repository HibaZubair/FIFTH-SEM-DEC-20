#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define size 4 

#define MAX_THREAD 4 
  
int matA[size][size]; 
int matB[size][size]; 
int matC[size][size];
int matD[size][size]; 
int steps = 0;
int addstep=0;   
void* matrixmulti(void* var) 
{ 
    int core = steps++; 
    int i,j,k; 
    for (i = core * size / 4; i < (core + 1) * size / 4; i++)  
        for (j = 0; j < size; j++)  
            for (k = 0; k < size; k++)  
                matC[i][j] += matA[i][k] * matB[k][j]; 
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
    for(i=0;i<MAX_THREAD;i++)
    {
    pthread_create(&a[i],NULL,matrixadd,(void*)&a[i]);
    }
    for(i=0;i<MAX_THREAD;i++)
    pthread_join(a[i],NULL);   
    pthread_t threads[MAX_THREAD]; 
    for (i = 0; i < MAX_THREAD; i++) { 
        int* var; 
        pthread_create(&threads[i], NULL, matrixmulti, (void*)(var)); 
    } 
   
    for (i = 0; i < MAX_THREAD; i++)  
        pthread_join(threads[i], NULL);     
  
  printf("Resultant Addition Matrix:\n");
    for (i = 0; i < size; i++) { 
        for (j = 0; j < size; j++)
        { printf("%d\t",matD[i][j]); 
         }   
        printf("\n");
    }
    printf("Resultant Multiplication Matrix:\n");
    for (i = 0; i < size; i++) { 
        for (j = 0; j < size; j++)
        { printf("%d\t",matC[i][j]); 
         }   
        printf("\n");
    } 
 
    return 0; 
} 
