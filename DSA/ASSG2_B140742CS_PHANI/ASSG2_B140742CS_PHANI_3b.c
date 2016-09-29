#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student_list{

	char name[30];
	char roll[30];
	int marks;
};

void radixsort(struct student_list [],int,int);

int main()
{
int i,n,j;
if(!scanf("%d",&n) || n<=0)
	{printf("invalid input");
	return 1;}
struct student_list a[n];
for(i=0;i<n;i++){
	scanf("%s %s %d",a[i].roll,a[i].name,&a[i].marks);
	if(strlen(a[i].roll)!=9 || a[i].marks<0 || a[i].marks>100)
	{printf("invalid input");
	return 1;}
	if(a[i].roll[0]<'A' || a[i].roll[0]>'Z')
	{printf("invalid input");
	return 1;}
	if(a[i].roll[7]<'A' || a[i].roll[7]>'Z')
	{printf("invalid input");
	return 1;}
	if(a[i].roll[8]<'A' || a[i].roll[8]>'Z')
	{printf("invalid input");
	return 1;}
	for(j=1;j<7;j++)
	if(a[i].roll[j]<'0' || a[i].roll[j]>'9')
	{printf("invalid input");
	return 1;}
	
}
radixsort(a,n,8);
printf("\n");
for(i=0;i<n;i++)
	printf("%s %s %d\n",a[i].roll,a[i].name,a[i].marks);
}

void radixsort(struct student_list a[],int n,int l){
int j,i;
for(i=1;i<n;i++)
{
	j=i-1;
	struct student_list p=a[i];
	while(a[j].roll[l]>p.roll[l] && j>=0){
	//transferring data from j to j+1
	strcpy(a[j+1].name,a[j].name);
	strcpy(a[j+1].roll,a[j].roll);
	a[j+1].marks=a[j].marks;
	j--;}
	strcpy(a[j+1].name,p.name);
	strcpy(a[j+1].roll,p.roll);
	a[j+1].marks=p.marks;
}


if(l!=0)
	radixsort(a,n,l-1);
}

