#include<stdio.h>
#include<stdlib.h>

int main()
{
int i,n,j,k;
if (!scanf("%d",&n) || n<=1){printf("invalid input");return 0;}
int a[n];
if (!scanf("%d",&a[0])){printf("invalid input");return 0;}
for(i=1;i<n;i++)
{
if (!scanf("%d",&a[i]) || a[i]<a[i-1]){printf("invalid input");return 0;}
}
if (!scanf("%d",&k)){printf("invalid input");return 0;}
i=1,j=0;
while(j<n-1){
if (a[i]+a[j]==k && i!=j)
	{printf("%d %d\n",a[j],a[i]);
	return 1;}
else if(a[i]+a[j]>k || i==n-1)
	{j++;i=j+1;}
else  i++;
}
printf("no two elements sum upto %d",k);
}
