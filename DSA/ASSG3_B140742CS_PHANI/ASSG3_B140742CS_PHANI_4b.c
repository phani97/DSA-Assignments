#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

struct stack{
struct node *top;
};
void initialise (struct stack *s);
int isempty(struct stack *s);
void push(struct stack* s,int element);
int pop(struct stack *s);
void print(struct stack *s);

void initialise (struct stack *s)
{
s->top=NULL;
}
int isempty(struct stack *s)
{
if(s->top==NULL)
	return 1;
else return 0;
}

void push(struct stack* s,int element)
{
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=element;
temp->next=s->top;
s->top=temp;
}

int pop(struct stack *s)
{
struct node *temp;
if(s->top==NULL) return -1;
temp=s->top;
int data=temp->data;
s->top=temp->next;
free(temp);
return data;
}

void print(struct stack *s)
{
struct node *temp;
temp=s->top;
if(s->top==NULL){ printf("EMPTY\n");return;}
while(temp!=NULL)
{
	printf("%d ",temp->data);
	temp=temp->next;
}
printf("\n");
}

int main()
{
struct stack s;
initialise(&s);
int x,i;
char choice;
do{
scanf("%c",&choice);
switch(choice)
{
case 'a':
{
	if(!scanf("%d",&x) || x<0 || x>2147483648) {printf("invalid input");return;}
	push(&s,x);
	break;
}
case 'r':
{
	i=pop(&s);
	
	if(i==-1) printf("EMPTY\n");
	else printf("%d\n",i);
	break;
}
case 'p':
	{print(&s);
	break;}
case 's':
	return 0;
default:
{
printf("choose right option");
break;
}
}scanf("%c",&choice);
}while(choice!='s');
}
