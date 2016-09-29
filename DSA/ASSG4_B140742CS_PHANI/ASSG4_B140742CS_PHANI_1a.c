#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node* next;
};

struct hash{
struct node *head;
};
int n;
int hash_f(int ele)
{
if(ele>=0)
return ele%n;
else return (ele%n+n)%n;
}

void insert(struct hash *s,int data)
{
struct node *temp;
temp=(struct node*) malloc(sizeof(struct node));
temp->data=data;
temp->next=s->head;
s->head=temp;
}

void search(struct hash s,int data)
{

while(s.head!=NULL) {
if(s.head->data==data) {
printf("%d FOUND\n",hash_f(data));return;}
s.head=s.head->next;}
if(s.head==NULL) printf("%d NOT FOUND\n",hash_f(data));
}

main()
{
int i;
char c;
scanf("%d",&n);
if(n<0) {printf("INVALID INPUT");return;}
struct hash h[n];
for(i=0;i<n;i++) 
	h[i].head=NULL;
scanf("%c",&c);
do{
scanf("%c",&c);
switch(c)
{
case 'i':
{
	scanf("%d",&i);
	insert(&h[hash_f(i)],i);
	printf("%d\n",hash_f(i));
	break;
}
case 'f':
{
	scanf("%d",&i);
	search(h[hash_f(i)],i);
	break;
}
case 's':
{return;
break;}
default:
{
printf("enter correct option\n");
break;
}
}
scanf("%c",&c);
}while(c!='s');
}
