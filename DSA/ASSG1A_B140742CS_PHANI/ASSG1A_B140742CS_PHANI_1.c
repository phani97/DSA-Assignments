#include<stdio.h>
#include<stdlib.h>

int main()
{
int i,j,n,k;
printf("enter order of matrix");
i=scanf("%d",&n);
if(n<1||i<1||n>100){
printf("Matrix can't built with that configurations");
return 1;}
int a[n][n];
printf("enter matrix\n");

for(i=0;i<n;i++)
	for(j=0;j<n;j++){
		k=scanf("%d",&a[i][j]);
		if(k!=1||a[i][j]<0||a[i][j]>2147483647){
			printf("invalid input");
			return 1;}
	}
			
for(i=0;i<n/2;i++)
	for(j=i;j<n-1-i;j++)
	{
		k=a[i][j];
		a[i][j]=a[n-1-j][i];
		a[n-1-j][i]=a[n-1-i][n-1-j];
		a[n-1-i][n-1-j]=a[j][n-1-i];
		a[j][n-1-i]=k;
	}
	
printf("Matrix rotated clockwise by 90 degrees\n");
for(i=0;i<n;i++){
	for(j=0;j<n;j++)
		printf("%d\t",a[i][j]);
	printf("\n");
}}
		

