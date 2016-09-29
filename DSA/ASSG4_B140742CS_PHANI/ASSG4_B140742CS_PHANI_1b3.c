#include<stdio.h>
#include<stdlib.h>

struct hash{
int data;
int *head;
};
int n;
int hash_f(int ele,int i)
{
return (h1(ele)+i*h2(ele))%n;
}
int h1(int ele){
if(ele<0)
return (ele%n+n)%n;
else return ele%n;
}

int h2(int ele)
{
double t;
t=ele*0.6180339887;
int t1=(int) t;
t=t-t1;
if(t<0) t+=1;
t=t*n;
t1=(int) t;
if(t1<0) return t1+n;
return t1;
}

void insert(struct hash s[],int data)
{
int i,key;
for(i=0;i<n;i++)
{
key=hash_f(data,i);
printf("%d ",key);
if(s[key].head==NULL) break; 
}
if(i==n) {printf("CANNOT INSERT\n");return;}
s[key].data=data;
s[key].head=&data;
printf("\n");
}

void search(struct hash s[],int data)
{
int i,key;
for(i=0;i<n;i++)
{
key=hash_f(data,i);
if( s[key].head==NULL)
{printf("%d NOT FOUND\n",key);return;}
else if(s[key].data==data) 
{printf("%d FOUND\n",key);return;}
else printf("%d ",key);
}
printf("NOT FOUND\n");
}

main()
{
scanf("%d",&n);
if(n<0) {printf("INVALID INPUT");return;}
struct hash h[n];
char choice;
int data;
for(data=0;data<n;data++)
	h[data].head=NULL;
for(data=0;data<n;data++)
	if(h[data].head!=NULL) printf("%d",data);

do{
scanf("%c",&choice);
scanf("%c",&choice);
switch(choice)
{
case 'i':
{
	scanf("%d",&data);
	insert(h,data);
	break;
}
case 'f':
{
	scanf("%d",&data);
	search(h,data);
	break;
}
}
}while(choice!='s');
}
