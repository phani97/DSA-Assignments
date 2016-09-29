#include<stdio.h>
#include<stdlib.h>

int main()
{
int n,m,i,j,count=0,k;char c;
if(scanf("%d%d",&m,&n)!=2 || n<=0 ||m<=0){
	printf("invalid input");
	return 0;}
int a[m][n];
for(i=0;i<m;i++)
	for(j=0;j<n;j++)
		if(!scanf("%d",&a[i][j])){
		printf("invalid input");
		return 0;}

if(!scanf("%d",&k) ){
		printf("invalid input");
		return 0;}

for(i=0;i<m;i++)
	for(j=0;j<n;j++)
		if(a[i][j]==k){
		printf("%d\t%d\n",i+1,j+1);
		count++;}
if(count==0)
	printf("NOT FOUND");
}

