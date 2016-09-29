#include<stdio.h>
#include<stdlib.h>

int main()
{
int i,j,n;
if(!scanf("%d",&n) || n<=0)
	{printf("invalid input");
	return 0;}
float a[n],temp;
for(i=0;i<n;i++)
	if(!scanf("%f",&a[i]))
		{printf("invalid input");
		return 0;}
for(i=0;i<n-1;i++)
	for(j=0;j<n-i-1;j++)
		if(a[j]>a[j+1]){
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
for(i=0;i<n;i++)
	printf("%g\t",a[i]);
}
