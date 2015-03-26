#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) 
{
  int	tid, i, j, k;
  int	a[500][500],b[500][500],c[500][500];
  double start = clock();
  
  #pragma omp parallel num_threads(5)
  {
    tid = omp_get_thread_num();

    printf("Thread %d Initialize matrix 1...\n",tid);
    #pragma omp for schedule (dynamic) 
    for (i=0; i<500; i++)
      for (j=0; j<500; j++)
        a[i][j]= rand();
    
    printf("Thread %d Initialize matrix 2...\n",tid);
    #pragma omp for schedule (dynamic)
    for (i=0; i<500; i++)
      for (j=0; j<500; j++)
        b[i][j]= rand();
    
    printf("\nMatrix multiplication\n");
    #pragma omp for schedule(dynamic)
    for (i=0; i<500; i++)    
    {
      for(j=0; j<500; j++)       
        for (k=0; k<500; k++)
          c[i][j] += a[i][k] * b[k][j];
    }
  } 
  double end=clock();

  printf("******************************************************\n");
  printf("Result Matrix:\n");
  for (i=0; i<500; i++)
  {
    for (j=0; j<500; j++) 
      printf("%d", c[i][j]);
    printf("\n"); 
  }
  printf("******************************************************\n");
  printf ("Done.\n");
  
  double T = end - start;
  printf("time = %f",T);
}
