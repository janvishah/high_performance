#include <stdio.h>
#include <conio.h>
void main()
{
	int N=6;
	int a[N][N],b[N][N],c[N][N];
	int i,j,k;
	int s = 3;

	for (i=0; i<N; i++)
    for (j=0; j<N; j++)
  		a[i][j]= rand();	

  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
    	printf("%d\t",a[i][j]);
    printf("\n");

  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      b[i][j]= rand();

  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
    	printf("%d\t",b[i][j]);
    printf("\n");

  for(int jj=0;jj<N;jj+= s)
  {
    for(int kk=0;kk<N;kk+= s)
    {
      for(int i=0;i<N;i++)
      {
        for(int j = jj; j<((jj+s)>N?N:(jj+s)); j++)
        {
          temp = 0;
          for(int k = kk; k<((kk+s)>N?N:(kk+s)); k++)
          {
            temp += a[i][k]*b[k][j];
          }
          c[i][j] += temp;
        }
      }
    }
  }

  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
    	printf("%d\t",b[i][j]);
    printf("\n");
}