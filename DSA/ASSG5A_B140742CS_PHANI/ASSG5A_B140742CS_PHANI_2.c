#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<limits.h>

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

void graph(float a[][n])
{
int i,j;
struct node* temp;
//float a[n][n];
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		{a[i][j]=INT_MAX;
		if(i==j) a[i][j]=0;}

for(i=0;i<n;i++)
{
	temp=h[i].head;
	while(temp!=NULL)
	{
		a[i][temp->data]=temp->weight;
		temp=temp->next;
	}
}
}

void floyd()
{
float a[n][n];
graph(a);
int i,j,k;
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	if(a[i][j]!=a[j][i]) {printf("INVALID INPUT");return;}
for(k=0;k<n;k++)
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]>a[i][k]+a[k][j])
				a[i][j]=a[i][k]+a[k][j];

for(i=0;i<n;i++){
	for(j=0;j<n;j++)
	{
		if(a[i][j]==INT_MAX)
			printf("INF ");
		else printf("%g ",a[i][j]);
		
	}
	printf("\n");}
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
if(weight<-1000 || weight>1000){printf("INVALID INPUT");return;}
add_weight(weight,i,1);
start=ele;
k=1;
//printf("%d %d\n",ele,i);
while(c!='\n')
	{
		k++;
		scanf("%f",&weight);
		if(weight<-1000 || weight>1000){printf("INVALID INPUT");return;}
		//if(ele<=start || ele>=n){printf("INVALID INPUT");return;}
		add_weight(weight,i,k);
		start=ele;
		scanf("%c",&c);
	}
}}
floyd();
}
