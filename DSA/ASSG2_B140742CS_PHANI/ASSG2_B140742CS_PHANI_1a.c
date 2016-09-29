#include<stdio.h>
#include<stdlib.h>

int main()
{
int n,k,last,middle,first,i;
printf("enter no.of elements");
if(!scanf("%d",&n) || n<0){
	printf("invalid input");
	return 1;}
int a[n];
printf("enter elements");
if(!scanf("%d",&a[0])){
	printf("invalid input");
	return 1;}
	
for(i=1;i<n;i++)
{
	if(!scanf("%d",&a[i]) || a[i]<a[i-1]){
	printf("invalid input");
	return 1;}
}
printf("enter element to be searched");
if(!scanf("%d",&k)){
	printf("invalid input");
	return 1;}
first=0;
last=n-1;
middle=0;
while(first<=last)
{
middle=(first+last)/2;
if(a[middle]==k)
	break;
else if(a[middle]<k){
	first=middle+1;}
else last=middle-1;
}
if(a[middle]==k)
	printf("element present at %d position",middle+1);
else printf("Not found");
return 1;
}
	
