#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n;
struct node{
int data;
int weight;
struct node* next;
};

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

void add_weight(int weight,int pos,int pos1)
{
struct node*temp=h[pos].head;
int i;
for(i=1;i<pos1;i++)
	temp=temp->next;
temp->weight=weight;
}

int check (int a[],int ele,int count)
{
int i;
for(i=0;i<count;i++)
	{if(a[i]==ele) return 1;}
return 0;
}




struct p_queuenode{
int data,priority;
};

struct p_queue{
struct p_queuenode a[10000];
int heapsize;
};
void delete(struct p_queue *pq,int index);
void initialise(struct p_queue *pq);
int parent(int index);
int left(int index);
int right(int index);
int insert_pqueue(struct p_queue *pq,int data,int priority);
int extract_min(struct p_queue *pq);
void get_min(struct p_queue *pq);
void decrease_priority(struct p_queue *pq,int data,int priority);



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

int insert_pqueue(struct p_queue *pq,int data,int priority)
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
struct p_queuenode k;
while(index!=1 && pq->a[index].priority<pq->a[parent(index)].priority)
{
k=pq->a[index];
pq->a[index]=pq->a[parent(index)];
pq->a[parent(index)]=k;
index=parent(index);
}
return 1;
}

int extract_min(struct p_queue *pq)
{
if(isempty(pq))
{
printf("EMPTY\n");
return ;
}
int data=pq->a[1].data;
//printf("%d (%d)\n",pq->a[1].data,pq->a[1].priority);
delete(pq,1);
return data;
}

void delete(struct p_queue *pq,int index)
{
int l,r;
struct p_queuenode temp;
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

void decrease_priority(struct p_queue *pq,int data,int priority)
{

int index=1;
int i;

while(index<=pq->heapsize && pq->a[index].data!=data)
	index++;
if(index>pq->heapsize)
{
insert_pqueue(pq,data,priority);
}
else{
delete(pq,index);
insert_pqueue(pq,data,priority);}

}
void apsp(int start)
{
int a[n],b[n],ele,ele1,count=0,i;
for(i=0;i<n;i++)
	b[i]=INT_MAX;
struct p_queue q;
struct node*temp;
decrease_priority(&q,start,0);
b[start]=0;
while(!isempty(&q))
{
ele=extract_min(&q);
if(!check(a,ele,count)){
a[count++]=ele;
temp=h[ele].head;
	while(temp!=NULL)
	{
		ele1=temp->data;
		
		if(b[ele1]>b[ele]+temp->weight)
			b[ele1]=b[ele]+temp->weight;
		decrease_priority(&q,ele1,b[ele1]);
		temp=temp->next;
	}
}
}
for(i=0;i<n;i++) 
{
if(b[i]==INT_MAX) printf("INF ");
else printf("%d ",b[i]);
}
}

void sssp(int start,int end)
{
int a[n],b[n],ele,ele1,count=0,i;
for(i=0;i<n;i++)
	b[i]=INT_MAX;
struct p_queue q;
struct node*temp;
decrease_priority(&q,start,0);
b[start]=0;
while(!isempty(&q))
{
ele=extract_min(&q);
if(!check(a,ele,count)){
a[count++]=ele;
temp=h[ele].head;
	while(temp!=NULL)
	{
		ele1=temp->data;
		
		if(b[ele1]>b[ele]+temp->weight)
			b[ele1]=b[ele]+temp->weight;
		decrease_priority(&q,ele1,b[ele1]);
		temp=temp->next;
	}
}
}

if(b[end]==INT_MAX) printf("UNREACHABLE");
else printf("%d",b[end]);

}


main()
{
scanf("%d",&n);
if(n<0 || n>1000) {printf("INVALID INPUT");return;}
int i,ele,start,end,j,weight,k;
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

//scanf("%c",&c);
for(i=0;i<n;i++)
{
scanf("%c",&c);
if(c=='\n') {}
else{
for(j=0;c!=' ' && c!='\n';j++)
	{s[j]=c;scanf("%c",&c);}
s[j]='\0';
ele=atoi(s);
if(ele<0 || ele>1000){printf("INVALID INPUT");return;}
add_weight(ele,i,1);
start=ele;
k=1;
//printf("%d %d\n",ele,i);
while(c!='\n')
	{
		k++;
		scanf("%d",&ele);
		//if(ele<=start || ele>=n){printf("INVALID INPUT");return;}
		add_weight(ele,i,k);
		start=ele;
		scanf("%c",&c);
	}
}}
scanf("%s",s);
while(strcmp(s,"stop")!=0)
{
if(strcmp(s,"apsp")==0)
{
scanf("%d",&start);
if(start<0 || start>=n){printf("INVALID INPUT");return;}
apsp(start);
printf("\n");
}
else if(strcmp(s,"sssp")==0)
{
scanf("%d %d",&start,&end);
if(start<0 || start>=n || end<0 || end>=n){printf("INVALID INPUT");return;}
sssp(start,end);
printf("\n");
}
else{printf("INVALID INPUT");return;}
scanf("%s",s);
}


}
