#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int N=500;
	int a[N][N],b[N][N],c[N][N];
	int i,j,k,jj,kk,temp;
	int s=2;

  double start = clock();
	for (i=0; i<N; i++)
    for (j=0; j<N; j++)
  		a[i][j]= i;	

  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      b[i][j]= j;

  for (i=0; i<(N/s); i++)
  {
    for (j=0; j<N; j++)
    {
      c[i][j] = 0;
      for(k=0; k<N; k++)
      {
        c[i][j] += a[i][k]*b[k][j];
      }
    }
  }

  for (i=(N/s); i<N; i++)
  {
    for (j=0; j<N; j++)
    {
      c[i][j] = 0;
      for(k=0; k<N; k++)
      {
        c[i][j] += a[i][k]*b[k][j];
      }
    }
  }

  
  double end=clock();

  printf("\n Matrix C\n");
  for (i=0; i<N; i++)
  {
    for (j=0; j<N; j++)
    {
    	printf("%d\t",c[i][j]);
    }
    printf("\n");
  }

  double T = end - start;
  printf("time = %f",T);
}