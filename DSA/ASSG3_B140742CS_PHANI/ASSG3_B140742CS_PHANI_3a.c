#include<stdio.h>
#include<stdlib.h>

struct queue{
int *a,head,size,tail;
};
int initialise(struct queue *q);
int isempty(struct queue *q);
int isfull(struct queue *q);
void enqueue(struct queue *q,int element);
int dequeue(struct queue *q);
void print(struct queue *q);

int initialise(struct queue *q)
{
if(!scanf("%d",&q->size) || q->size<1 || q->size>99) return -1;
q->a=(int*)malloc((q->size)*sizeof(int));
q->head=0;
q->tail=0;
return 1;
}

int isempty(struct queue *q)
{
if(q->head==q->tail) 
	return 1;
else return 0;
}

int isfull(struct queue *q)
{
if(q->tail==q->size-1)
{
	if(q->head==0)
		return 1;
	else return 0;
}
else
{
	if(q->tail+1==q->head)
		return 1;
	else return 0;
}
}

void enqueue(struct queue *q,int element)
{
if(isfull(q)) {
printf("OVERFLOW\n");
return ;
}
q->a[q->tail]=element;
if(q->tail==q->size-1)
	q->tail=0;
else q->tail++;
}

int dequeue(struct queue *q){
if(isempty(q)) return -1;
int element=q->a[q->head];
if(q->head==q->size-1)
	q->head=0;
else q->head++;
return element;
}

void print(struct queue *q)
{
if(isempty(q)) {printf("EMPTY"); return ;}
int index=q->head;
while(index!=q->tail)
{
printf("%d ",q->a[index]);
if(index==q->size-1)
	index=0;
else index++;
}
}

int main()
{
struct queue q;
if(initialise(&q)==-1) {printf("invalid array size");return;}
if(q.size==1) {printf("queue can't store any values");return;}
int x,i;
char choice;
scanf("%c",&choice);
do{
scanf("%c",&choice);
switch(choice)
{
case 'e':
	{
	if(!scanf("%d",&x) || x<0 || x>2147483648) {printf("invalid input");return;}
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
printf("enter correct option");
break;

}
}
scanf("%c",&choice);}while(choice!='s');
return 1;}
