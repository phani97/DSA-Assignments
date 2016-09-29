#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("enter n\n");
    i=scanf("%d",&n);
    if(i==0){
	printf("Invalid input");
	return 1;}
    if(n==0){
	printf("Matrix doesn't exist with order 0");
	return 1;}
    int a[n][n];
    printf("enter matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(n==1)
                printf("%d\n",a[i][j]);
            else if(i==0&&j==0)
            {
                int k=( (a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1])/4.0)+0.5;
                printf("%d\t",k);
            }
            else if(i==0&&j!=n-1)
            {
                int k=( ( a[i][j-1]+a[i][j]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1] )/6.0 )+0.5;
                printf("%d\t",k);
            }
            else if(i==0&&j==n-1)
            {
                int k=( (a[i][j-1]+a[i][j]+a[i+1][j-1]+a[i+1][j] )/4.0)+0.5;
                printf("%d\n",k);
            }
            else if(i==n-1&&j==0)
            {
                int k=( (a[i][j]+a[i-1][j]+a[i][j+1]+a[i-1][j+1])/4.0)+0.5;
                printf("%d\t",k);
            }
            else if(i==n-1&&j==n-1)
            {
                int k=( (a[i][j-1]+a[i][j]+a[i-1][j-1]+a[i-1][j] )/4.0)+0.5;
                printf("%d\n",k);
            }
            else if(i!=n-1&&j==0)
            {
                int k=( (a[i-1][j]+a[i][j]+a[i+1][j]+a[i-1][j+1]+a[i][j+1]+a[i+1][j+1])/6.0)+0.5;
                printf("%d\t",k);
            }
            else if(i!=n-1&&j==n-1)
            {
                int k=( (a[i-1][j]+a[i][j]+a[i+1][j]+a[i-1][j-1]+a[i][j-1]+a[i+1][j-1])/6.0)+0.5;
                printf("%d\n",k);
            }

            else if(i==n-1&&j!=n-1)
            {
                int k=( ( a[i][j-1]+a[i][j]+a[i][j+1]+a[i-1][j-1]+a[i-1][j]+a[i-1][j+1] )/6.0)+0.5;
                printf("%d\t",k);
            }
            else
            {
                int k=( (a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+a[i][j-1]+a[i][j]+a[i][j+1]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1])/9.0)+0.5;
                printf("%d\t",k);
            }

        }
    }

return 0;
}
