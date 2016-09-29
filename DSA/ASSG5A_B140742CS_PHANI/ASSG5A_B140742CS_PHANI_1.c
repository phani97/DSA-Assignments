#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<limits.h>
int number;
int n;
struct node{
int data;
float weight;
struct node* next;
};

struct hash{
struct node* head;
}h[10000];


int check (int a[],int ele,int count)
{
int i;
for(i=0;i<count;i++)
	{if(a[i]==ele) return 1;}
return 0;
}

void insert_node(int ele,int pos)
{
struct node* temp=h[pos].head,*temp1;
temp1=(struct node*) malloc(sizeof(struct node));
temp1->data=ele;
temp1->next=NULL;
if(h[pos].head==NULL){ h[pos].head=temp1;return;}
while(temp->next!=NULL) temp=temp->next;
temp->next=temp1;
}

void add_weight(float weight,int pos,int pos1)
{
struct node*temp=h[pos].head;
int i;
for(i=1;i<pos1;i++)
	temp=temp->next;
temp->weight=weight;
}
int m=0;
struct priority_queue
{
    int data;
    float pri;
};
struct priority_queue pq[10000];

void insert(struct priority_queue h[],int y,float x)
{ 
int l,p,temp,i;
    if(m==0)
    {
        h[1].data=y;
        h[1].pri=x;
        l=1;
        m++;
    }
    else{
        m++;
        h[m].data=y;
        h[m].pri=x;
        l=m;

        p=l;
        while(p/2!=0 &&h[p].pri <h[p/2].pri)
        {
            temp=h[p/2].pri;
            h[p/2].pri=x;
            h[p].pri=temp;
            temp=h[p/2].data;
            h[p/2].data=y;
            h[p].data=temp;
            p=p/2;
        }
       }

}
int isempty(struct priority_queue pq[])
{   if(m==0)
{
    
    return 1;
}return 0;
    
    return;
}
int extract_min(struct priority_queue pq[])
{  int i;
    if(m==0)
{
    return;
}
   struct priority_queue temp;
   temp=pq[1];
    pq[1]=pq[m];
    m=m-1;
    minheap(pq,1);
   
    return temp.data;
}
void decrease_priority(struct priority_queue h[],int a ,int b)
{
    int i,j=0,l,p,temp;
    if(m==0)
    {
        insert(pq,a,b);
        return;
    }
    for(i=1;i<m+1;i++)
    {  
        if(h[i].data==a)
        {   if(b>h[i].pri)
        {  
            return;
        }
            h[i].pri=b;
            goto c;
        }
j++;
    }
    c:p=i;
if(j==m)
{ insert(pq,a,b);
return;}
        while(p/2!=0 && h[p].pri <h[p/2].pri)
        {
            temp=h[p/2].pri;
            h[p/2].pri=h[p].pri;
            h[p].pri=temp;
            temp=h[p/2].data;
            h[p/2].data=h[p].data;
            h[p].data=temp;
            p=p/2;
        }

}


int minheap(struct priority_queue a[],int i)
{
    int c,j,k;struct priority_queue l;
    c=i;
    if(left(c)<=m)
    {
        if(a[left(c)].pri < a[i].pri)
            i=left(c);
    }
        if(right(c)<= m)
        {
            if(a[right(c)].pri < a[i].pri)
            {
                i=right(c);
            }


        }
        if(i!=c)
        { l=a[c];
        a[c]=a[i];
        a[i]=l;
        minheap(a,i);

        }

}
int left(int a)
{
    return 2*a;
}
int right(int a)
{
    return (2*a)+1;
}



void apsp(int start)
{
int a[n],ele,ele1,count=0,i;
float b[n];
for(i=0;i<n;i++)
	b[i]=INT_MAX;
struct priority_queue q[1000];
struct node*temp;
insert(q,start,0);
b[start]=0;
while(!isempty(q))
{
ele=extract_min(q);
if(!check(a,ele,count)){
a[count++]=ele;
temp=h[ele].head;
	while(temp!=NULL)
	{
		ele1=temp->data;
		
		if(b[ele1]>b[ele]+temp->weight)
			b[ele1]=b[ele]+temp->weight;
		insert(q,ele1,b[ele1]);
		temp=temp->next;
	}
}
}
for(i=0;i<n;i++) 
{
if(b[i]==INT_MAX) printf("INF ");
else printf("%g ",b[i]);
}
}

void sssp(int start,int end)
{
int a[n],ele,ele1,count=0,i;
float b[n];
for(i=0;i<n;i++)
	b[i]=INT_MAX;
struct priority_queue q[10000];
struct node*temp;
insert(q,start,0);
b[start]=0;
while(!isempty(q))
{
ele=extract_min(q);
if(!check(a,ele,count)){
a[count++]=ele;
temp=h[ele].head;
	while(temp!=NULL)
	{
		ele1=temp->data;
		
		if(b[ele1]>b[ele]+temp->weight)
			b[ele1]=b[ele]+temp->weight;
		insert(q,ele1,b[ele1]);
		temp=temp->next;
	}
}
}

if(b[end]==INT_MAX) printf("UNREACHABLE");
else printf("%g",b[end]);

}







main()
{
scanf("%d",&n);
if(n<0 || n>1000) {printf("INVALID INPUT");return;}
int i,ele,start,end,j,k;
float weight;
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
insert_node(ele,i);
start=ele;
//printf("%d %d\n",ele,i);
while(c!='\n')
	{
		scanf("%d",&ele);
		if(ele<=start || ele>=n){printf("INVALID INPUT");return;}
		insert_node(ele,i);
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
weight=atof(s);
if(weight<0 || weight>1000){printf("INVALID INPUT");return;}
add_weight(weight,i,1);
start=ele;
k=1;
//printf("%d %d\n",ele,i);
while(c!='\n')
	{
		k++;
		scanf("%f",&weight);
		if(weight<0 || weight>1000){printf("INVALID INPUT");return;}
		//if(ele<=start || ele>=n){printf("INVALID INPUT");return;}
		add_weight(weight,i,k);
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

