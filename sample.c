#include <stdio.h>
#include <stdlib.h>
void main()
{
	int N=6;
	int a[N][N],b[N][N],c[N][N];
	int i,j,k,jj,kk,temp;
	int s = 3;

	for (i=0; i<N; i++)
    for (j=0; j<N; j++)
  		a[i][j]= i;	

  printf("\n Matrix 1\n");
  for (i=0; i<N; i++)
  {
    for (j=0; j<N; j++)
    {
    	printf("%d\t",a[i][j]);
    }
    printf("\n");
  }
}