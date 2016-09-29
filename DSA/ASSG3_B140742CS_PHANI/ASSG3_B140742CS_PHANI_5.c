#include<stdio.h>
#include<stdlib.h>

struct node{
int data,priority;
};

struct p_queue{
struct node a[10000];
int heapsize;
};
void delete(struct p_queue *pq,int index);
void initialise(struct p_queue *pq);
int parent(int index);
int left(int index);
int right(int index);
int insert(struct p_queue *pq,int data,int priority);
void extract_min(struct p_queue *pq);
void get_min(struct p_queue *pq);
int decrease_priority(struct p_queue *pq,int data,int priority);

void initialise(struct p_queue *pq)
{
pq->heapsize=0;
}

int parent(int index)
{
if(index%2==0) return index/2;
else return (index-1)/2;
}
int left(int index)
{
return 2*index;
}

int right(int index)
{
return 2*index+1;
}
int isempty(struct p_queue *pq)
{
if(pq->heapsize==0)
	return 1;
return 0;
}

int insert(struct p_queue *pq,int data,int priority)
{
int i;
for(i=1;i<=pq->heapsize;i++)
{
if(pq->a[i].data==data || pq->a[i].priority==priority)
	return -1;
}
pq->heapsize++;
pq->a[pq->heapsize].data=data;
pq->a[pq->heapsize].priority=priority;
int index=pq->heapsize;
struct node k;
while(index!=1 && pq->a[index].priority<pq->a[parent(index)].priority)
{
k=pq->a[index];
pq->a[index]=pq->a[parent(index)];
pq->a[parent(index)]=k;
index=parent(index);
}
return 1;
}

void extract_min(struct p_queue *pq)
{
if(isempty(pq))
{
printf("EMPTY\n");
return ;
}
struct node temp;
printf("%d (%d)\n",pq->a[1].data,pq->a[1].priority);
delete(pq,1);
}

void delete(struct p_queue *pq,int index)
{
int l,r;
struct node temp;
pq->a[index]=pq->a[pq->heapsize];
pq->heapsize--;
while(left(index)<=pq->heapsize)
{
if(pq->a[index].priority>pq->a[left(index)].priority)
{
temp=pq->a[index];
pq->a[index]=pq->a[left(index)];
pq->a[left(index)]=temp;
l=1;
}
else l=0;
if(right(index)<=pq->heapsize)
{
if(pq->a[index].priority>pq->a[right(index)].priority)
{
temp=pq->a[index];
pq->a[index]=pq->a[right(index)];
pq->a[right(index)]=temp;
r=1;
}
else r=0;
}
if(l==1) index=left(index);
else if (r==1) index=right(index);
else return;
}


}
void get_min(struct p_queue *pq)
{
if(isempty(pq))
{
printf("EMPTY\n");
return ;
}
printf("%d (%d)\n",pq->a[1].data,pq->a[1].priority);
}

int decrease_priority(struct p_queue *pq,int data,int priority)
{
if(isempty(pq)){printf("EMPTY\n");return;}
int index=1;
int i;
for(i=1;i<=pq->heapsize;i++)
{
if( pq->a[i].priority==priority)
	return -1;
}
while(index<=pq->heapsize && pq->a[index].data!=data)
	index++;
if(index>pq->heapsize){printf("given data not available\n"); return 1;}

if(pq->a[index].priority<priority) { printf("given priority is invalid"); return 1;}
delete(pq,index);
insert(pq,data,priority);
return 1;
}

int main()
{
struct p_queue pq;
initialise(&pq);
char choice;
int data,priority;
do{
scanf("%c",&choice);
switch(choice)
{
case 'a':
{
	if(scanf("%d%d",&data,&priority)!=2 || data<0|| priority<1|| data>1073741824|| priority>1073741824){
	printf("invalid input"); return 0;}
	if(insert(&pq,data,priority)==-1) printf("data or priority already exist");
	break;
}
case 'e':
{
	extract_min(&pq);
	break;
}
case 'g':
{
	get_min(&pq);
	break;
}
case 'd':
{
	if(scanf("%d%d",&data,&priority)!=2 || data<0|| priority<1|| data>1073741824|| priority>1073741824){
	printf("invalid input"); return 0;}
	if(decrease_priority(&pq,data,priority)==-1) printf("priority already exists");
	break;
}
case 's':
	return 0;
default:
{
	printf("choose right option\n");
	break;
}}
scanf("%c",&choice);
}while(choice!='s');
}
