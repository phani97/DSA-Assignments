#include<stdio.h>
#include<stdlib.h>
struct sll{
int data;
struct sll *next;
};
void insert(struct sll **s,int data)
{
struct sll *temp,*temp1;
temp=(struct sll*)malloc(sizeof(struct sll));
temp->data=data;
if(*s==NULL)
	*s=temp;
else {
temp1=*s;
while(temp1->next!=NULL)
	temp1=temp1->next;
temp1->next=temp;
}
}


void sumofdigits(struct sll **s1,struct sll **s2)
{
int sum;
if((*s1)->next==NULL){
	sum=(*s1)->data+(*s2)->data;
	(*s1)->data=sum;
	return;
	}
else
{
	sumofdigits(&((*s1)->next),&((*s2)->next));
	sum=(*s1)->next->data;
	(*s1)->next->data=sum%10;
	sum=(*s1)->data+(*s2)->data+(sum/10);
	(*s1)->data=sum;
	return;
}}

void print(struct sll **s)
{
struct sll *temp=*s;
while(temp!=NULL)
{
printf("%d",temp->data);
temp=temp->next;
}
printf("\n");
}
int main()
{
struct sll *s1,*s2;
s1=NULL;
s2=NULL;
int n,i,ele;
if(!scanf("%d",&n) ||n<1 || n>10000) {printf("invalid");return -1;}
char c,s[2];
scanf("%c",&c);
for(i=0;i<n;i++)
{
scanf("%c",&c);
if(c<'0' || c >'9') {printf("invalid");return -1;}
s[0]=c;
ele=atoi(s);
insert(&s1,ele);
}
scanf("%c",&c);
for(i=0;i<n;i++)
{
scanf("%c",&c);
if(c<'0' || c >'9') {printf("invalid");return -1;}
s[0]=c;
ele=atoi(s);
insert(&s2,ele);
}
sumofdigits(&s1,&s2);
print(&s1);
}
