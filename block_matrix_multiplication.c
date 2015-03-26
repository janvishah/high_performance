#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int N=500;
	int a[N][N],b[N][N],c[N][N];
	int i,j,k,jj,kk,temp;
	int s = 100;

  double start = clock();
	for (i=0; i<N; i++)
    for (j=0; j<N; j++)
  		a[i][j]= rand();	

  printf("\n Matrix 1\n");
  for (i=0; i<N; i++)
  {
    for (j=0; j<N; j++)
    {
    	printf("%d\t",a[i][j]);
    }
    printf("\n");
  }

  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      b[i][j]= rand();

  printf("\n");
  printf("\n Matrix 2\n");
  for (i=0; i<N; i++)
  {
    for (j=0; j<N; j++)
    {
    	printf("%d\t",b[i][j]);
    }
    printf("\n");
  }

  for(jj=0;jj<N;jj+= s)
  {
    for(kk=0;kk<N;kk+= s)
    {
      for(i=0;i<N;i++)
      {
        for(j = jj; j<((jj+s)>N?N:(jj+s)); j++)
        {
          temp = 0;
          for(k = kk; k<((kk+s)>N?N:(kk+s)); k++)
          {
            temp += a[i][k]*b[k][j];
          }
          c[i][j] += temp;
        }
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