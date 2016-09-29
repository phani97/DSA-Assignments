#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
int i,j,n;
if(!scanf("%d",&n) || n<=0)
	{printf("invalid input");
	return 0;}
char p[n][20],temp[11];

for(i=0;i<n;i++)
{
scanf("%s",p[i]);
if(strlen(p[i])>10){
	printf("invalid input");
	return 1;}
for(j=0;j<strlen(p[i]);j++)
if(p[i][j]<'a' || p[i][j]>'z'){
	printf("invalid input");return 0;}
}
for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++){
		if(strcmp(p[i],p[j])>0){
			strcpy(temp,p[i]);
			strcpy(p[i],p[j]);
			strcpy(p[j],temp);
		}
	}

for(i=0;i<n;i++){
printf("%s\t",p[i]);
}
}
