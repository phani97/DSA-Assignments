#include<stdio.h>
#include<stdlib.h>

int b_s(int [],int,int,int);
int main()
{
int n,k,f,i;
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
f=b_s(a,0,n-1,k);
if(f!=-1)
	printf("%d",f+1);
else printf("Not found");
}

int b_s(int a[],int first,int last,int k)
{
int middle;
if(first<=last)
{
middle=(first+last)/2;
if(a[middle]==k)
	return middle;
else if(a[middle]<k){
	return b_s(a,middle+1,last,k);}
else return b_s(a,first,middle-1,k);
}

}

