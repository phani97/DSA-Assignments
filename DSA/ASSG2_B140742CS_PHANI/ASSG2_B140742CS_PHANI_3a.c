#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student_list{

	char name[30];
	char roll[30];
	int marks;
};
int partition(struct student_list [],int,int);
void quicksort(struct student_list [],int ,int);

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
quicksort(a,0,n-1);
for(i=0;i<n;i++)
	printf("%s %s %d\n",a[i].roll,a[i].name,a[i].marks);
}

void quicksort(struct student_list a[],int f,int l){
if(f<l){
int q=partition(a,f,l);
quicksort(a,f,q-1);
quicksort(a,q+1,l);
}
}

int partition(struct student_list a[],int f,int l){
int i,j=f-1,temp;
char t[30];
for(i=f;i<=l;i++){
	if(a[i].marks>=a[l].marks){
		//swaping marks
		temp=a[i].marks;
		a[i].marks=a[j+1].marks;
		a[j+1].marks=temp;
		
		//swaping roll_no
		strcpy(t,a[i].roll);
		strcpy(a[i].roll,a[j+1].roll);
		strcpy(a[j+1].roll,t);
		
		//swaping names
		strcpy(t,a[i].name);
		strcpy(a[i].name,a[j+1].name);
		strcpy(a[j+1].name,t);
		j++;
	}
}

return j--;
}
