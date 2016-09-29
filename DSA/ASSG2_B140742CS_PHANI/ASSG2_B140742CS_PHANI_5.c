#include<stdio.h>
#include<stdlib.h>

int main()
{
int i,j,n;
if(!scanf("%d",&n) || n<=0)
	{printf("invalid input");
	return 0;}
int a[n],temp;
for(i=0;i<n;i++)
	if(!scanf("%d",&a[i]) || a[i]<0 || a[i]>2147483648)
		{printf("invalid input");
		return 0;}
for(i=1;i<n;i++)
{
	temp=a[i];j=i-1;
	while(a[j]>temp && j>=0){
		a[j+1]=a[j];
		j--;
		}
	a[j+1]=temp;
}
for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}
