#include<stdio.h>
#include<stdlib.h>
int m;
int left(int);
int right(int);
void buildheap(int []);
void maxheapify(int [],int);
int main()
{
int n,i,temp;
if(!scanf("%d",&n) || n<=0){
	printf("invalid input");
	return 0;}
int a[n];
for(i=0;i<n;i++){
	if(!scanf("%d",&a[i])){
	 printf("invalid input");
	return 0;}}
m=n;
buildheap(a);
while(m>0)
{
	temp=a[m-1];
	a[m-1]=a[0];
	a[0]=temp;
	m=m-1;
	maxheapify(a,0);
}
for(i=0;i<n;i++){
	printf("%d\t",a[i]);
}
}
int left(int i){
return 2*i+1;}
int right(int i){
return 2*i+2;}

//building heap from given elements
void buildheap(int a[]){
int i;
for(i=m/2-1;i>=0;i--)
{
maxheapify(a,i);
}
}

//getting max element to ith position in its child
void maxheapify(int a[],int i)
{
int temp=i,x;
if(left(temp)<=m-1){
	if(a[left(temp)]>a[i])
		i=left(temp);
}
if(right(temp)<=m-1){
	if(a[right(temp)]>a[i])
		i=right(temp);
}
if(i!=temp){
	x=a[i];
	a[i]=a[temp];
	a[temp]=x;
	maxheapify(a,i);
}
}
