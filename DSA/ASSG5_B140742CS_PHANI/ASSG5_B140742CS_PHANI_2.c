#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
int data;
struct node* next;
};
int n;
struct hash{
struct node* head;
}h[10000];

void insert(int ele,int pos)
{
struct node* temp=h[pos].head,*temp1;
temp1=(struct node*) malloc(sizeof(struct node));
temp1->data=ele;
temp1->next=NULL;
if(h[pos].head==NULL){ h[pos].head=temp1;return;}
while(temp->next!=NULL) temp=temp->next;
temp->next=temp1;
}

int check (int a[],int ele,int count)
{
int i;
for(i=0;i<count;i++)
	{if(a[i]==ele) return 1;}
return 0;
}

struct stacknode{
int data;
struct stacknode* next;
};

struct stack{
struct stacknode* top;
};

struct queuenode{
int data;
struct queuenode* next;
};

struct queue{
struct queuenode *head,*tail;
};

void push(struct stack* s,int element)
{
struct stacknode* temp;
temp=(struct stacknode*)malloc(sizeof(struct stacknode));
temp->data=element;
temp->next=s->top;
s->top=temp;
}

int pop(struct stack *s)
{
struct stacknode *temp;
if(s->top==NULL) return -1;
temp=s->top;
int data=temp->data;
s->top=temp->next;
free(temp);
return data;
}

int isempty_stack(struct stack *s)
{
if(s->top==NULL)
	return 1;
else return 0;
}

int isempty_queue(struct queue *q)
{
if(q->head==NULL)
	return 1;
else return 0;
}

void enqueue(struct queue* q,int element)
{
struct queuenode *temp,*temp1;
temp= (struct queuenode*)malloc(1*sizeof(struct queuenode));
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
struct queuenode *temp;
int data;
if(isempty_queue(q)) return -1;
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

void bfs(int start,int end)
{
int a[n],ele,count=0;
struct node *temp;
struct queue q;
q.head=NULL;
enqueue(&q,start);
while(!isempty_queue(&q))
{
ele=dequeue(&q);
if(!check(a,ele,count)){
a[count]=ele;
count++;
printf("%d ",ele);
if(ele==end) return;
temp=h[ele].head;

	while(temp!=NULL)
		{
			enqueue(&q,temp->data);
			temp=temp->next;
		}

}
}

}



void dfs(int start,int end)
{
struct stack s;
struct node* temp;
s.top=NULL;
int a[n],b[n],ele,count=0,i,j,count1=0;
push(&s,start);
while(!isempty_stack(&s))
{

count1=0;
ele=pop(&s);
if(!check(a,ele,count)){
printf("%d ",ele);
a[count]=ele;
count++;
if(ele==end) return;
temp=h[ele].head;
	while(temp!=NULL)
		{
			b[count1++]=temp->data;
			temp=temp->next;
		}
	for(i=count1-1;i>=0;i--)
		push(&s,b[i]);
}
}
}

main()
{
scanf("%d",&n);
if(n<0 || n>10000) {printf("INVALID INPUT");return;}
int i,ele,start,end,j;
char c,s[n];
for(i=0;i<n;i++)
	h[i].head=NULL;
scanf("%c",&c);
for(i=0;i<n;i++)
{
scanf("%c",&c);
if(c=='\n') {}
else{
for(j=0;c!=' ' && c!='\n';j++)
	{s[j]=c;scanf("%c",&c);}
s[j]='\0';
ele=atoi(s);
if(ele<0 || ele>=n){printf("INVALID INPUT");return;}
insert(ele,i);
start=ele;
//printf("%d %d\n",ele,i);
while(c!='\n')
	{
		scanf("%d",&ele);
		if(ele<=start || ele>=n){printf("INVALID INPUT");return;}
		insert(ele,i);
		start=ele;
		scanf("%c",&c);
	}
}}
scanf("%s",s);
while(strcmp(s,"stp")!=0)
{
if(strcmp(s,"bfs")==0)
{
scanf("%d %d",&start,&end);
if(start<0 || start>=n || end<0 || end>=n){printf("INVALID INPUT");return;}
bfs(start,end);
printf("\n");
}
else if(strcmp(s,"dfs")==0)
{
scanf("%d %d",&start,&end);
if(start<0 || start>=n || end<0 || end>=n){printf("INVALID INPUT");return;}
dfs(start,end);
printf("\n");
}
else{printf("INVALID INPUT");return;}
scanf("%s",s);
}


}

