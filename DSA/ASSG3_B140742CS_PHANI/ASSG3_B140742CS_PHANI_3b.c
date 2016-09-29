#include<stdio.h>
#include<stdlib.h>


struct node{
int data;
struct node *next;
};

struct queue{
struct node *head,*tail;
};
void initialise(struct queue *q);
int isempty(struct queue *q);
void enqueue(struct queue* q,int element);
int dequeue(struct queue* q);
void print(struct queue* q);

void initialise(struct queue *q)
{
q->head=NULL;
q->tail=NULL;
}

int isempty(struct queue *q)
{
if(q->head==NULL)
	return 1;
else return 0;
}

void enqueue(struct queue* q,int element)
{
struct node *temp,*temp1;
temp= (struct node*)malloc(1*sizeof(struct node));
if(q->head==NULL)
{
q->head=temp;
q->tail=temp;
}
else{
temp1=q->tail;
temp1->next=temp;
q->tail=temp;
}
temp->data=element;
temp->next=NULL;
}

int dequeue(struct queue* q)
{
struct node *temp;
int data;
if(isempty(q)) return -1;
if(q->head==q->tail)
{
temp=q->head;
data=temp->data;
q->head=NULL;
q->tail=NULL;
free(temp);
return data;
}
else{
temp=q->head;
data=temp->data;
q->head=temp->next;
free(temp);
return data;
}
}

void print(struct queue* q)
{
struct node *temp;
if(q->head==NULL)
{
printf("EMPTY");
return;}
temp=q->head;
while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

int main()
{
struct queue q;
initialise(&q);
int x,i;
char choice;

do{
scanf("%c",&choice);
switch(choice)
{
case 'e':
	{
	if(!scanf("%d",&x) || x<0|| x>2147483648) {printf("invalid input");return;}
	enqueue(&q,x);
	break;
	}
case 'd':
	{i=dequeue(&q);
	if(i==-1) printf("EMPTY\n");
	else printf("%d\n",i);
	break;
	}
case 'p':
	{print(&q);
	printf("\n");
	break;
	}
case 's':
{ return 0;}
default:
{
printf("enter correct option\n");
break;

}
}
scanf("%c",&choice);}while(choice!='s');
return 1;}
