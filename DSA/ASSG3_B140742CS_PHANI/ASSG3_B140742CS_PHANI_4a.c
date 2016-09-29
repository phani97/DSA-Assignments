#include<stdio.h>
#include<stdlib.h>

struct stack{
int *a,top,size;
};
int initialise(struct stack *s);
int isempty(struct stack *s);
int isfull(struct stack *s);
void push(struct stack *s,int element);
int pop(struct stack *s);
void print(struct stack* s);

int initialise(struct stack *s)
{
if(!scanf("%d",&s->size) || s->size<=0 || s->size>=1000) return -1;
s->top=-1;
s->a=(int*)malloc((s->size)*sizeof(int));
return 1;
}

int isempty(struct stack *s)
{
if(s->top==-1) return 1;
else return 0;
}

int isfull(struct stack *s)
{
if(s->top==s->size-1) return 1;
else return 0;
}

void push(struct stack *s,int element)
{
if(isfull(s)) {printf("OVERFLOW\n"); return ;}
s->top++;
s->a[s->top]=element;
}

int pop(struct stack *s)
{
if(isempty(s))  return -1;
int element=s->a[s->top];
s->top--;
return element;
}

void print(struct stack* s)
{
if(isempty(s)) {printf("EMPTY\n"); return;}
int size=s->top;
while(size!=-1)
{
printf("%d ",s->a[size]);
size--;
}
printf("\n");
}


int main()
{
struct stack s;
if(initialise(&s)==-1) {printf("invalid array size"); return 0;}
int x,i;
char choice;
scanf("%c",&choice);
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
printf("choose right option\n");
break;
}
}scanf("%c",&choice);
}while(choice!='s');
}
