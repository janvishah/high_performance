#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) 
{
  int	i, j, k;
  int	a[1000][1000],b[1000][1000],c[1000][1000];    /* matrix A to be multiplied */
                     /* set loop iteration chunksize */
  double start = clock();
  
  printf("Initialize matrix 1...\n"); 
  for (i=0; i<1000; i++)
    for (j=0; j<1000; j++)
  	  a[i][j]= rand();
    
  printf("Initialize matrix 2...\n"); 
  for (i=0; i<1000; i++)
    for (j=0; j<1000; j++)
    	b[i][j]= rand();
    
  printf("\nMatrix multiplication\n");
  for (i=0; i<1000; i++)    
  {
    for(j=0; j<1000; j++)       
      for (k=0; k<1000; k++)
        c[i][j] += a[i][k] * b[k][j];
  }
  
  double end=clock();

  /*** Print results ***/
  printf("******************************************************\n");
  printf("Result Matrix:\n");
  for (i=0; i<1000; i++)
  {
    for (j=0; j<1000; j++) 
      printf("%d", c[i][j]);
    printf("\n"); 
  }
  printf("******************************************************\n");
  printf ("Done.\n");
  
  double T = end - start;
  printf("time = %f",T);
}